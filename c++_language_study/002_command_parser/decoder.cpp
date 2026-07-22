#define _CRT_SECURE_NO_WARNINGS

#include "decoder.h"

#include <Windows.h>
#include <stdio.h>
#include <string.h>

const int MAX_INSTR_LEN = 32;
const int MAX_TOKEN_NUM = 5;

const char DELIMITER = ' ';

const char* FUNC_NAME_01 = "func1";
const char* FUNC_NAME_02 = "func2";

int getInput(char** buffer)
{
	*buffer = (char*)malloc(sizeof(char) * MAX_INSTR_LEN + 2); 
	//one for padding delimter after the last word 
	//the other for marking end of string with null char 

	int instrLen = 0;
	int i = 0;

	char prevChar = 0; 
	
	while (1)
	{
		char c = 0;
		scanf_s("%c", &c, 1);

		//ignore leading delimiters
		if (i == 0 && c == DELIMITER) {
			continue;
		}

		//ignore consecutive delimiters
		if (c == DELIMITER && prevChar == DELIMITER) {
			continue;
		}

		if (c == '\n') {
			(*buffer)[i] = DELIMITER;
			(*buffer)[i+1] = 0;
			instrLen = i+1;
			break;
		}

		(*buffer)[i] = c;
		i++;

		if (i >= MAX_INSTR_LEN) {
			(*buffer)[MAX_INSTR_LEN] = DELIMITER;
			(*buffer)[MAX_INSTR_LEN+1] = 0;
			instrLen = MAX_INSTR_LEN+1;
			break;
		}

		prevChar = c;
	}

	//for (i = 0; i < MAX_INSTR_LEN; i++)
	//{
	//	char c = 0;
	//	scanf_s("%c", &c, 1);

	//	if (c == '\n') {
	//		*buffer[i] = 0;
	//		break;
	//	}

	//	*buffer[i] = c;
	//}
	//instrLen = i;

	return instrLen;
}

int tokenizer(char* string, char*** tokens)
{
	int curIdx = 0;
	int prevDelimiterIdx = -1;
	int tokenIdx = 0;

	(*tokens) = (char**)malloc(MAX_TOKEN_NUM * sizeof(char*));
	
	while (1)
	{
		char curChar = string[curIdx];
		
		if (tokenIdx >= MAX_TOKEN_NUM ||
			curChar == 0)
			break;

		if (curChar == DELIMITER)
		{
			int tokenLen = curIdx - prevDelimiterIdx - 1;
			
			((*tokens)[tokenIdx]) = (char*)malloc((tokenLen + 1) * sizeof(char));

			int srcIdx = prevDelimiterIdx+1;
			int destIdx = 0;
			while (destIdx < tokenLen) 
			{
				((*tokens)[tokenIdx])[destIdx++] = string[srcIdx++];
			}
			//for (int destIdx = 0, srcIdx = prevDelimiterIdx; 
			//	destIdx < tokenLen; 
			//	destIdx++, srcIdx++)
			//{
			//	((*tokens)[tokenIdx])[destIdx] = string[srcIdx];
			//}

			((*tokens)[tokenIdx])[tokenLen] = 0;

			tokenIdx++;
			prevDelimiterIdx = curIdx;
		}
		curIdx++;
	}
	return tokenIdx;
}

void distributer(char** tokens)
{
	const char* funcName = tokens[0];

	if (!strcmp(funcName, FUNC_NAME_01)) {
		func1Decoder(tokens);
	}
	else if (!strcmp(funcName, FUNC_NAME_02)) {
		func2Decoder(tokens);
	}
	else {
		printf("invalid instruction \n");
	}
}

void func1Decoder(char** params)
{
	const char* param1 = params[1];
	const char* param2 = params[2];

	int iparam1 = atoi(param1);
	int iparam2 = atoi(param2);

	func1(iparam1, iparam2);
}

void func2Decoder(char** params)
{
	const char* param1 = params[1];
	const char* param2 = params[2];
	const char* param3 = params[3];

	func2(param1, param2, param3);
}

void func1(int a, int b)
{
	printf("%d + %d = %d \n", a, b, a + b);
}

void func2(const char* s1, const char*s2, const char* s3)
{
	printf("%s loves %s \n", s1, s2);
	printf("%s loves %s \n", s2, s3);
	printf("%s loves %s \n", s3, s1);
}
