#include <iostream>
#include <vector>

using namespace std;

/* thing to test

Class& operator=(const Class& rhs);
f(Class& object);

Class obj1, obj2;
f(obj1 = obj2);
f(temp object);

*/

int& refreturn(int& p)
{
	return p;
}

int& refreturn2(int& p)
{
	int lv = 100100;
	return lv;
}

int valreturn(int& p)
{
	return p;
}

int main()
{
	int a = 100;

	int b = refreturn(a);
	b += 100;
	cout << a << endl;

	int& c = refreturn(a);
	c += 1000;
	cout << a << endl;

	int x = 5500;

	int y = valreturn(x);
	y += 100;
	cout << x << endl;

	//int& z1 = valreturn(x);
	//int& z2 = ref(valreturn(x));

	int p = 700700;
	int& q = p;
	int& r = q;

	p += 400400;
	cout << r << endl;

    return 0;
}