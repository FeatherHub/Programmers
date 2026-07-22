#include "mymath.h"

int mypow(int base, int exp)
{
	int res = 1;

	while (exp-- > 0)
		res *= base;

	return res;
}
