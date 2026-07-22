#include <iostream>
#include <vector>

using namespace std;

template <typename _Ty>
void f(_Ty a) {
    string _innerInfo{ typeid(_Ty).name() };

    cout << _innerInfo << endl;
}

void f(float f) {
    cout << "overload float" << endl;
}

template <>
void f(int d) {
    cout << "template<> specialization" << endl;
}

int main()
{
    f<int>(11);

    f<float>(1.1f);
    f(1.1f);

    f<string>("aaa");

    return 0;
}