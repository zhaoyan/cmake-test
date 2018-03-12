#I want to test a function in the sum.cpp file,
#So I need to add it to he project.
file(GLOB SRCS *.cpp ../../sum.cpp)

ADD_EXECUTABLE(testlib ${SRCS})

TARGET_LINK_LIBRARIES(testlib
    #libfoo
    libgtest
    libgmock
)

add_test(NAME testsum
         COMMAND testsum)
