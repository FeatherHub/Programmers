#include <stdio.h>


const char IDX_SYMTAB[] = 
	{'i', 'j', 'k', 'l', 
	'm', 'n', 'o', 'p'};

void generalized_for(int num, int* lims);

int main()
{
	generalized_for(4, new int[4]{ 3,3, 3, 3 });

	generalized_for(8, new int[8] { 1, 2, 3, 4, 5, 6, 7, 8 });

	return 3003;
}

void generalized_for(int num, int* lims)
{
	int* indices = new int[num] {0, };

	for (int i = 0; i < num; i++)
		printf("%d ", lims[i]);
	putchar('\n');

	int i;
	while (1) 
	{
		i = 0;
		if (indices[i] >= lims[i]) 
		{
			do 
			{
				if (indices[i] >= lims[i])
				{
					indices[i] = 0;
					indices[i + 1]++;
				}
			} while (++i < num - 1);
		}

		if (indices[num - 1] >= lims[num - 1])
			break;

		putchar('(');
		for (int j = 0; j < num; j++)
		{
			printf("%c:%d ", IDX_SYMTAB[j], indices[j]);
		}
		printf("\b)\n");

		indices[0]++;
	}
}
