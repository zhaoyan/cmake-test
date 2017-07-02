#include<stdio.h>
#include"sum.h"
#include"testConfig.h"
#include <vector>
#include <math.h>

#ifdef USE_MYMATH
#include"MathFunctions.h"
#endif
#define YYY 1
int g_i = 100;

int main(){
		int i = 2;
		int j = 3;	
int yan = 123;
int yan123 = 333;
int yin = 0;

		std::vector<int> vi;
	     	
		printf("major version is %d, and minor version %d\n", TEST_VERSION_MAJOR, TEST_VERSION_MINOR);
		double result = 0.0;
		// You can modify USE_MYMATH in CMakeList.txt
		#ifdef USE_MYMATH
				result = mysqrt(4.0);
		#else
				result = sqrt(4.0);
		#endif
		
		// This is test automaticlly.
		#ifdef HAVE_LOG
				printf("Log function can be used in this platform\n")
		#endif
		printf("mysqrt of 4 is %f\n", result);
		printf("%d + %d is %d\n", g_i ,j,Sum(i,j));
		printf("hello world\n");
		return 0;
}
