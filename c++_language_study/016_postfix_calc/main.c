#include <stdio.h>

#include "stack.h"
#include "mystring.h"

#include "component_test.h"

enum optype {PLUS, MINUS, MULTI, DIV, ERR};

int controller();
int getLine(char* buf);
void cleanLine(char* line);
int decoder(char* line);
int calculate(int op);

int main()
{
	component_test();

	//controller();

	return 0;
}

int controller()
{
	char buf[1000] = { "" };

	while (getLine(buf) != 0)
	{
		cleanLine(buf);

		int op = decoder(buf);

		if (op == ERR) {
			printf("Invalid Operator.\n");
			continue;
		}

		int res = calculate(op);
		printf("%d \n", res);
	}

	return 0;
}

int getLine(char* buf)
{
	int i = 0;
	int c = 0;
	while ((c = getchar()) != EOF)
	{
		if (c != '\n')
			buf[i++] = c;
		else
			break;
	}

	buf[i] = '\0';
	return i;
}

void cleanLine(char* buf)
{
	mycompact(buf, ' ');
	mycompact(buf, '\t');
	mytrim(buf, ' ');
	mytrim(buf, '\t');
}

int decoder(char* line)
{
	char buf[100] = {""};
	int i = 0;
	int start = 0;
	int c = 0;
	int type = 0;

	while ( (c =line[i]) != '\0')
	{
		if (c == ' ')
		{
			buf[i] = '\0';
			push(myatoi(buf + start));
			start = i + 1;
		}
		else
			buf[i] = c;

		i++;
	}

	c = line[i - 1];
	switch (c)
	{
	case '+': type = PLUS; break;
	case '-': type = MINUS; break;
	case '*': type = MULTI; break;
	case '/': type = DIV; break;
	default: type = ERR; break;
	}

	return type;
}

int calculate(int op)
{
	int res = 0;
	int op2 = 0;

	switch (op)
	{
	case PLUS:
		res = pop() + pop();
		break;
	case MINUS:
		op2 = pop();
		res = pop() - op2;
		break;
	case MULTI:
		res = pop() * pop();
		break;
	case DIV:
		op2 = pop();
		res = pop() / op2;
		break;
	}

	return res;
}