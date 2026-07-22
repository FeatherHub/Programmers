#include <stack>
#include <iostream>

using namespace std;

typedef long long int64;
typedef void(*funct)(void);

stack<void*> gstk;

template <typename T>
T pop(stack<T>& stk)
{
	T v = stk.top();
	stk.pop();
	return v;
}

void add(/*int a, int b*/)
{
	int a = (int)pop(gstk);
	int b = (int)pop(gstk);

	int r = a + b;

	gstk.push((void*)r);
	/*return r*/
}

int main()
{
	int x = 10;
	int y = 50;
	gstk.push((void*)y);
	gstk.push((void*)x);
	add();
	int z = (int)pop(gstk);
	
	cout << z << endl;

	gstk.push((void*)y);
	gstk.push((void*)x);
	gstk.push((void*)(add));
	((funct)(pop(gstk)))();
	
	z = (int)pop(gstk);
	
	cout << z << endl;


	return 0;
}