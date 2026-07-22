#pragma once
#include "Rational.h"
#include "IntegerUtility.h"
#include <iostream>

using namespace std;

static class RationalUtility
{
public:
	static void printr(Rational r)
	{
		IntegerUtility ih;
		ih.puti(r.getNumerator());
		cout << " / ";
		ih.puti(r.getDenominator());
		cout << endl;
	}

	static float convert(Rational r)
	{
		return (r.getNumerator().getSign().isPlus() ? 1 : -1) *
			(float)r.getNumerator().getNatural().getValue() / (float)r.getDenominator().getNatural().getValue();
	}

	static bool cmp(float l, float r)
	{
		float tolerance = 0.0001f;
		return l - tolerance <= r && r <= l + tolerance;
	}
};