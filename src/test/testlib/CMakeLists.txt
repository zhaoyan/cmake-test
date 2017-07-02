file(GLOB SRCS *.cpp ../../sum.cpp)

ADD_EXECUTABLE(testlib ${SRCS})

TARGET_LINK_LIBRARIES(testlib
    #libfoo
    libgtest
    libgmock
)

add_test(NAME testlib
         COMMAND testlib)
