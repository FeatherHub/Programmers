#include <functional>
#include <iostream>

using namespace std;


template <typename T>
void println(T v) {
    cout << v << endl;
}

template <typename RET, typename ARG1, typename ARG2>
void applier(std::function<RET(ARG1, ARG2)> func, 
    ARG1 arg1, ARG2 arg2) {
    RET res = func(arg1, arg2);
    println(res);
}

template <typename RET, typename ARG>
void applier(std::function<RET(ARG)> func, ARG arg) {
    RET res = func(arg);
    println(res);
}

int main()
{
    std::function<float(int, int)> divider =
        [](int a, int b) {
        return (float)a / b;
    };

    std::function<char(int)> intToCharMap =
        [](int c) {
        return (char)c;
    };

    applier<float, int, int>(divider, 10, 3);
    applier<char, int>(intToCharMap, 65);

    return 0;
}