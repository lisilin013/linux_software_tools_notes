#!/bin/zsh

rm -rf build
rm -rf /tmp/hello-world-project
mkdir build
cd build
# cmake ..
# CMAKE_INSTALL_PREFIX 的默认定义是/usr/local
cmake -DCMAKE_INSTALL_PREFIX=/tmp/hello-world-project/usr ..
make
make install
