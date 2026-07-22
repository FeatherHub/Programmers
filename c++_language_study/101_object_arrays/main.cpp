#include <iostream>
#include <vector>

using namespace std;

class A
{
public:
	A() 
	{
		cout << "constructor is called" << endl;
	}

};

class B
{
public:
	B() = delete;
	B(int a) {

	}
};

void test1()
{
	A arr[10];

	cout << endl << endl << endl;

	new A[20];
}

void test2()
{
	B b{ 100 };
	//B arr[10]; //attempting to reference a deleted function
}

int main()
{
	test1(); 
	//test2();
    return 0;
}