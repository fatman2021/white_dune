#!/bin/sh
# set -x

# creates a snap installable binary package 

mkdir -p meta
mkdir -p snap

VER=`sh ../../batch/getversion.sh`
VERSION=wdune-$VER

ARCH=`uname -m`
if test "X_$ARCH" = "X_x86_64"; then
    ARCH=amd64
fi

SNAPVAR='$SNAP'

cat << EOT > meta/snap.yaml
name: wdune
version: '$VER'
summary: simple X3D/VRML NURBS/Superformula 3D modeller and animation tool
description: X3D/VRML editor, simple NURBS/Superformula 3D modeller and animation tool
type: app
base: core18
apps:
    wdune:
        command: dune -fn 9x15bold -x3dv 
        plugs:
            - desktop
            - network

parts:
    wdune:
        source: ftp://ftp.ourproject.org/pub/wdune/$VERSION.tar.bz2
        plugin: autotools

# access OpenSubdiv in /usr/local
passthrough:
    layout:
        /usr/local:
            bind: $SNAPVAR/usr/local

build-packages:
    - make
    - bison
    - flex
    - gawk
    - m4
    - x11proto-core-dev
    - libexpat1-dev
    - libxmu-dev
    - xbase-clients
    - libxi-dev 
    - libgl-dev
    - libglu-dev
    - libmotif-dev
    - libpng-dev
    - libjpeg-dev
    - g++
    - gcc
    - libcurl4-openssl-dev
    - libfreetype6-dev
    - libcgal-dev
    - libavcodec-dev
    - libavutil-dev
    - libavformat-dev
    - libavresample-dev
    - libswscale-dev
    - libswresample-dev
    - ttf-bitstream-vera
    - xfonts-base 
    - gedit
    - xdg-utils
    - aqsis
    - imagemagick
    - kolourpaint
    - audacity
    - rcs
EOT

rm -rf /usr/include/white_dune

cp meta/snap.yaml snap/snapcraft.yaml

cp ../../desktop/kde/dune.desktop meta
cp ../../desktop/kde/dune4kids.desktop meta

#cp ../../desktop/kde/dune.desktop snap
#cp ../../desktop/kde/dune4kids.desktop snap

snapcraft
