#!/bin/sh
#set -x

export DUNEMAKEFLAGS=-j4

RPM_SRC_LIST="/usr/src/rpm /usr/src/RPM /usr/src/redhat /usr/src/packages"
RPM_SRC_LIST="$RPM_SRC_LIST $HOME/rpmbuild"

unset MKRPM_SRC
for i in $RPM_SRC_LIST ; do 
   if test -d $i/SOURCES ; then
      MKRPM_SRC=$i/SOURCES
   fi
done
if test "$MKRPM_SRC" = "" ; then
   echo -n non of typical rpm source directories 1>&2
   for i in $RPM_SRC_LIST ; do 
       echo -n " " $i/SOURCES 1>&2 
   done
   echo " " found 1>&2 
   echo extend variable RPM_SRC_LIST in $0 for your system 1>&2
   exit 1
fi

UNAME_A=`uname -a`
UNAME_PS2="Linux $USER 2.2.1 #1 Wed Nov 14 18:28:00 JST 2001 mips unknown"

VERSION1=wdune-`sh ../../batch/getversion.sh`
VERSION2=`echo $VERSION1 | awk '{gsub("wdune-","",$0);print $0}'`
VERSION3=`awk -v x="$VERSION2" 'BEGIN {split(x, a, "pl");print a[1]}'`
VERSION4=`awk -v x="$VERSION2" 'BEGIN {split(x, a, "pl");print a[2]}'`
. /etc/os-release
VERSION5=wdune-$VERSION3
VERSION6=$VERSION3
VERSION=$VERSION1

(
   cd ../../.. && 
   rm -rf /tmp/$VERSION5 && \
   cp -r $VERSION1 /tmp/$VERSION5 && \
   cd /tmp/$VERSION5 && 
   sh -x batch/fix_not_translated_rcfiles.sh &&
   make realclean && rm -rf desktop/macosx desktop/irix
) && \
(cd /tmp && tar -cpf - $VERSION5) | \
bzip2 -c > $MKRPM_SRC/$VERSION5.tar.bz2

if test "$UNAME_A"="$UNAME_PS2"; then
   # disable optimization on Playstation 2 cause of compiler bugs
   OPTIMIZE="--with-optimization"
   RPM_OPT_FLAGS=""
else 
   OPTIMIZE="--with-optimization"
   RPM_OPT_FLAGS='$RPM_OPT_FLAGS -O2 -g'
fi

if grep -q Mageia /etc/os-release 2>/dev/null; then 
    export CXXFLAGS="$CXXFLAGS -D__MAGEIA__=1"
fi

RPM_BUILD_ROOT='$RPM_BUILD_ROOT'

cat > /tmp/wdune.spec << EOT 
Summary: A graphical X3D/VRML97 editor, simple 3D modeler and animation tool
Name: wdune
%global extraver pl$VERSION4
Version: $VERSION6
Release: 1%{?dist}
#Copyright: GPL
License: GPLv3+,MPLv1.1
URL: http://wdune.ourproject.org/
Source: ftp://ftp.ourproject.org/pub/wdune/wdune-%{version}.tar.bz2
BuildRequires: gcc-c++
BuildRequires: gawk
BuildRequires: make
BuildRequires: bash
BuildRequires: motif-devel
BuildRequires: libxi-devel
BuildRequires: lib64xmu-devel
BuildRequires: libpng-devel
BuildRequires: libjpeg-devel
BuildRequires: libglu-devel
BuildRequires: expat-devel
BuildRequires: flex
BuildRequires: bison
BuildRequires: imlib2-devel
BuildRequires: libusb-devel
BuildRequires: CGAL-devel
BuildRequires: opensubdiv-devel
BuildRequires: gmp-devel
BuildRequires: libcurl-devel
BuildRequires: eigen3-devel
BuildRequires: ImageMagick
BuildRequires: aqsis
BuildRequires: freetype-devel 
BuildRequires: imlib2-devel
BuildRequires: fonts-ttf-bitstream-vera
BuildRequires: desktop-file-utils
BuildRequires: xdg-utils
BuildRequires: grep
BuildRequires: audacity
BuildRequires: lib64ffmpeg-devel
Requires: git
Requires: rcs
Requires: gedit
Requires: ImageMagick
Requires: aqsis
Requires: audacity
Requires: xorg-x11-75dpi-fonts
Requires: fonts-ttf-bitstream-vera
Recommends: lxterminal
Recommends: kolourpaint
Recommends: audacity

