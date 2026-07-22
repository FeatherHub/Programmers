#include <stdio.h>

int plus(int a, int b) { return a + b; }
int minus(int a, int b) { return a - b; }
int mult(int a, int b) { return a * b; }
int div(int a, int b) { return a / b; }

/*==============
RETURN TYPE
(*NAME)
(PARAM TYPE)
===============*/

int main()
{
	enum { PLUS = 0, MINUS, MULT, DIV, NUM };
	int (*opf[4])(int, int);
	
	opf[PLUS] = plus;
	opf[MINUS] = minus;
	opf[MULT] = mult;
	opf[DIV] = div;

	for (int i = 0; i < NUM; i++)
	{
		int res = opf[i](100, 25);
		printf("%p\t%p\t%d\n", &opf[i], opf[i], res);
	}

	return 0;
}