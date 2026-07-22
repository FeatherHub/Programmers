#pragma once
#include "Stack.h"

class Reader
{
public:
	int read(char*, char);
	int readLine(char*);
	int getc();
	int unget(char);
	int unget(char*);
	int ungetLastCharacter();
	int lineLen(const char*);
private:
	Stack<char> ungetBuffer;
	char lastChar;
};