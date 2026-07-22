#include "stack.h"

#define STACK_SIZE 1000

static int buf[STACK_SIZE] = { 0, };
static int sp = 0;

int pop()
{
	if (sp <= 0) return -1;
	
	return buf[--sp];
}

void push(int d)
{
	if (sp >= STACK_SIZE) return;

	buf[sp++] = d;
}
