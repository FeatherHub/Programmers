#pragma once
#include "Rational.h"

class Complex
{
public:
	Complex(int real, int imag);
	Complex(const Complex& c);
	int getReal() const;
	int getImag() const;
	void set(int real, int imag);
	void setReal(int real);
	void setImag(int imag);
	Complex add(Complex c);
	Complex add(int n);
	Complex sub(Complex c);
	Complex mul(Complex c);
	Complex mul(int n);
	int addReal(Complex c);
	int addImag(Complex c);
	Complex makeCopy();
	Complex makeRealInvert();
	Complex makeImagInvert();
	Complex makeInvert();
	Complex makeCompl();
	Complex makeAbs();
	int mulReals(Complex c);
	int mulImags(Complex c);
	int mulRealImag(Complex c);
	int mulImagReal(Complex c);
	bool compare(Complex c);
	bool compareReal(Complex c);
	bool compareImag(Complex c);
	bool isCompl(Complex c);
	bool isInvert(Complex c);
	bool isRealInvert(Complex c);
	bool isImagInvert(Complex c);
	int invertReal();
	void setRealInvert();
	int invertImag();
	void setImagInvert();
private:
	int r;
	int i;
};
