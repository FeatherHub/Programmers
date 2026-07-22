#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string* str = (string*)malloc(sizeof(string));
    string str2 = "hello";

    char* ptmp = (char*)str;
    for (size_t i = 0; i < sizeof(string); i++)
    {
        *(ptmp + i) = 0;
    }

    cout << str->capacity() << endl;
    cout << str->size() << endl;

    cout << (long long*)str->c_str() << endl;
    cout << (long*)str->c_str() << endl;
    cout << (int*)str->c_str() << endl;
    cout << (char*)str->c_str() << endl;

    cout << str->empty() << endl;
    
    str->push_back('A');
    cout << str->at(0) << endl;

    cout << "end" << endl;

    return 0;
}

void f3() {
    throw exception("in the f3()");
}

void f2() {
    throw exception("in the f2()");
    f3();
}

void f() {
    throw exception("in the f()");
    f2();
}

int main2()
{
    try {
        f();
    } 
    catch (exception e) {
        cout << e.what() << endl;
    }
    return 0;
}