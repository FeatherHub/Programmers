#include <stdio.h>
#include "point.h"

int main()
{
	point p1 = make_point(3, 4);	  
	point p2 = make_point(5, 6);

	this = &p1;
	point p3 = p1.add(p2);

	this = &p3;
    p3.print();

	return 0;
}