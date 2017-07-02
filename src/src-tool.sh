#!/bin/sh

ctags -R .
if [ ! -f ./cscope.files ]; then
		    echo "cscope.files not found!"
find . -name '*.cpp' -or -name '*.cxx' > cscope.files
fi 
cscope -Rbq

cd ..
if [ ! -f ./Doxyfile ]; then
		    echo "Doxyfile not found!"
	doxygen -g
	echo "GENERATE_LATEX = NO" >> Doxyfile
	echo "INPUT = ./src" >> Doxyfile
	                                                     
fi

cd ./src
if [ ! -f ./.ycm_extra_conf.py ]; then
		    echo "ycm not found!"
			~/.vim/bundle/YCM-Generator/config_gen.py .
fi
