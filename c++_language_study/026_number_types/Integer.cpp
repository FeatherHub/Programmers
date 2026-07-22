#include "Integer.h"

Integer::Integer() : Integer(0)
{
}

Integer::Integer(int i) : Integer(
	Natural(i >= 0 ? i : -i), 
	i>=0 ? SignValue::PLUS : SignValue::MINUS)
{

}

Integer::Integer(Natural n) : Integer(n, SignValue::PLUS)
{
}

Integer::Integer(Natural n, Sign s)
{
	//treat zero as positive integer
	if (n.eq(Natural(0)))
		s.setPlus();
		
	init(n, s);
}

void Integer::assign(Integer i)
{
	*this = i;
}

Natural Integer::getNatural()
{
	return _n;
}

Sign Integer::getSign()
{
	return _s;
}

Bool Integer::eq(Integer i)
{
	return getNatural().eq(i.getNatural())
		.And(getSign().eq(i.getSign()));
}

Bool Integer::neq(Integer i) 
{
	return eq(i).Not();
}

Bool Integer::gt(Integer i) 
{
	if (getSign().isPlus().And(i.getSign().isPlus()))
		return getNatural().gt(i.getNatural());
	if (getSign().isPlus().And(i.getSign().isMinus()))
		return true;
	if (getSign().isMinus().And(i.getSign().isPlus()))
		return false;
	if (getSign().isMinus().And(i.getSign().isMinus()))
		return getNatural().lt(i.getNatural());
}

Bool Integer::lt(Integer i)
{
	return (gt(i).Not()).And(eq(i).Not());
}

Bool Integer::geq(Integer i)
{
	return lt(i).Not();
}

Bool Integer::leq(Integer i)
{
	return gt(i).Not();
}

Bool Integer::invert(Integer i)
{
	return getSign().neq(i.getSign());
}

Integer Integer::add(Integer i) 
{
	if (getSign().eq(i.getSign()))
		return Integer(getNatural().add(i.getNatural()), getSign());
	//else
	//	return gt(i) ?
	//	Integer(getNatural().sub(i.getNatural()), getSign()) :
	//	Integer(i.getNatural().sub(getNatural()), i.getSign());

	if (getNatural().gt(i.getNatural()))
		return Integer(getNatural().sub(i.getNatural()), getSign());
	else
		return Integer(i.getNatural().sub(getNatural()), i.getSign());
}

Integer Integer::sub(Integer i)
{
	return add(i.invert());
}

Integer Integer::mul(Integer i)
{
	return Integer(getNatural().mul(i.getNatural()), getSign().mul(i.getSign()));
}

Integer Integer::div(Integer i)
{
	return Integer(getNatural().div(i.getNatural()), getSign().mul(i.getSign()));
}

Integer Integer::copy()
{
	return Integer(*this);
}

Integer Integer::invert()
{
	return Integer(getNatural(), getSign().invert());
}

void Integer::setInvert()
{
	_s.setInvert();
}

Integer Integer::abs()
{
	return getSign().isPlus() ? copy() : invert();
}

Integer& Integer::increment()
{
	return *this = Integer(add(Integer(1)));
}

Integer& Integer::decrement()
{
	return *this = Integer(add(Integer(1, SignValue::MINUS)));
}

void Integer::init(Natural n, Sign s)
{
	_n = n;
	_s = s;
}
