cmake_minimum_required(VERSION 2.8)

# Project's name
project(test)

# method 1, You can build directory outside, then cd, run cmake /path/to/source/
# In this way, SOURCE_DIR and BINARY_DIR is decided implicitly.
# Check two important directory, and learn message method
message("PROJECT_SOURCE_DIR is ${PROJECT_SOURCE_DIR}")
message("PROJECT_BINARY_DIR is ${PROJECT_BINARY_DIR}")

# method 2, You can set BINARY_DIR by hand.  
#set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
#set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})


#make will give you all the compiler flag value
set(CMAKE_VERBOSE_MAKEFILE true)


set(TEST_VERSION_MAJOR 1)
set(TEST_VERSION_MINOR 0)

include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists (log HAVE_LOG)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

configure_file (
		"${PROJECT_SOURCE_DIR}/testConfig.h.in"
		"${PROJECT_BINARY_DIR}/testConfig.h"
		)

# set include directory
set(PROJECT_INCLUDE_DIRECTORIES
		${PROJECT_SOURCE_DIR}/
		${PROJECT_BINARY_DIR}/
		# add more head file here
					)

include_directories(${PROJECT_INCLUDE_DIRECTORIES})

add_definitions("-Wall" "-g")
# method 1 to add some source file
#set(SRC_FILES ${PROJECT_SOURCE_DIR}/main.cpp
					  #${PROJECT_SOURCE_DIR}/bmi.cpp
									#… )
# method 2 to add some source file
aux_source_directory(${CMAKE_SOURCE_DIR} PRJ_SRC_FILES)

	
	#LINK_DIRECTORIES("${PROJECT_BINARY_DIR}/")	
if (USE_MYMATH)
		include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
		add_subdirectory (MathFunctions)
		set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif ()



add_executable(test ${PRJ_SRC_FILES}) 

target_link_libraries (test  ${EXTRA_LIBS})


# This produce install target in Makefile. 
install(TARGETS test DESTINATION bin)
