#include <iostream>

using namespace std;

bool band(bool a, bool b);

int main()
{
	cout << "band function" << endl;
	cout << band(true, true) << endl;
	cout << band(false, true) << endl;
	cout << band(true, false) << endl;
	cout << band(false, false) << endl;
	
	cout << "&& operator" << endl;
	cout << (true && true) << endl;
	cout << (true && false) << endl;

	return 0;
}

bool band(bool a, bool b)
{
	//1
	return a && b;

	//2
	if (a == false)
		return false;
	if (b == false)
		return false;

	return true;

	//3
	if (a == true && b == true)
		return true;
	else if (a == true && b == false)
		return false;
	else if (a == false && b == true)
		return false;
	else if (a == false && b == false)
		return false;

	//3-2
	if (a == true) {
		if (b == true)
			return true;
		else
			return false;
	}
	else
		return false;
}