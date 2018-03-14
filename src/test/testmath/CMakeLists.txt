#I want to test a function in the sum.cpp file,
#So I need to add it to he project.
file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testmath ${SRCS})

#LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/MathFunctio)

TARGET_LINK_LIBRARIES(testmath
	MathFunctions
    libgtest
    libgmock
)

add_test(NAME testmath
         COMMAND testmath)
