#include <math.h>

float fmaf(float x, float y, float z)
{
	__asm__ ("ffmaw %0 = %1, %2\n"
		 ";;\n"
		 : "+r"(z) : "r"(x), "r"(y));
	return z;
}
