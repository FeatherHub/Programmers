#include "Complex.h"
#include <iostream>

using namespace std;

void print(const Complex& c)
{	
	cout << (c.getReal() >= 0 ? '+' : '\0')
		<< c.getReal() 
		<< (c.getImag() >= 0 ? '+' : '\0')
		<< c.getImag() << "i"
		<< endl;
}

void print(...)
{
}

int main()
{
	Complex n1(3, 3);
	Complex n2 = Complex(3, 3);
	print(n1);
	print(n2);

	print(n1.add(n2));
	print(n1.mul(n2));
	print(n1.sub(n2));

	cout << n1.compare(n2) << endl;
	cout << n1.isInvert(n2) << endl;

	Complex n3 = n2;
	n3.set(-3, 666);

	print(n3);
	
	cout << n1.isRealInvert(n3) << endl;
	cout << n3.isRealInvert(n1) << endl;
	cout << n3.compare(n3) << endl;

	return 0;
}