#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* thing to test
  
  various conditions which trigger move ctor & move assignment
    pass to function
	return from function
	create temporary object
*/

class A
{
public:
	A() 
	{
		log("default constructor");
	}

	A(int data) : m_data{ data } 
	{
		log("default constructor+");
	}

	~A()
	{
		log("destrcutor");
	}

	A(const A& src)
	{
		m_data = src.m_data;

		log("copy constructor");
	}

	A(A&& src) noexcept
	{
		m_data = exchange(src.m_data, 0);

		log("move constructor");
	}

	A& operator= (A&& rhs) noexcept
	{
		m_data = exchange(rhs.m_data, 0);

		log("move assigment");
	}

	void setData(int data) {
		m_data = data;
	}

	int getData() {
		return m_data;
	}

private:
	void log(string_view msg) {
		cout << m_id << " " << m_data << " " << msg << endl;
	}

	inline static int CNT = 1;
	int m_id = CNT++;
	int m_data = -1;
};

A makeTempObj()
{
	//return A{111};

	return true ? A{ 111 }
				: A{ 222 }; //to disable RVO
}

void f(A);
void g(A);

void f(A param)
{
	cout << param.getData() << endl;

	param.setData(param.getData() + 100);

	cout << param.getData() << endl;

	if (param.getData() < 300)
		g(move(param));
}

void g(A param)
{
	cout << "g is called" << endl;
	f(move(param));
}

int main()
{
	f( makeTempObj() );
    return 0;
}