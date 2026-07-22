#pragma once

#include <iostream>
using namespace std;

//things to remember
//  move constructor and move assignment operator 
//	should not throw and should be marked with 'noexcept'

class MyClass
{
public:
	MyClass() 
	{
		cout << "default constructor is called \n";
	}

	~MyClass()
	{
		//cout << "destructor is called \n";
	}

	MyClass(const MyClass& src)
	{
		cout << "copy constructor is called \n";
	}

	MyClass(MyClass&& src) noexcept
	{
		cout << "move constructor is called \n";
	}

	MyClass& operator=(const MyClass& rhs)
	{
		cout << "copy assignment operator is called \n";

		return *this;
	}

	MyClass& operator=(MyClass&& rhs) noexcept
	{
		cout << "move assignment operator is called \n";

		return *this;
	}

	MyClass operator+(const MyClass& rhs)
	{
		MyClass mc;
		mc.data = 600600;
		return mc;
	}

	static MyClass getInstance() 
	{
		MyClass mc;
		mc.data = 100100;
		return mc;
	}

	void doSomething()
	{
		cout << "do something\n";
	}

	int data;
};