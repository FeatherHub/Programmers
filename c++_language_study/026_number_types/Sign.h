#pragma once
#include "Bool.h"

enum SignValue { PLUS, MINUS };

class Sign
{
public:
	Sign() : Sign(SignValue::PLUS) { }
	Sign(SignValue v) { setSign(v); }

	Sign makePlus() { return Sign(SignValue::PLUS); }
	Sign makeMinus() { return Sign(SignValue::MINUS); }

	void setSign(SignValue s) { _v = s; }
	SignValue getSign() { return _v; }

	Sign mul(Sign s) { return eq(s) ? makePlus() : makeMinus(); }
	Sign invert() { return isPlus() ? makeMinus() : makePlus(); }

	void setInvert() { isPlus() ? setSign(SignValue::MINUS) : setSign(SignValue::PLUS); }
	void setPlus() { setSign(SignValue::PLUS); }
	void setMinus() { setSign(SignValue::MINUS); }

	Bool eq(Sign s) { return getSign() == s.getSign(); }
	Bool neq(Sign s) { return !eq(s); }
	
	Bool isPlus() { return eq(SignValue::PLUS); }
	Bool isMinus() { return !isPlus(); }

private:
	SignValue _v;
};