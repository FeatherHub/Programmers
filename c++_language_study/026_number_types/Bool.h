#pragma once

enum BoolValue {TRUE, FALSE};

class Bool
{
public:
	Bool();
	Bool(bool v);
	Bool(BoolValue v);
	BoolValue getValue();
	Bool makeTrue();
	Bool makeFalse();
	Bool And(Bool b);
	Bool Or(Bool b);
	Bool Xor(Bool b);
	Bool Nand(Bool b);
	Bool Nor(Bool b);
	Bool Not();
	Bool eq(Bool b);
	Bool neq(Bool b);
	Bool isTrue();
	Bool isFalse();
	operator bool();
private:
	BoolValue _v;
};