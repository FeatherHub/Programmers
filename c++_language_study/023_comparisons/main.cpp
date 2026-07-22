#include <iostream>

//******************** comparison operators ****************************//
//																		//
// a < b							LESS-THAN				LT			//
// a == b							EQUAL					EQ			//
// a > b							GREATER-THAN			GT			//
// a != b							NOT-EQUAL				NEQ			//
// a <= b	a < b || a == b			LESS-THAN-OR-EQUAL		LEQ			//
// a >= b	a > b || a == b			GREATER-THAN-OR-EQUAL	GEQ			//
//																		//
// !(a < b)		a == b ||  a > b			NOT-LESS-THAN		NLT		// 
// !(a == b)	a < b || a > b || a != b	NOT-EQUAL			NEQ		//
// !(a > b)		a < b || a == b				NOT-GREATER-THAN	NGT		//
// !(a <= b)	a > b				NOT-LESS-THAN-OR-EQUAL		NLEQ	//
// !(a >= b)	a < b				NOT-GREATER-THAN-OR-EQUAL	NGEQ	//
// !(a != b)	a == b				NOT-NOT-EQUAL				NNEQ	//
//																		//
//**********************************************************************//

// NEQ		<=>		GT | LT
// EQ		<=>		NGT & NLT

enum CMP_RES {LT, EQ, GT, NEQ};

bool lt(int l, int r)
{
	return l < r;
}

bool gt(int l, int r)
{
	return l > r;
}

bool eq(int l, int r)
{
	return l == r;
}

bool neg(bool f)
{
	return not f;
}

bool _or(bool l, bool r)
{
	return l or r;
}

bool _and(bool l, bool r)
{
	return l and r;
}

int main()
{
	std::cout << eq(lt(3, 4), neg(gt(3, 4)));
	return 0;
}