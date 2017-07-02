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
		echo 	"RECURSIVE = YES" >>Doxyfile
		echo "EXTRACT_ALL = YES" >>Doxyfile
		echo "EXCLUDE_PATTERNS = */*.py" >>Doxyfile                                                     
fi

cd ./src
if [ ! -f ./.ycm_extra_conf.py ]; then
		    echo "ycm not found!"
			~/.vim/bundle/YCM-Generator/config_gen.py .
fi
