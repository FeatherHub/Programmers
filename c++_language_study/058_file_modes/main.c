#pragma warning (disable: 4996)

#include <stdio.h>


int readLine(char* buf)
{
	const char* s = buf;
	int c = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
			break;

		*buf++ = c;
	}

	*buf = '\0';

	return buf - s;
}

FILE* fileopener()
{
	FILE* fp = 0;
	char filename[128], filemode[16];

	while(1)
	{
		printf("enter file name: ");
		scanf("%s", filename);
		printf("enter file mode: ");
		scanf("%s", filemode);

		fp = fopen(filename, filemode);
		
		if (fp == 0)
			printf("fopen error\n");
		else {
			printf("fopen success\t%p\t%p\n", fp, fp->_Placeholder);
			break;
		}
	}

	return fp;
}

const char* dfFileName = "data.txt";
const char* dfFileMode = "w+";

int main()
{
//	FILE* wfp = fileopener();
	FILE* wfp = fopen(dfFileName, dfFileMode);

	char wbuf[100] = { '\0', };
	char rbuf[100] = { '\0', };

	int cnt = readLine(wbuf);
	fwrite(wbuf, sizeof(char), cnt, wfp);
	
	fclose(wfp);

	FILE* rfp = fopen(dfFileName, "r+");
	fread(rbuf, sizeof(char), cnt, rfp);

	printf("rbuf(%d) %s \n", sizeof(rbuf), rbuf);

	fclose(rfp);

	return 0;
}