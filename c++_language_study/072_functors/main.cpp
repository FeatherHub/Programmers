#include <iostream>
#include <functional>

using namespace std;

template <class _F>
class Functor {
public:
    void operator()() {
        cout << "func" << endl;
    }

    void operator()(int i) {
        for (int j = 0; j < i; j++) {
            cout << "wow" << endl;
        }
    }

};

template <class _F>
class C {
public:
    C(_F f): _f(f) {
    }

    void doit() {
        _f();
    }

    void doit(int i) {
        _f(i);
    }

private:
    _F _f;
};

int main()
{
    Functor<int> object;

    C<Functor<int>> c = C<Functor<int>>(object);
    
    c.doit();
    c.doit(5);
    int x = 100;

    auto lam1 = [=](int x)->float {
        return 200.5f;
    };

    //syntax for declaring a function pointer
    //[retType](*fpName)(paramType)
    float(*lam2)(int) = [](int x)->float {
        cout << "this is lam2: " << x << endl;
        return 3.14f;
    };

    cout << lam2(10);

    std::function<float(int, int)> func10;
    func10 = [](int x, int y)->float {
        cout << x << y << endl;
        return 3.14f;
    };
    func10.operator()(104, 205);
    func10(500, 800);

    std::function<int(int, int, int)> adder =
        [](int a, int b, int c)->int {
        return a + b + c;
    };

    cout << adder(1, 2, 3) << endl;


    return 0;
}