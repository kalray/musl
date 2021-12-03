#include <math.h>

double fma(double x, double y, double z)
{
	__asm__ ("ffmad %0 = %1, %2\n"
		 ";;\n"
		 : "+r"(z) : "r"(x), "r"(y));
	return z;
}
