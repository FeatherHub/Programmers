#pragma once

#include "Bool.h"

class Natural
{
public:
	Natural() : Natural(0) { }
	Natural(int _v) { _v < 0 ? setValue(0) : setValue(_v); }

	int getValue() { return _v; }
	void setValue(int v) { _v = v; }

	Bool eq(Natural n) { return getValue() == n.getValue(); }
	Bool lt(Natural n) { return getValue() < n.getValue(); }
	Bool gt(Natural n) { return getValue() > n.getValue(); }
	Bool neq(Natural n) { return eq(n).Not(); }
	Bool geq(Natural n) { return lt(n).Not(); }
	Bool leq(Natural n) { return gt(n).Not(); }

	Natural add(Natural n) { return Natural(getValue() + n.getValue()); }
	Natural sub(Natural n) { return Natural(getValue() - n.getValue()); }
	Natural mul(Natural n) { return Natural(getValue() * n.getValue()); }
	Natural div(Natural n) { return Natural(getValue() / n.getValue()); }

private:
	int _v;
};