#include "Complex.h"
#include <math.h>

Complex::Complex(int real, int imag)
{
	set(real, imag);
}

Complex::Complex(const Complex& c)
{
	set(c.r, c.i);
}

int Complex::getReal() const
{
	return r;
}

int Complex::getImag() const
{
	return i;
}

void Complex::set(int real, int imag)
{
	setReal(real);
	setImag(imag);
}

void Complex::setReal(int real)
{
	r = real;
}

void Complex::setImag(int imag)
{
	i = imag;
}

Complex Complex::add(Complex c)
{
	return Complex(addReal(c), addImag(c));
}

Complex Complex::add(int n)
{
	return add(Complex(n, 0));
}

Complex Complex::sub(Complex c)
{
	return add(c.makeInvert());
}

Complex Complex::mul(Complex c)
{
	return Complex(
		mulReals(c) - mulImags(c),
		mulRealImag(c) + mulImagReal(c)
	);
}

Complex Complex::mul(int n)
{
	return mul(Complex(n, 0));
}

int Complex::addReal(Complex c)
{
	return getReal() + c.getReal();
}

int Complex::addImag(Complex c)
{
	return getImag() + c.getImag();
}

Complex Complex::makeCopy()
{
	return Complex(getReal(), getImag());
}

Complex Complex::makeRealInvert()
{
	return Complex(invertReal(), getImag());
}

Complex Complex::makeImagInvert()
{
	return Complex(getReal(), invertImag());
}

Complex Complex::makeInvert()
{
	return Complex(invertReal(), invertImag());
}

Complex Complex::makeCompl()
{
	return makeImagInvert();
}

Complex Complex::makeAbs()
{
	return Complex(abs(getReal()), abs(getImag()));
}

int Complex::mulReals(Complex c)
{
	return getReal() * c.getReal();
}

int Complex::mulImags(Complex c)
{
	return getImag() * c.getImag();
}

int Complex::mulRealImag(Complex c)
{
	return getReal() * c.getImag();
}

int Complex::mulImagReal(Complex c)
{
	return getImag() * c.getReal();
}

bool Complex::compare(Complex c)
{
	return compareReal(c) && compareImag(c);
}

bool Complex::compareReal(Complex c)
{
	return getReal() == c.getReal();
}

bool Complex::compareImag(Complex c)
{
	return getImag() == c.getImag();
}

bool Complex::isCompl(Complex c)
{
	return compare(c.makeCompl());
}

bool Complex::isInvert(Complex c)
{
	return compare(c.makeInvert());
}

bool Complex::isRealInvert(Complex c)
{
	return compare(c.makeRealInvert());
}

bool Complex::isImagInvert(Complex c)
{
	return compare(c.makeImagInvert());;
}

int Complex::invertReal()
{
	return -getReal();
}

void Complex::setRealInvert()
{
	setReal(invertReal());
}

int Complex::invertImag()
{
	return -getImag();
}

void Complex::setImagInvert()
{
	setImag(invertImag());
}

