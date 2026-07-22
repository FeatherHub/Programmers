#include <iostream>
#include <iomanip>

using namespace std;

/*
test for the result of assigning operation
test for the cast
*/

void assigntest();
void casttest();

int main()
{
//	assigntest();

	casttest();
}

void casttest()
{
	float res1 = 10 / 3;
	float res2 = (float)10 / 3;
	float res3 = 10 / (float)3;
	float res4 = float(10 / 3);
	float res5 = (float)10 / (float)3;

	cout << fixed;

	cout << res1 << endl;
	cout << res2 << endl;
	cout << res3 << endl;
	cout << res4 << endl;
	cout << res5 << endl;

	float res6 = 10 / 3 + 40 / 3;
	float res7 = (float)10 / 3 + (float)40 / 3;
	float res8 = 10 / (float)3 + 40 / (float)3;
	float res9 = (float)(10 / 3) + 40 / 3;
	float resa = 10 / 3 + float(40 / 3);

	cout << res6 << endl;
	cout << res7 << endl;
	cout << res8 << endl;
	cout << res9 << endl;
	cout << resa << endl;

	cout << "=====" << endl;

	float resb = 1 / 2 * 3 / 4;
	float resc = (float)1 / 2 * 3 / 4;
	float resd = (float)1 / 2 * (float)3 / 4;
	float rese = 1 / 2 * (float)3 / 4;
	float resf = 1 / 2 * 3 / (float)4;

	cout << resb << endl;
	cout << resc << endl;
	cout << resd << endl;
	cout << rese << endl;
	cout << resf << endl;

}

void assigntest()
{
	int b = 10;
	int m = 5;
	int s = 2;

	cout << (s < b) << endl;
	cout << (b > m > s) << endl;
	cout << (b > m && m > s) << endl;
	//left-to-right associativity
	//10 > 5 -> 1
	//1 > 2 -> 0

	int i = 5;
	int j = 0;

	cout << --(--j = --j = i) << endl;

	bool b1 = true;
	bool b2 = false;

	cout << !(b2 = b1) << endl;

	float f1 = 3.14f;
	float f2 = 5.15f;

	cout << ++(f1 = f2) << endl;
	cout << f2 << endl;

	float f3 = 3.f;
	float f4 = 4.f;

	cout << (f1 = f2)++ << endl;
	cout << f1 << endl;
	cout << f2 << endl;

	int i2 = 10;
	int i3 = 3;
//	cout << (i2 += 1) << endl;
	cout << (i3 = i2 *= i3 += 6)++ << endl;
	//Right-to-Left associativity
	// i3 += 6		9
	// i2 *= i3		90
	// i3 = i2		90
	// i3++			90
	cout << i3 << endl;
	// i3			91
}
