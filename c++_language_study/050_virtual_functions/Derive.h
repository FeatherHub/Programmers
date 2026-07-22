#pragma once
#include "VirtualBase.h"

class Derive1 : public VirtualBase
{
public:
	Derive1();
	int type1(int arg1);
	void type2(void);
};
