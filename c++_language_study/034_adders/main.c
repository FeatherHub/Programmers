#include <stdio.h>

typedef char signal;
typedef struct signal2 { signal s[2]; } signal2;


	
//	a	b	a+b		c
//	0	0	0		0
//	0	1	1		0
//	1	0	1		0		
//	1	1	0		1
signal2 half_adder(signal a, signal b)
{
	signal r = a != b;
	signal c = a && b;

	signal2 o = { r, c };

	return o;
}


//	a	b	c	a+b+c	c2
//	0	0	0	0		0
//	0	1	0	1		0
//	1	0	0	1		0
//	1	1	0	0		1
//	0	0	1	1		0
//	0	1	1	0		1
//	1	0	1	0		1
//	1	1	1	1		1
signal2 full_adder(signal a, signal b, signal c)
{
	signal r = a != b && !c || a == b && c;
	signal c2 = a && b || c && (a || b);

	signal2 o = { r, c2 };

	return o;
}

int main()
{
	return 0;
}