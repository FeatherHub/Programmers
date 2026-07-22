#include "Vector.h"
#include <iostream>

int main() 
{
	Vector<int> vec;
	
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i] = i * 10;
	}

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}

	return 0;
}