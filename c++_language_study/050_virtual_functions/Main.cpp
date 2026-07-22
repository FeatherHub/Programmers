#include "VirtualBase.h"
#include "Derive.h"

int main()
{
	Derive1 d1;
	d1.type1(10);
	d1.type2();

	VirtualBase* vb = &d1;
	vb->type1(10);
	vb->type2();

	return 0;
}