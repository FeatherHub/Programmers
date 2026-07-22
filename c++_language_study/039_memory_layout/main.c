#include <stdio.h>

void* m[1000];

struct pack1
{
	int i;
	char c;
};

int main()
{
	*(m + 15) = (void*)5;
	*(m + 15 + 1) = (void*)'A';

	printf("%d \n", ((struct pack1*)(m + 15))->i);
	printf("%c \n", ((struct pack1*)(m + 15))->c);
	printf("%c \n", (*(m + 15 + 1)));

	return 0;
}