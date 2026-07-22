#include <stdio.h>
#include "Draw.h"

const int SIDE_LEN = 30;
const bool LEFT_ALIGNED = true;
const bool ASCENDING = true;

void exaustiveTest();
void miniTest();

int main()
{
	exaustiveTest();

	return 0;
}

void exaustiveTest()
{
	int** arr = new int* [SIDE_LEN];
	for (int i = 0; i < SIDE_LEN; i++)
	{
		arr[i] = new int[SIDE_LEN];
	}

	for (int i = 0; i < SIDE_LEN; i++)
	{
		for (int j = 0; j < SIDE_LEN; j++)
		{
			arr[i][j] = ' ';
		}
	}

	int mask = 0;
	for (int i = 0; i < 256; i++)
	{
		Draw((int**)arr, SIDE_LEN, 1, mask & 1, mask & 2);
		Draw((int**)arr, SIDE_LEN, 2, mask & 4, mask & 8);
		Draw((int**)arr, SIDE_LEN, 3, mask & 16, mask & 32);
		Draw((int**)arr, SIDE_LEN, 4, mask & 64, mask & 128);

		for (int i = 0; i < SIDE_LEN; i++)
		{
			for (int j = 0; j < SIDE_LEN; j++)
			{
				printf("%c", arr[i][j]);
			}
			printf("\n");
		}

		for (int i = 0; i < SIDE_LEN; i++)
		{
			for (int j = 0; j < SIDE_LEN; j++)
			{
				arr[i][j] = ' ';
			}
		}
		printf("===========NEXT===========\n");
		mask++;
	}

	printf("\n\n==================PROC END==================\n\n");

	for (int i = 0; i < SIDE_LEN; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	printf("\n\n===========DEALLOC END===========\n\n");
}

void miniTest()
{
	int** arr = new int* [SIDE_LEN];
	for (int i = 0; i < SIDE_LEN; i++)
	{
		arr[i] = new int[SIDE_LEN];
	}

	for (int i = 0; i < SIDE_LEN; i++)
	{
		for (int j = 0; j < SIDE_LEN; j++)
		{
			arr[i][j] = ' ';
		}
	}

	Draw((int**)arr, SIDE_LEN, 1, LEFT_ALIGNED, ASCENDING);
	Draw((int**)arr, SIDE_LEN, 2, !LEFT_ALIGNED, ASCENDING);
	Draw((int**)arr, SIDE_LEN, 3, !LEFT_ALIGNED, !ASCENDING);
	Draw((int**)arr, SIDE_LEN, 4, LEFT_ALIGNED, !ASCENDING);

	for (int i = 0; i < SIDE_LEN; i++)
	{
		for (int j = 0; j < SIDE_LEN; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < SIDE_LEN; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
