#include <functional>
#include <iostream>

using namespace std;

template <typename RET, typename... ARGS>
void applier(function<RET(ARGS...)> func, ARGS... args) {
    RET res = func(args...);
    cout << res << endl;
}

template <typename T1, typename T2>
void applier2(function<T1(T2)> func, T2 arg) {
    auto res = func(arg);
    cout << res << endl;
}

template <typename... Args>
int MultiplyAll(Args... args) {
    return (args * ...);
}

int main()
{
    cout << MultiplyAll(67.4f, 2, 3, 4, 5) << endl;

    function<int(int, int, int)> func1 =
        [](int a, int b, int c)->int {
        return a * b * c;
    };

    function<float(float)> func2 =
        [](float a) -> float{ 
        return a * a;
    };

    applier(func1, (int)2.5f, 2, 3);
    applier2(func2, 3.14f);
    //applier(MultiplyAll, 1, 2, 3, 4, 5);

    return 0;
}