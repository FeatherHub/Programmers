#include <iostream>
#include <stdio.h>

using namespace std;

const auto n = 50;
char m[n] = { 'A', };

int main()
{
	for (char* p = m; p < m + n; p++)
	{
		cout << p << ": " << endl;
		printf("%p \n", p);
	}

	return 0;
}
