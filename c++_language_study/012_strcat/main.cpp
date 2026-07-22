#include <stdio.h>

/* assumption */
// strings are terminated with null character
// src has enough space for the concatenation
char* my_strcat(char* src, const char* cat);

const int BUF_SIZE = 300;

int main()
{
	char bbuf[BUF_SIZE] = "";

	printf("%s \n", my_strcat(bbuf, "1 "));
	printf("%s \n", my_strcat(bbuf, "2 "));
	printf("%s \n", my_strcat(bbuf, "3 "));
	printf("%s \n", my_strcat(bbuf, "4 "));
	printf("%s \n", my_strcat(bbuf, "5 "));
	printf("%s \n", my_strcat(bbuf, "6 "));

	return 0;
}

char* my_strcat(char* src, const char* cat)
{
	int i, j;
	i = j = -1;

	//find src position to concatenate
	while (src[++i] != '\0');

	//concatenate to src
	while ((src[i++] = cat[++j]) != '\0');
	
	return src;
}