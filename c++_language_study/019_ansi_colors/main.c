#define _CRT_NONSTDC_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ANSI escape sequence which changes color mode
#define RESET	"\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define COLOR_NUM 300

void _strcpy(const char* s, char* t);

int main()
{
	const char* colorModePrefix = "\x1B[";
	const char* colorModePrefixTest = "x1B[";

	char colorMode[COLOR_NUM][12] = { "" };

	for (int i = 0; i < COLOR_NUM; i++)
		_strcpy(colorModePrefix, colorMode[i]);
	
	char cbuf[5] = "";
	for (int i = 0; i < COLOR_NUM; i++)
	{
		itoa(i, cbuf, 10);
		strcat(colorMode[i], cbuf);
		strcat(colorMode[i], "m");
	}

	for (int i = 0; i < COLOR_NUM; i++)
	{
		printf(colorMode[i]);
		printf("%-10s %3d: %s", colorMode[i]+1, i, "jjjjjjjj");
		printf(RESET);
		putchar('\n');
	}

	return 0;
}

void _strcpy(const char* s, char* t)
{
	while ((*t++ = *s++) != '\0');

	*t = *s;
}