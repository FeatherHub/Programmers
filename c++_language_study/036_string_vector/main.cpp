#include <iostream>
#include "String.h"

using namespace std;

int main()
{
	String s1 = "Hello";

	cout << s1 << endl;
	s1.pushBack(',');
	cout << s1 << endl;
	s1.removeBack();
	s1.removeBack();
	cout << s1 << endl;
	s1.pushBack("World!");
	cout << s1 << endl;

	String s2 = "printf()";
	s1.pushBack(s2);
	cout << s1 << endl;

	for (int i = 0; i < s1.length(); i++)
	{
		cout << s1[i] << endl;
	}

	cout << s1.length();

	while (s1.length() != 0)
	{
		s1.removeBack();
		cout << s1.length();

		cout << s1 << endl;
	}

	cout << s1 << endl;
	cout << "end" << endl;

	String s3 = "aaa bbb ccc hhh eeee abcdeh";
	cout << s3 << endl;
	s3.squeeze('a');
	cout << s3 << endl;

	String s4 = "aaaaaaaaaaaa";
	cout << s4 << endl;
	s4.squeeze('a');
	cout << "after squeeze: " << s4 << endl;

	return 0;
}