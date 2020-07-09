#!/bin/sh

# This file is free software; the Free Software Foundation    
# gives unlimited permission to copy, distribute and modify it.

cd `dirname $0`/..
export CFLAGS=
export CXXFLAGS=
DUNEMAKEFLAGS=-j8
export DUNEMAKEFLAGS
make realclean
./configure --with-gprof --without-cgal --without-omp --without-devil 
make

