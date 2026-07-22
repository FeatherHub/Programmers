#include <stdio.h>
#include <string.h>
#include "Stack.h"
#include "Array.h"
#include "Reader.h"
#include <vector>
#include <iostream>

void reverse(const char* cstr)
{
	Stack<char> stk;
	
	for (; *cstr; cstr++)
		stk.push(*cstr);

	for(; !stk.empty(); )
		putchar(stk.pop());
}

void stacktest();

int main()
{
	Array<int> iarr; 
	iarr[1] = 11;
	iarr[11] = 111;
	iarr[123123] = 1111;
	
	return 0;
}

void stacktest()
{
	char buf[1000];
	Reader r;

	r.getc();
	r.ungetLastCharacter();
	r.readLine(buf);

	reverse(buf);
}
