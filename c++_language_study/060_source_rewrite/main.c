#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int readLine(FILE* fp, char* buf)
{
	const char* s = buf;
	char c;

	while ((c = getc(fp)) != EOF)
	{
		*buf++ = c;

		if (c == '\n')
			break;
	}

	*buf = '\0';

	return buf - s;
}

int readFile(const char* fname, const char* fmode)
{
	FILE* fp = fopen(fname, fmode);

	char rbuf[500] = { 0, };
	int lcnt = 0;
	while (readLine(fp, rbuf) > 0)
	{
		printf("%-3d] %s", ++lcnt, rbuf);
	}

	return lcnt;
}


int flag = 0;
void writeLine(const FILE* fp)
{
	char c;

	while ((c = getchar()) != EOF)
	{
		putc(c, fp);

		if (c == '\n') break;
		if (c == 'Q') {
			flag = 1;
			break;
		}
	}
}

void writeLines(const FILE* fp)
{
	while (!flag)
		writeLine(fp);
}

int main()
{
//	readFile("main.c", "r+");

	FILE* wfp = fopen("new_main.c", "w+");
	writeLines(wfp);

	system("pause");

	return 0;
}