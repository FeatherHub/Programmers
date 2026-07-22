#include "VirtualBase.h"
#include "Derive.h"

#include <iostream>
using namespace std;

int VirtualBase::type1(int arg1)
{
	cout << "I am VirtualBase and this is type1() and I am going to polymorphize" << endl;

	if (type == T_Derive1)
	{
		Derive1 d1;
		return d1.type1(arg1);
	}
}

void VirtualBase::type2(void)
{
	cout << "I am VirtualBase and this is type2() and I am going to polymorphize" << endl;

	if (type == T_Derive1)
	{
		Derive1 d1;
		return d1.type2();
	}
}
