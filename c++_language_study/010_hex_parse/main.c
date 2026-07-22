#include <stdio.h>

int htoi(const char* h);

void test2()
{
	const char set[16] =
	{ '0','1','2','3',
	  '4','5','6','7',
	  '8','9','a','b',
	  'c','d','e','f' };

	char test[5];
	int loc[4] = { 0, };

	for (;;)
	{
		for (int k = 3; k >= 1; k--)
		{
			if (loc[k] >= 16) {
				loc[k] = 0;
				loc[k - 1]++;
			}
		}

		if (loc[0] >= 16)	
			break;

		for (int i = 0; i < 4; i++)
		{
			test[i] = set[loc[i]];
		}
		test[4] = '\0';

		printf("%s %d \n", test, htoi(test));

		loc[3]++;
	}
}

void test1()
{
	const char set[16] =
	{ '0','1','2','3',
	  '4','5','6','7',
	  '8','9','a','b',
	  'c','d','e','f' };

	char test[5];

	int i, j, k, l;

	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 16; j++)
		{
			for (k = 0; k < 16; k++)
			{
				for (l = 0; l < 16; l++)
				{
					test[0] = set[i];
					test[1] = set[j];
					test[2] = set[k];
					test[3] = set[l];
					test[4] = '\0';

					printf("%s %d \n", test, htoi(test));
				}
			}
		}
	}
}
int main()
{
	test2();

	return 0;
}

int htoi(const char* h)
{
	int i;
	int num = 0;
	for (i = 0; h[i] != '\0'; ++i)
	{
		num = num * 16 + htoi2(h[i]);
	}
	return num;
}

int htoi2(const char h)
{
	if (h >= '0' && h <= '9')
		return h - '0';
	else if (h >= 'a' && h <= 'f')
		return h - 'a' + 10;
	else if (h >= 'A' && h <= 'Z')
		return h - 'A' + 10;
	else
		return -1;
}


