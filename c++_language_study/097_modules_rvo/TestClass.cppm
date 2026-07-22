export module test_class;

import <string>;
import <format>;
import <iostream>;

using namespace std;

class MyClass {
public:
	MyClass() = delete;

	//Constructor chaining is not applied in this class
	//for the purpose of simplifying the logging task
	MyClass(const string& varName, const string& declScope, const string& curScope, const string& dstrScope)
		: m_varName(varName), m_declScope(declScope), m_curScope(curScope), m_dstrScope(dstrScope)
	{
		log("dflt ctor");
	}

	MyClass(const MyClass& src) 
		: m_varName("srcnm " + src.m_varName), m_declScope("srcscp " + src.m_declScope)
		//curScope & dstrScope should be assigned manually after construction
	{
		log("copy ctor");
	}

	MyClass(const MyClass& src, const string& varName)
		:MyClass(src, varName, src.m_declScope, "curscp unset", "dtrscp unset")
		//curScope & dstrScope should be assigned manually after construction
	{
	}

	MyClass(const MyClass& src, const string& varName, const string& declScope, const string& curScope, const string& dstrScope)
		: m_varName(varName), m_declScope(declScope), m_curScope(curScope), m_dstrScope(dstrScope)
	{
		log("aug copy ctor");
	}

	~MyClass()
	{
		log("dtor");
	}

	void setCurrentScope(const string& curScope)
	{
		m_curScope = "manset " + curScope;
	}

	void setDestroyScope(const string& dstrScope)
	{
		m_dstrScope = "manset " + dstrScope;
	}

private:
	void log(string_view method) {
		cout << format("{:>16} | {:16} ({:1}) [{:<15}{:<15}{:<15}]\n",
			method, m_varName, m_id, m_declScope, m_curScope, m_dstrScope);
	}

	string m_varName = "no name";
	string m_declScope = "dclscp unset";
	string m_curScope = "curscp unset";
	string m_dstrScope = "dtrscp unset";
	int m_id = CNT++;
	inline static int CNT = 1;
};

export class TestClass {
public:

	MyClass foo(MyClass param) {
		param.setCurrentScope(__func__);
		param.setDestroyScope(__func__);
		MyClass object2{ param, "object2", __func__, __func__, __func__};

		return true ? MyClass{ "object3", __func__, "unset", __func__}
					: MyClass{ "object3", __func__, "unset", __func__}; //to disable RVO
	}

	void test() {
		MyClass object1{"object1", __func__, __func__, __func__};

		MyClass object4 = foo(object1);

		object4.setCurrentScope(__func__);
		object4.setDestroyScope(__func__);
	}
};