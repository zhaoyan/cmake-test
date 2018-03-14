cmake_minimum_required(VERSION 2.8)

# Project's name
project(foo)

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

#this is global setting cxx_flags,
#use this way to preserve the old value.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")

include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists (log HAVE_LOG)

#You can use USE_MYMATH in your .cpp file.
#you can put #cmakedefine USE_MYMATH in testConfig.h.in,
#CMake will produce config.h file in your build dirctory. 
#You also can use cmake -DUSE_MYMATH=OFF to turn off this option
option(USE_MYMATH "Use tutorial provided math implementation" ON)

#here you can specify your Config file
configure_file (
		"${PROJECT_SOURCE_DIR}/testConfig.h.in"
		"${PROJECT_BINARY_DIR}/testConfig.h"
		)

# set include directory
#Why you need add PROJECT_BINARY_DIR? because testConfig.h file is produced there.
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
#CMAKE_SOURCE_DIR is top-level CMakeLists.txt file location. 
aux_source_directory(${CMAKE_SOURCE_DIR} PRJ_SRC_FILES)

	
	#LINK_DIRECTORIES("${PROJECT_BINARY_DIR}/")	
if (USE_MYMATH)
		include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
		add_subdirectory (MathFunctions)
		set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif ()



add_executable(foo ${PRJ_SRC_FILES}) 
target_link_libraries (foo  ${EXTRA_LIBS})

#if you want to use third-paty library, use below cmake syntax.
#find_library(POCO_FOUNDATION PocoFoundation)
#target_link_libraries (foo  ${POCO_FOUNDATION})

# This produce install target in Makefile. 
install(TARGETS foo DESTINATION bin)



# build gtest function here. If you don't need it, just omit below statement.
option(BUILD_TEST "Build Python SWIG module" OFF)
if(BUILD_TEST)
add_subdirectory(test)

endif()

# build swig function here. If you don't need it, just omit below statement.
option(BUILD_SWIG "Build Python SWIG module" OFF)
if(BUILD_SWIG)
add_subdirectory(swig)
endif()


macro(print_all_variables)
    message(STATUS "print_all_variables------------------------------------------{")
    get_cmake_property(_variableNames VARIABLES)
    foreach (_variableName ${_variableNames})
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
    message(STATUS "print_all_variables------------------------------------------}")
endmacro()

option(DEBUG_CMAKE "Print out all CMAKE variables" OFF)
if(DEBUG_CMAKE)
print_all_variables()
endif()
