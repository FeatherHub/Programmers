#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "decoder.h"

int main()
{
	char* insBuffer = 0;
	int bufferLen = 0;

	printf(": ");
	bufferLen = getInput(&insBuffer);
	
	for (int i = 0; i < bufferLen; i++)
	{
		if (insBuffer[i] == '\n' ||
			insBuffer[i] == 0) {
			break;
		}

		printf("%c", insBuffer[i]);
	}

	printf("\n");

	char** tokens = 0;
	int tokenNum = 0;
	tokenNum = tokenizer(insBuffer, &tokens);

	for (int tokenIdx = 0; tokenIdx < tokenNum; tokenIdx++)
	{
		char* curToken = tokens[tokenIdx];
		printf("token-%d:[", tokenIdx+1);
		for (int charIdx = 0; curToken[charIdx] != 0; charIdx++)
		{
			printf("%c", curToken[charIdx]);
		}
		printf("]\n");
	}

	distributer(tokens);

	return 0;
}