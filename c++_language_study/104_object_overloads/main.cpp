#include <iostream>
#include <vector>
#include <string>
using namespace std;

// thing to test
/*
  test various conditions to find out which resolves to r-ref
  overloading for lvalue reference 
  overloading for rvalue reference 
*/

string msg;

class A
{
public:
	A() {}

	void met(A&) {
		cout << msg << " ===> met(A&)" << endl;
	}
	void met(A&&) {
		cout << msg << " ===> met(A&&)" << endl;
	}

	A& refreturn() {
		return *this;
	}

	A copreturn() {
		return *this;
	}
};

A make() {
	return {};
}

int main()
{
	A test;
	A lvalue;

	msg = "met(lvalue)";
	test.met(lvalue);

	msg = "met(make())";
	test.met(make());

	msg = "met(A{})";
	test.met(A{});

	msg = "met(lvalue.refreturn())";
	test.met(lvalue.refreturn()); // also apply to prefix increment operator and copy assignment operator

	msg = "met(lvalue.copreturn()";
	test.met(lvalue.copreturn());

	msg = "met(move(lvalue))";
	test.met(move(lvalue));

    return 0;
}