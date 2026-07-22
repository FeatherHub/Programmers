#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int sum(int num, int power, ...)
{
	va_list varg;
	va_start(varg, power);

	int sum = 0;
	for (int i = 0; i < num; i++)
	{
		sum *= power;
		sum += va_arg(varg, int);
	}

	va_end(varg);

	return sum;
}

char* cstr(int n, ...)
{
	va_list varg;
	va_start(varg, n);

	char* newStr = (char*)malloc(sizeof(char) * (n + 1));
	for (int i = 0; i < n; i++)
	{
		newStr[i] = va_arg(varg, char);
	}
	newStr[n] = 0;

	va_end(varg);

	return newStr;
}

int mainCall = 0;
int main()
{
	mainCall++;
	main();

	int s = sum(5, 10,
		1, 2, 3, 4,
		5);

	printf("%d \n", s);

	char* str = 0;
	printf( str = cstr(10, 'h', 'e', 'l', 'l', 'o', ',', 'w', 'o', 'r', 'l') );


	
	return 0;
}