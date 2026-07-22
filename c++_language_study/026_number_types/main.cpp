#include <iostream>
#include <iomanip>

#include "Natural.h"
#include "Sign.h"
#include "Integer.h"
#include "IntegerUtility.h"
#include "Bool.h"
#include "RationalUtility.h"
#include "Rational.h"

using namespace std;

void ntest();
void stest();
void itest();
void itest2();
void itest3();
void itest4();
void btest();
void rtest();
void rtest2();

int main()
{
	rtest2();

	return 0;
}

void rtest2()
{
	int test_size = 20;
	RationalUtility rh;
	for (int i = -test_size; i < test_size; i++)
	for (int j = -test_size; j < test_size; j++)
	for (int k = -test_size; k < test_size; k++)
	for (int l = -test_size; l < test_size; l++)
	{
		if (i == 0 || j == 0 || k == 0 || l == 0);
			continue;

		Rational r1 = Rational(i, j);
		Rational r2 = Rational(k, l);

		//rh.printr(r1.add(r2));
		//rh.printr(r1.div(r2));
		//rh.printr(r1.mul(r2));
		//rh.printr(r1.sub(r2));

		cout << std::fixed;
		std::setprecision(3);

		if (!rh.cmp(rh.convert(r1.add(r2)), (float)i / j + (float)k / l))
			cout << "Add Error: " << rh.convert(r1.add(r2)) << " & " << (float)i / j + (float)k / l << endl;

		if (!rh.cmp(rh.convert(r1.sub(r2)), (float)i / j - (float)k / l))
		{
			cout << "====================" << endl;
			cout << "Sub Error: " << rh.convert(r1.sub(r2)) << " & " << (float)i / j - (float)k / l << endl;
			cout << "i " << i << " j " << j << " k " << k << " l " << l << endl;
			cout << "r1-r2: " << rh.convert(r1.sub(r2)) << " "; rh.printr(r1.sub(r2));
			cout << "r1: ";  rh.printr(r1);
			cout << "r2: ";  rh.printr(r2);
			cout << "r2.invert(): ";  rh.printr(r2.invert());
			cout << "i/j: " << (float)i / j << endl;
			cout << "k/l: " << (float)k / l << endl;
			cout << "====================" << endl;
		}

		if (!rh.cmp(rh.convert(r1.mul(r2)), (float)i / j * (float)k / l))
			cout << "Mul Error: " << rh.convert(r1.mul(r2)) << " & " << (float)i / j * (float)k / l << endl;


		if (!rh.cmp(rh.convert(r1.div(r2)), ((float)i / j) / ((float)k / l)))
			cout << "Div Error: " << rh.convert(r1.div(r2)) << " & " << ((float)i / j) / ((float)k / l) << endl;
			//cout << "Div Error: " << rh.convert(r1.div(r2)) << " & " << (float)i / j / (float)k / l << endl;
	}
}

void rtest()
{
	Rational r1(Integer(2, SignValue::MINUS), Integer(5, SignValue::MINUS)),
		r2(Integer(7), Integer(8).invert()),
		r3(Integer(8), Integer(-9)),
		r4(Integer(10), Integer(-3));
	RationalUtility rh;

	rh.printr(r1.add(r4));
	rh.printr(r2.mul(r3));
	rh.printr(r3.sub(r2));
	rh.printr(r4.invert().mul(r4));

	
}

