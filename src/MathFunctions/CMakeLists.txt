#this statment will produce a .so file
add_library(MathFunctions SHARED MathFunctions.cxx)

#will install lib and header file to it's destination.
install (TARGETS MathFunctions DESTINATION lib)
install (FILES MathFunctions.h DESTINATION include)
