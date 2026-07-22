#pragma warning (disable:4996)
#include <string.h>
#include <stdio.h>

int readLine(char* buf)
{
	char c = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\n') break;

		*buf++ = c;
	}
	*buf = '\0';

	return 0;
}

int main()
{
	char string1[100], string2[100];
	int res;
	char useranswer[100];

	while (1)
	{
		printf("input string1: ");
		readLine(string1);
		printf("input string2: ");
		readLine(string2);

		res = strcmp(string1, string2);

		printf("what is the result?\n");
		readLine(useranswer);

		printf("%s / (%s, %s) => %d\n", useranswer, string1, string2, res);
	}

	return 0;
}