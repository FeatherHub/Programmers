#pragma once
#include "Integer.h"

class Rational
{
public:
	Rational(int numerator, int denominator);
	Rational(Integer numerator, Integer denominator);
	void divgcd();
	void stdsign();
	Integer getGCD() const;
	Integer getLCM() const;
	Integer getNumerator() const;
	Integer getDenominator() const;
	void setNumerator(int n);
	void setDenominator(int d);
	void init(Integer n, Integer d);
	Rational add(Rational n);
	Rational sub(Rational n);
	Rational mul(Rational n);
	Rational div(Rational n);
	Rational invert();
	Integer invertNumerator();
	Integer invertDenominator();
	Rational reciprocal();
private:
	Integer num;
	Integer denom;
};
