#include <iostream>
#include <stdio.h>

using namespace std;

void print(int* v, const char* msg)
{
	cout << "==========" << endl;
	cout << msg << endl;
	cout << "value: " << *v << endl;
	cout << "address: " << v << endl;
	cout << "==========" << endl;
}

int& retref()
{
	int i;

	int j = 1000;
	int k = 2000;

	i = j + k;

	print(&i, "retref-i");
	print(&j, "retref-j");
	print(&k, "retref-k");

	return i;
}

int&& retrvalref()
{
	int i, j, k;
	i = 10, j = 20, k = 30;
	return (i + j) * k;
}

void reftst()
{
	int& rf1 = retref();
	print(&rf1, "main-rf1");

	int& rf2 = retref();
	print(&rf2, "main-rf2");

	rf2 -= 50000;

	print(&rf1, "main-rf1");
	print(&rf2, "main-rf2");

	//undefined behavior
	//irregular, unruled, arbitrary, random, chaotic
	for (int i = 0; i < 10; i++)
	{
		//		cout << (rf2 += 1) << endl;				 //ok
		//		cout << "...." << (rf2 += 1) << endl;	 //error
		//		printf("%d \n", rf2++);					 //error
		//		print(&(rf2 += 1), "main-for-loop-rf2"); //error
	}
}

int main()
{
	int&& a = retrvalref();
	int b = retrvalref();
	int&& c = retrvalref();

	a++;
	b--;

	cout << c << "\t|\t" << &c << endl;
	cout << b << "\t|\t" << &b << endl;
	cout << a << "\t|\t" << &a << endl;

	return 0;
}