void btest()
{
	Bool b1(BoolValue::TRUE), b2(BoolValue::FALSE);

	cout << b1.And(b2) << endl;
	cout << b1.Or(b2) << endl;
	cout << b1.Nand(b2) << endl;
	cout << b1.Xor(b2) << endl;
	cout << b1.Not() << endl;
	cout << b1.And(b2).Not() << endl;
	cout << b1.Or(b2).Not() << endl;

	cout << "Or Test" << endl;

	Bool b3(BoolValue::TRUE), b4(BoolValue::TRUE);

	cout << b3.Or(b4) << endl;
	cout << b3.Or(b4.Not()) << endl;
	cout << b3.Not().Or(b4) << endl;
	cout << b3.Not().Or(b4.Not()) << endl;

	cout << "And Test" << endl;

	cout << b3.And(b4) << endl;
	cout << b3.And(b4.Not()) << endl;
	cout << b3.Not().And(b4) << endl;
	cout << b3.Not().And(b4.Not()) << endl;

}
void itest4()
{
	Integer i1(3);
	Integer i2(3, SignValue::MINUS);
	IntegerUtility h;

	cout << i1.invert(i2) << endl;
	h.printi(i1.increment());
	h.printi(i2.decrement());
}

void itest3_help2(int i, int j, int r1, int r2, const char* op)
{
	if (r1 == r2)
		cout << "ok ";
	else
		cout << endl << "error: " << i << " " << j << op << r2 << endl;
}
void itest3_help(int i, int j)
{
	IntegerUtility h;
	Integer i1 = h.convert(i);
	Integer i2 = h.convert(j);

	itest3_help2(i, j, i + j, h.convert(i1.add(i2)), " ADD ");
	itest3_help2(i, j, i - j, h.convert(i1.sub(i2)), " SUB ");
	itest3_help2(i, j, i * j, h.convert(i1.mul(i2)), " MUL ");
}
void itest3()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			itest3_help(i, j);
			itest3_help(i, -j);
			itest3_help(-i, j);
			itest3_help(-i, -j);
		}
	}
}
void itest2()
{
	IntegerUtility h;

	const int TEST_RANGE = 1000;

	for (int i = 0; i < TEST_RANGE; i++)
	{
		for (int j = 0; j < TEST_RANGE; j++)
		{
			Integer i1(i);
			Integer i2(j);

			//cout << i << " + -" << j << " = " << i + -j << endl;
			//cout << i << " - -" << j << " = " << i - -j << endl;

			if (-i != h.convert(i1.invert()))
				cout << "error1" << endl;
			if (-j != h.convert(i2.invert()))
				cout << "error2" << endl;

			//cout << i << " & " << h.convert(i1) << endl;
			//cout << j << " & " << h.convert(i2) << endl;
		}
	}

}
void itest()
{
	IntegerUtility m;

	Integer
		i1(Natural(5), Sign(SignValue::PLUS)),
		i2(Natural(5), Sign(SignValue::MINUS)),
		i3(Natural(0), Sign(SignValue::MINUS));

	m.printi(i1), m.printi(i2), m.printi(i3);

	m.printi(i1.add(i2));
	m.printi(i1.sub(i2));
	m.printi(i1.mul(i2));
	m.printi(i1.invert().mul(i2));

	cout << "***2***" << endl;

	Integer
		i4(Natural(5), Sign(SignValue::PLUS)),
		i5(Natural(3), Sign(SignValue::MINUS));

	m.printi(i4.add(i5));
	m.printi(i4.sub(i5));
	m.printi(i4.mul(i5));
	m.printi(i5.add(i4));
	m.printi(i5.sub(i4));
	m.printi(i5.mul(i4));

	m.printi(i1.mul(i3));
	m.printi(i2.mul(i3));
	m.printi(i3.mul(i3));
	m.printi(i4.mul(i3));
	m.printi(i5.mul(i3));
}

void stest()
{
	Sign s1(SignValue::PLUS), s2(SignValue::MINUS), s3;

	cout << s1.isPlus() << s1.isMinus() << endl;
	cout << s2.isPlus() << s2.isMinus() << endl;
	cout << s2.eq(s1) << s2.neq(s1) << endl;
	cout << s3.isPlus() << endl;
	cout << s3.invert().isPlus() << endl;
}

void ntest()
{
	Natural n1(-5), n2(20), n3;

	cout << n1.add(n2).getValue() << endl;
	cout << n1.sub(n2).getValue() << endl;
	cout << n1.mul(n2).getValue() << endl;
	cout << n3.getValue() << endl;
}