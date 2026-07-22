#include <iostream>
using namespace std;

int stack = -1;

int main();

void push(int n) { stack = n; }
int pop() { return stack; }

void call1() { cout << "call1 executed and terminating" << endl; main(); }
void call2() { cout << "call2 executed and terminating" << endl; main(); }

enum return_address$main {
	$call1, $call2
};

int main()
{
	cout << "main first line" << endl;
	int function_return_address = pop();
	int local_variables = pop();
	int result1 = pop();
	int result2 = pop();

	switch (function_return_address)
	{
	case return_address$main::$call1: 
		goto return_address$call1;
	case return_address$main::$call2:
		goto return_address$call2;
	}

	push(return_address$main::$call1);
	cout << "call1" << endl;
	call1();
	return 0;
return_address$call1:
	cout << "return from call1" << endl;
	result1 = pop();

	push(return_address$main::$call2);
	cout << "call2" << endl;
	call2();
	return 0;
return_address$call2:
	cout << "return from call2" << endl;
	result2 = pop();

	result1 += result2; //result1 must be valid 

	cout << "main last line" << endl;
	return 0;
}