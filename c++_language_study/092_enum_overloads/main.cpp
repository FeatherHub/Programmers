#include <iostream>
#include <vector>
#include <ranges>

using namespace std;

enum class State3 {
    One = 'z', Two = 'm', Three = 'j'
};

template<typename T>
void f() {
    char Nice1 = (double)T::One;

    cout << Nice1 << endl;

}

int main()
{
    f<State3>();

    return 0;
}

enum class State2 : char {
    One = 'a', Two, Three
};

State2& operator++(State2& state, int) {
    return state = (State2)((char)state+1);
}

ostream& operator<<(ostream& os, const State2& state)
{
//    os << state; //leads to recursion
    cout << (char)state;

    return os;
}

int main3()
{
    State2 state2 = State2::One;

    std::ranges::iota_view<int, int> col = std::views::iota(0, 50);
    for (int i : col) {
        cout << state2++ << " ";
    }

    return 0;
}

enum class State {
    One, Two, Three
};

State& operator++(State& state, int) {
    return state = (State)((int)state + 1);
}

int main2()
{
    auto stat(State::One);
    stat++; cout << (int)stat << endl;
    stat++; cout << (int)stat << endl;
    stat++; cout << (int)stat << endl;
    stat++; cout << (int)stat << endl;
    stat++; cout << (int)stat << endl;
    stat++; cout << (int)stat << endl;

    return 0;
}