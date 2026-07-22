#include <stdio.h>

int main(int n, char** args)
{
	printf("%d\n", n);

	for (int i = 0; i < n; i++)
	{
		printf("%d: %s\n", i, args[i]);
	}

	return 0;
}