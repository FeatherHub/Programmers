#include "Solution.h"

#include <iostream>
#include <stack>


void Solution::ReverseWords(string& s)
{
	char* cstr = (char*)s.c_str();
	stack<int> blankPosStack;
	
	blankPosStack.push(-1);
	for (int i = 0; i < s.size(); i++)
	{
		if (cstr[i] == ' ')
		{
			blankPosStack.push(i);
		}
	}

	string reversedStr;
	while (blankPosStack.empty() == false)
	{
		auto posOfBlank = blankPosStack.top();
		blankPosStack.pop();

		int posOfChar = posOfBlank + 1;
		while (posOfChar < s.size() && 
			cstr[posOfChar] != ' ' &&  
			cstr[posOfChar] != '\0') 
		{
			reversedStr.push_back(cstr[posOfChar++]);
		}
		reversedStr.push_back(' ');
	}

	s.swap(reversedStr);
}