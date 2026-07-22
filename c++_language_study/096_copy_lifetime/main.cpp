#include <iostream>
#include <vector>
#include <string>
#include <format>

using namespace std;

class MyClass {
public:
	MyClass(const string& varName, const string& currentScope)
		:MyClass(varName, "default constructor", currentScope)
	{
	}

	~MyClass() 
	{
		message("destructor");
	}

	MyClass(const MyClass& src)
		: MyClass("<no name>", "normal copy constructor", src.m_currentScope)
	{

	}

	MyClass(const MyClass& src, const string& varName, const string& currentScope) 
		: MyClass(varName, "augmented copy constructor", currentScope)
	{
	}

	MyClass(const string& varName, string_view calledMethod, string_view currentScope)
		: m_varName(varName), m_currentScope(currentScope)
	{
		message(calledMethod);
	}

	MyClass& operator=(const MyClass& src)
	{
		cout << "zxczxc";
	}

	void setDeclaredScope(const string& scope)
	{
		m_currentScope = scope;
	}

private:
	void message(string_view calledMethod)
	{
		cout << format("{:^30} -> {:10}({:1}) | {}\n", calledMethod, m_varName, m_id, m_currentScope);
	}

	int m_id = NUM++;
	string m_currentScope="<not set>";
	string m_varName="<no name>";
	inline static int NUM = 0;
};

MyClass p(MyClass param)
{
	param.setDeclaredScope(__func__);

	MyClass object2{ param, "object2", __func__ };

	return object2;
}

int main()
{
	MyClass object1{"object1", __func__};

	p(object1); // param {object1}; triggers normal copy constructor

	return 0;
}
