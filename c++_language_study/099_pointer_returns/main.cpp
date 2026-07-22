#include <iostream>
#include <vector>

using namespace std;

/* thing to test

int* f1(int* p);
int f2(int* p);
int* f3(int p);

*/

int* f1(int* p)
{
	return p;
}

int f2(int* p)
{
	return *p;
}

int* f3(int p)
{
	return &p;
}

void test1()
{
	int a = 600;
	int* b = f1(&a);
	*b += 100;
	cout << a << endl;

	int& b2 = *f1(&a);
	b2 += 999;
	cout << a << endl;

	int c = f2(&a);
	//int* c2 = &f2(&a);
	c += 10000;
	cout << a << endl;

	int x = 7;
	int* y = f3(x);
	*y += 7777;
	cout << x  << " " << *y << endl;

	int z = *f3(x);
	z += 7777;
	cout << *y << " " << z << endl;
	cout << x << " " << *y << " " << z << endl;
	cout << y << " " << &z << endl;
}

int main()
{
	test1();


    return 0;
}