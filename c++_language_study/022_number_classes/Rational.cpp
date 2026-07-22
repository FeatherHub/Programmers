#include "Rational.h"
#include <math.h>

Rational::Rational(int numerator, int denominator)
{
	Rational(Integer(numerator), Integer(denominator));
}

Rational::Rational(Integer numerator, Integer denominator)
{
	if(denominator.getQuantity().compare())
	init(numerator, denominator);
}

void Rational::divgcd()
{
	int gcd = getGCD();
	init(getNumerator() / gcd, getDenominator() / gcd);
}

void Rational::stdsign()
{
	if (getDenominator() < 0)
		init(invertNumerator(), invertDenominator());
}

int Rational::getGCD() const
{
	int a = abs(getNumerator());
	int b = abs(getDenominator());

	while (a != 0 && b != 0)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}

	return a == 0 ? a : b;
}

int Rational::getLCM() const
{
	return getDenominator() / getGCD() * getNumerator();
}

int Rational::getNumerator() const
{
	return num;
}

int Rational::getDenominator() const
{
	return denom;
}

void Rational::setNumerator(int n)
{
	num = n;
}

void Rational::setDenominator(int d)
{
	denom = d;
}

void Rational::init(Integer n, Integer d)
{
}

void Rational::init(int n, int d)
{
	setNumerator(n);
	setDenominator(d);
}

Rational Rational::add(Rational n)
{
	int lcm = getLCM();
	return Rational(
		lcm / getDenominator() * getNumerator() +
		lcm / n.getDenominator() * n.getNumerator(),
		lcm
	);
}

Rational Rational::sub(Rational n)
{
	return add(n.invert());
}

Rational Rational::mul(Rational n)
{
	return Rational(
		getNumerator() * n.getNumerator(),
		getDenominator() * n.getDenominator()
	);
}

Rational Rational::div(Rational n)
{
	return mul(n.reciprocal());
}

Rational Rational::invert()
{
	return Rational(invertNumerator(), invertDenominator());
}

int Rational::invertNumerator()
{
	return -getNumerator();
}

int Rational::invertDenominator()
{
	return -getDenominator();
}

Rational Rational::reciprocal()
{
	return Rational(getDenominator(), getNumerator());
}
