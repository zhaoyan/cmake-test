cmake_minimum_required(VERSION 2.8)

find_package(SWIG REQUIRED)
find_package(Java REQUIRED)
find_package(JNI REQUIRED)
include(UseJava)
include(UseSWIG)
include_directories(${JNI_INCLUDE_DIRS})

set( CMAKE_SWIG_OUTDIR ${CMAKE_CURRENT_BINARY_DIR} )

# Build the C++ code into a dynamic library: example.dll (on Windows) or libexample.so (on Linux)
swig_add_module(
    Mysqrtjava 
    java 
    ../MysqrtSwig.i 
    ../../MathFunctions/mysqrt.cxx
)

# For convenience we copy the dynamic library to the current build folder
add_custom_command(
    TARGET Mysqrtjava 
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Mysqrtjava> ${CMAKE_CURRENT_BINARY_DIR}
)

# Build the Java code into ExampleJNI.jar
add_jar(
	MysqrtjavaJNI
    SOURCES
	${CMAKE_SWIG_OUTDIR}/MysqrtSwig.java
	${CMAKE_SWIG_OUTDIR}/MysqrtSwigJNI.java
)
add_dependencies( MysqrtjavaJNI Mysqrtjava )

# Finally build the demonstration code into Main.jar

set(CMAKE_JAVA_JAR_ENTRY_POINT main) 
add_jar(
    Main 
    SOURCES main.java
    ENTRY_POINT main
)
add_dependencies( Main MysqrtjavaJNI )
