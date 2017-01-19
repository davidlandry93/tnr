# tnr
A small library to play with Teach and Repeat maps. Stands for Teach aNd Repeat.

## Installing jsoncpp as a cmake package

`tnr` has `jsoncpp` as a dependency. Here's how to install it on your system in 
a way that if works with `tnr`.

```
$ git clone git@github.com:open-source-parsers/jsoncpp.git
$ mkdir build && cd build
$ cmake .. -DBUILD_STATIC_LIBS=ON -DJSONCPP_WITH_TEST=OFF -DJSONCPP_WITH_CMAKE_PACKAGE=ON`
$ make -j 
$ sudo make install # Jsoncpp does not support build-tree packages
```
