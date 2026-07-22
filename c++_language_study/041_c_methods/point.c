#include "point.h"
#include <stdio.h>

point add(point p2);
void print();

point make_point(int x, int y)
{
	point p;
	p.add = add;
	p.print = print;
	p.x = x;
	p.y = y;
	return p;
}

void print()
{
	printf("x: %d y: %d \n", ((point*)this)->x, ((point*)this)->y);
}

point add(point p2)
{
	return make_point(((point*)this)->x + p2.x, ((point*)this)->y + p2.y);
}
