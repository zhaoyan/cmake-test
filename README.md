# cmake-test 1
This is a template dirctory for C/C++ Project. 

1) git clone git@github.com:zhaoyan/cmake-test.git

2) sudo apt-get update && apt-get upgrade
if you want to build swig for java, install these components firstly. 
sudo apt-get install default-jdk
sudo apt-get install swig

3) How to build?
In cmake-test directory, mkdir build
cd build
if you want to build with gtest and swig support, run
cmake -DBUILD_TEST=ON -DBUILD_SWIG=ON ../src

or without gtest and swig run
cmake ../src
then
make

4) How to generate html doc
cd src
./src-tool.sh
cd ..
doxygen Doxygen

5)Vim plugin
cd src
./src-tool.sh
vim main.cpp
:set tags=tags
:cs add cscope.out

6) If you cmake with TEST on, a test directory will be built 
./test/testlib/testlib

7) If you cmake with SWIG on, a swig directory will be built, there are python and java directory under it. It use swig produce wrapper code for you math function. In the end java and python client can call c++ function. 
cd test/testlib run 
./testlib

cd swig/python run
python3 test.py

cd swig/java run
java -Djava.library.path=. -jar Main.jar

java -Djava.library.path=. -jar Main.jar

8) If you want to see all the variable in the cmake file, you can run:
cmake -DDEBUG_CMAKE, it will print all the varaible out. 
