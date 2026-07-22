#pragma once

class VirtualBase
{
public:
	int type1(int arg1);
	void type2(void);
protected:
	int type;
	enum {T_Derive1};
};