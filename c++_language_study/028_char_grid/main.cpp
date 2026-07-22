#include <iostream>
using namespace std;

void printf(int from, int to, int n, int off, const char* delim);

int main()
{
	printf('a', 'z', 4, 2, "\n\n");

	return 0;
}

void printf(int from, int to, int n, int off, const char* delim)
{
	for (int i = from; i <= to; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//remove redundant appearnace of i + j * off
			if(i + j * off <= to)
				cout << (char)(i + j * off);
		}
		cout << delim;
	}

	int i, j;
	i = from;
	j = 0;
	while (i + j * off <= to)
	{
		while (j < n)
		{
			cout << (char)(i + j * off);
		}
	}



}
