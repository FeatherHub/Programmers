#include <iostream>
#include <vector>

//#define NDEBUG //define macro before the assert header
//#undef NDEBUG
#include <cassert>

//static_assert(CONST_CONDITION_EXPRESSION, MESSAGE)

using namespace std;

class Test {
public:
    int member1;
};

int main()
{
    Test t1;
    t1.member1;

    int trap_value = 50050;
    int escape_value = 10010;
    int poke, cnt;
    cnt = 0;
    do
    {
        cin >> poke;
        assert(poke != trap_value && "you poked trap. bomb");
        cout << poke << endl;
    } while (poke != escape_value);

    return 0;
}

int xdiv(int n, int d) {
    assert(d != 0 && "������. ʫ����. ABC.");
    if (d == 0) return 0;

    return n / d;
}

int main2()
{
    int r = xdiv(100, 5);
    int r2 = xdiv(100, 0);

    cout << r << " " << r2 << endl;

    return 0;
}