#include <iostream>
#include <vector>

using namespace std;

void test1()
{
	string str = "this is literal";
	cout << str << " " << (void*)str.data() << endl;

	str[0] = 'T';
	cout << str << " " << (void*)str.data() << endl;

	const char* pData = str.data();

	str.append(" but it is copied");
	cout << str << " " << (void*)str.data() << endl;

	cout << pData << " " << (void*)pData << endl;
}

void test2()
{
	char* cstr = (char*)"this is literal";
	//cstr[0] = 'T'; //Exception thrown: write access violation. cstr was 0x7FF63D8AF318.
	cout << cstr << " " << (void*)cstr << endl; //00007FF630E8F318
}

int main()
{
	//test1();
	//test2();

    return 0;
}
