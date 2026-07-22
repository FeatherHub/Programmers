#include <iostream>

using namespace std;

int main()
{
	for (int* i = (int*)main; (unsigned long long)i < ULLONG_MAX; i++)
	{
		cout << i << ": ";

		for (int j = 0; j < sizeof(int*); j++)
		{
			try {
				cout << *((char*)i + j) << ", ";
			}
			catch (...) {
			}
		}

		cout << endl;
	}

	return 0;
}