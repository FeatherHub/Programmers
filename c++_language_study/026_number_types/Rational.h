#pragma once

#include "Integer.h"

class Rational
{
public:
	Rational();
	Rational(Integer n, Integer d);

	Integer getNumerator();
	Integer getDenominator();

	bool eq(Rational r);
	bool neq(Rational r);
	bool gt(Rational r);
	bool lt(Rational r);
	bool invert(Rational r);
	bool reciprocal(Rational r);

	Rational invert();
	Rational reciprocal();

	Rational add(Rational r);
	Rational sub(Rational r);
	Rational mul(Rational r);
	Rational div(Rational r);
	
	void init(Integer n, Integer d);
	void stdsign();
	void divgcd();

	Integer calcGCD();
	Integer calcLCM(Rational r);

	// Common Denominator Factor
	// 
	//  3	    1	   3 x (20 / 5)       1 x (20 / 4)
	// ---  +  --- =  -------------- +   --------------
	//  5       4          20                  20
	//
	// CDF for 3/5 = 20 / 5
	// CDF for 1/4 = 20 / 4
	// CDF = LCM / denominator
	Integer calcCDF(Integer lcm); 
private:
	Integer _n;
	Integer _d;
};
