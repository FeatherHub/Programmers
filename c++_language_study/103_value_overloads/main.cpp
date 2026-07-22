#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* thing to test
  test various conditions to find out which is seen as rvalue to compiler
  overloaded function that accepts an lvalue reference argument
  overloaded function that accepts an rvalue reference argument
*/

string msg;

void f(int&& param) {
	cout << msg << " ===> f(int&&)" << endl;
}

void f(int& param) {
	cout << msg << " ===> f(int&)" << endl;
}

int g() {
	return 1;
}

int main()
{
	int lvalue {};

	msg = "f(lvalue)";
	f(lvalue);

	msg = "f(1)";
	f(1);

	msg = "f(lvalue+1)";
	f(lvalue+1);

	msg = "f(g())";
	f(g());

	int lvalue2 {};

	msg = "f(lvalue + lvalue2)";
	f(lvalue + lvalue2);

	msg = "f(lvalue++)";
	f(lvalue++); //rvalue reference version is called

	msg = "f(++lvalue)";
	f(++lvalue); //lvalue reference version is called

	msg = "f(move(lvalue))";
	f(move(lvalue));

    return 0;
}