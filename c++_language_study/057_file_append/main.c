#include <stdio.h>

int main()
{
	FILE* fp;

RE_TRY:
	fopen_s(&fp, "data.txt", "a+");
	if (fp == NULL)
		goto RE_TRY;

	char c = 0;
	while ((c = getc(stdin)) != EOF && c != 'q')
	{
		putc(c, fp);
	}

	fclose(fp);

	return 0;
}