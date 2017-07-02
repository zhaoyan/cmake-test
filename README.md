# cmake-test
This is a template dirctory for C/C++ Project. 

1) How to build?
mkdir build
cd build
cmake ../src

2) How to generate html doc
cd src
./src-tool.sh
cd ..
doxygen

3)Vim plugin
cd src
./src-tool.sh
vim main.cpp
:set tags=tags
:cs add cscope.out

4)Test 
