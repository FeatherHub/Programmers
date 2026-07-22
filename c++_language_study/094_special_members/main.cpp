#include "MyClass.h"

//relation between RVO and move forwarding
void moveTest()
{
	//MyClass mc1;
	//MyClass mc2 = MyClass(std::move(mc1));
	
	//MyClass mc3;
	//mc3 = MyClass::getInstance();

	//MyClass mc4{ MyClass() };
	//MyClass mc5;
	//mc5 = mc4;
	
	MyClass mc6{ move(MyClass::getInstance()) };
	cout << mc6.data << endl;
	MyClass mc7{ MyClass::getInstance() };
	cout << mc7.data << endl;
}

void copyTest()
{
	MyClass mc1;
	MyClass mc2{ mc1 }; //call copy constructor
	MyClass mc3;
	mc3 = mc2; //call copy assignment operator
}

void moveTestTwo()
{
	//MyClass mc1;
	//mc1 = move(MyClass::getInstance()); //call move assignment operator

	//MyClass mc2, mc3;
	//MyClass mc4 = mc2 + mc3; //why is the move constructor not called?
	//cout << mc4.data << endl;

	//MyClass mc5, mc6, mc7;
	//mc7 = mc5 + mc6; //move assignment operator is called
}

int main()
{
	//MyClass mc1;		//use default constructor
	//MyClass mc2(mc1);	//use copy constructor
	//MyClass mc3(MyClass());	//create temporary object
							//call move constructor

	//copyTest();
	//moveTest();
	moveTestTwo();

    return 0;
}