%description
The white_dune program is a graphical X3D/VRML97 editor, 
simple extrusion/NURBS/Superformula 3D modeler and animation tool.
With white_dune you can create/change 3D objects and animate them (in a easy 
way if you choose the -4kids GUI). The result can be shown in any WebGL enabled 
web browser or can be converted to the RIB format for movie creation. 
X3D and VRML97 are the ISO standard for displaying 3D data over the web. 
With Cobweb or X3DOM it can displayed in any WebGL enabled web browser. 

Under Linux, white_dune support some 3D input-devices like joysticks, game-pads
or all devices supported via the Xinput protocol.
White_dune support quad-buffer stereo visuals. Under Linux, this can be used
with Elsa Revelator, Crystal Eyes or Nvidia 3D Vision shutter-glasses and 
special drivers for expensive graphic-cards like Nvidia Quadro or ATI FireGL 4.
%prep
%setup -q

%build
%configure \
    --with-about="$VERSION1" \\
    --with-optimization \\
    --without-devil \\
    --with-helpurl="%{_docdir}/wdune-docs/docs/" \\
    --with-protobaseurl="%{_docdir}/wdune-docs/docs" \\
    --with-checkincommand="ci" \\
    --with-x11-editor="gedit" \\
    --with-imageeditor="kolourpaint" \\
    --with-imageeditor4kids="kolourpaint" \\
    --with-soundeditor=audacity
CXXFLAGS="$CXXFLAGS -Wno-ignored-attributes -Wnonnull-compare -Wmaybe-uninitialized"
%make_build 

%install
mkdir -p $RPM_BUILD_ROOT/%{_bindir}
mkdir -p $RPM_BUILD_ROOT/%{_mandir}/man1
mkdir -p $RPM_BUILD_ROOT/%{_datadir}/misc/white_dune
mkdir -p $RPM_BUILD_ROOT/%{_datadir}/applications
mkdir -p $RPM_BUILD_ROOT/%{_datadir}/pixmaps/

install -m 755 -p bin/dune $RPM_BUILD_ROOT/%{_bindir}/dune
install -m 755 -p bin/dune4kids $RPM_BUILD_ROOT/%{_bindir}/dune4kids
install -m 755 -p bin/illegal2vrml $RPM_BUILD_ROOT/%{_bindir}/illegal2vrml
install -m 755 -p tools/run_dune_and_aqsis.sh $RPM_BUILD_ROOT/usr/bin/run_dune_and_aqsis.sh
install -m 644 -p desktop/kde/dune.desktop $RPM_BUILD_ROOT/%{_datadir}/applications/dune.desktop
install -m 644 -p desktop/kde/dune.png $RPM_BUILD_ROOT/%{_datadir}/pixmaps/dune.png
install -m 644 -p desktop/kde/dune4kids.desktop $RPM_BUILD_ROOT/%{_datadir}/applications/dune4kids.desktop
install -m 644 -p desktop/kde/dune4kids.png $RPM_BUILD_ROOT/%{_datadir}/pixmaps/dune4kids.png
install -m 644 -p man/dune.1 $RPM_BUILD_ROOT/%{_mandir}/man1/dune.1
install -m 644 -p man/dune4kids.1 $RPM_BUILD_ROOT/%{_mandir}/man1/dune4kids.1
install -m 644 -p man/illegal2vrml.1 $RPM_BUILD_ROOT/%{_mandir}/man1/illegal2vrml.1

desktop-file-install                                    \\
--add-category="Graphics"                               \\
--delete-original                                       \\
--dir=$RPM_BUILD_ROOT/%{_datadir}/applications          \\
$RPM_BUILD_ROOT/%{_datadir}/applications/dune.desktop

%files
%license COPYING

%{_bindir}/dune
%{_bindir}/dune4kids
%{_bindir}/run_dune_and_aqsis.sh
%{_bindir}/illegal2vrml
%{_datadir}/applications/dune.desktop
%{_datadir}/pixmaps/dune.png
%{_datadir}/applications/dune4kids.desktop
%{_datadir}/pixmaps/dune4kids.png
%{_mandir}/man1/dune.1*
%{_mandir}/man1/dune4kids.1*
%{_mandir}/man1/illegal2vrml.1*

%package docs
Summary: Documentation for white_dune
%description docs
Documentation for white_dune
%files docs
%doc README.txt docs

%changelog

EOT

rpmdev-bumpspec --comment="Initial RPM release" --userstring="J. Scheurich <mufti11@web.de>" /tmp/wdune.spec

if rpm -ba /tmp/wdune.spec ; then
   echo > /dev/null
else
   rpmbuild -ba /tmp/wdune.spec
fi



