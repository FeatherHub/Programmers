#include <iostream>
#include <array>

using namespace std;

enum 
{
	ALU_SELECT_AU = 0,
	ALU_SELECT_LU = 1,
	AU_OP_PLUS = 0,
	AU_OP_MINUS = 1,
	AU_OP_MULTI = 2,
	AU_OP_DIV = 3,
	LU_OP_AND = 0,
	LU_OP_OR = 1,
	LU_OP_XOR = 2,
	LU_OP_INV = 3,
};

int AndGate(int x, int y)
{
	return x & y;
}

int OrGate(int x, int y)
{
	return x | y;
}

int XorGate(int x, int y)
{
	return x ^ y;
}

int InvGate(int x)
{
	return ~x;
}

int Adder(int x, int y)
{
	return x + y;
}

int Subtractor(int x, int y)
{
	return x - y;
}

int Multiplier(int x, int y)
{
	//SetOverflowBit
	return x * y;
}

int Divider(int x, int y)
{
	if (y == 0) {
		//SetFlag DivByZero
		return 0;
	}

	return x / y;
}

int LogicUnit(int x, int y, int op)
{
	switch (op)
	{
	case LU_OP_AND:		return	AndGate	(x, y);
	case LU_OP_OR:		return	OrGate	(x, y);
	case LU_OP_XOR:		return	XorGate	(x, y);
	case LU_OP_INV:		return	InvGate	(x);
	default: //invalid instruction, interrupt
	}
}

int ArithmeticUnit(int x, int y, int op)
{
	switch (op)
	{
	case AU_OP_PLUS:	return Adder		(x, y);
	case AU_OP_MINUS:	return Subtractor	(x, y);
	case AU_OP_MULTI:	return Multiplier	(x, y);
	case AU_OP_DIV:		return Divider		(x, y);
	default: //invalid instruction, interrupt
	}
}

int ALU(int x, int y, int u, int op)
{
	switch (u)
	{
	case ALU_SELECT_AU:	return ArithmeticUnit	(x, y, op);
	case ALU_SELECT_LU:	return LogicUnit		(x, y, op);
	default: //invalid instruction, interrupt
	}
}