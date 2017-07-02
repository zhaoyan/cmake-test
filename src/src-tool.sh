#!/bin/sh

ctags -R .
find . -name '*.cpp' > cscope.files
cscope -Rbq
doxygen -g
