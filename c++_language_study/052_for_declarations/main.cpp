#include <iostream>
using namespace std;

int main()
{

	/* it is not allowed to declare variables with different types
	in initialization part of for loop header */

	//	for (int i = 0, char c = 'a'; i < c; i++)

	int i; char c;
	for (i = 0, c = 'a'; i < c; i++)
	{
		cout << i << endl;
	}

	char d;
	for (int j = 0, d = 'z'; j < d; j++)
	{
		cout << j << endl;
	}

	return 0;
}