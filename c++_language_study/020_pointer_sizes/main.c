#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{	
	int n = 10;
	int* p = &n;

	char buf10[100] = "";
	char buf16[100] = "";
	_ui64toa((unsigned long long)p, buf10, 10);
	_ui64toa((unsigned long long)p, buf16, 16);

	printf("sizeof(int): %llu \n", sizeof(int));
	printf("sizeof(long): %llu \n", sizeof(long));
	printf("sizeof(long long): %llu \n", sizeof(unsigned long long));

	printf("sizeof(int*): %llu \n", sizeof(int*));
	printf("sizeof(long*): %llu \n", sizeof(long*));
	printf("sizeof(char*): %llu \n", sizeof(char*));

	printf("%llu \n", p);
	printf("(int)%llu \n", p);
	printf("%p \n", p);
	printf("%s \n", buf10);
	printf("%s \n", buf16);

	return 0;
}