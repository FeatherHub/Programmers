#include "Rational.h"
#include <iostream>
#include <cmath>

Rational::Rational() : Rational(Integer(0), Integer(1))
{
}

Rational::Rational(Integer n, Integer d)
{
	if (d.getNatural().eq(Natural(0))) {
		std::cout << "ERROR-Rational(Integer, Integer)" << std::endl;
		n = Integer(0);
		d = Integer(1);
	}

	init(n, d);
	stdsign();
	divgcd();
}

Integer Rational::getNumerator()
{
	return _n;
}

Integer Rational::getDenominator()
{
	return _d;
}

bool Rational::eq(Rational r)
{
	return getDenominator().eq(r.getDenominator()) &&
		getNumerator().eq(r.getNumerator());
}

bool Rational::neq(Rational r)
{
	return !eq(r);
}

bool Rational::gt(Rational r)
{
	if (getNumerator().getSign().neq(r.getNumerator().getSign()))
		return getNumerator().getSign().isPlus() ? true : false;
	else {
		Integer lcm = calcLCM(r);
		Integer ln = getNumerator().mul(calcCDF(lcm));
		Integer rn = r.getNumerator().mul(r.calcCDF(lcm));

		return getNumerator().getSign().isPlus() ? ln.gt(rn) : ln.lt(rn);
	}
}

bool Rational::lt(Rational r)
{
	return !gt(r);
}

bool Rational::invert(Rational r)
{
	return eq(r.invert());
}

bool Rational::reciprocal(Rational r)
{
	return eq(r.reciprocal());
}

Rational Rational::invert()
{
	return Rational(getNumerator().invert(), getDenominator());
}

Rational Rational::reciprocal()
{
	return Rational(getDenominator(), getNumerator());
}

Rational Rational::add(Rational r)
{
	Integer lcm = calcLCM(r);
	Integer ln = getNumerator().mul(calcCDF(lcm));
	Integer rn = r.getNumerator().mul(r.calcCDF(lcm));

	return Rational(ln.add(rn), lcm);
}

Rational Rational::sub(Rational r)
{
	return add(r.invert());
}

Rational Rational::mul(Rational r)
{
	return Rational(
		getNumerator().mul(r.getNumerator()),
		getDenominator().mul(r.getDenominator())
	);
}

Rational Rational::div(Rational r)
{
	return mul(r.reciprocal());
}

void Rational::init(Integer n, Integer d)
{
	_n = n;
	_d = d;
}

void Rational::stdsign()
{
	if (getDenominator().getSign().isMinus()) {
		_d.setInvert();
		_n.setInvert();
	}
}

void Rational::divgcd()
{
	Integer gcd = calcGCD();
	init(_n.div(gcd), _d.div(gcd));
}

Integer Rational::calcGCD()
{
	Integer i, j;

	for (i = getNumerator().abs(), j = getDenominator();
		i.gt(Integer(0)).And(j.gt(Integer(0)));
		i.gt(j) ? i.assign(i.sub(j)) : j.assign(j.sub(i))
		);

	return i.gt(j) ? i : j;
}

Integer Rational::calcLCM(Rational r)
{
	Integer lcm(1);

	for (Integer i(1), j(1);
		i.mul(getDenominator()).leq(getDenominator().mul(r.getDenominator()))
		.Or(j.mul(r.getDenominator()).leq(getDenominator().mul(r.getDenominator())));
		//no post-loop index process
		)
	{
		if (i.mul(getDenominator()).lt(j.mul(r.getDenominator())))
			i.increment();
		else if (j.mul(r.getDenominator()).lt(i.mul(getDenominator())))
			j.increment();
		else {
			lcm.assign(i.mul(getDenominator()));
			break;
		}
	}

	return lcm;
}

Integer Rational::calcCDF(Integer lcm)
{
	return lcm.div(getDenominator());
}
