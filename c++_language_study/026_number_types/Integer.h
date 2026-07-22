#pragma once
#include "Natural.h"
#include "Sign.h"

class Integer
{
public:
	Integer();
	Integer(int i);
	Integer(Natural n);
	Integer(Natural n, Sign s);

	void assign(Integer i);

	Natural getNatural();
	Sign getSign();

	Bool eq(Integer i);
	Bool neq(Integer i);
	Bool gt(Integer i);
	Bool lt(Integer i);
	Bool geq(Integer i);
	Bool leq(Integer i);
	
	Bool invert(Integer i);

	Integer add(Integer i);
	Integer sub(Integer i);
	Integer mul(Integer i);
	Integer div(Integer i);
	Integer copy();
	Integer invert();
	void setInvert();
	Integer abs();
	Integer& increment();
	Integer& decrement();

	void init(Natural n, Sign s);
private:
	Natural _n;
	Sign _s;
};
