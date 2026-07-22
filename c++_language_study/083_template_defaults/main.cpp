#include <iostream>
#include <vector>

using namespace std;

//template with default argument

template <int _Idx = 0, typename _Ty = string>
void f(const _Ty& _Arr) {
    cout << _Arr[_Idx];
}

int main()
{
    f<5>("String String");
    f<>("WoW");

    int myIntArr[10]{ 777 };
    f<1, int[10]>(myIntArr);

    return 0;
}