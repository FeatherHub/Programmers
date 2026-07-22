#include <iostream>
#include <vector>

using namespace std;

// list of overridable operators
// override operator++() & operator++(int)
// override operator<<()

class XState {
public:
    XState() { m_state = "one"; }

    //pre increment
    XState operator++() {

        cout << "pre" << endl;

        if (m_state == "one") {
            m_state = "two";
        } 
        else if (m_state == "two") {
            m_state = "three";
        }
        else if (m_state == "three") {
            m_state = "one";
        }

        return *this;
    }

    //post increment
    XState& operator++(int) {
        XState tmp = *this;

        cout << "post" << endl;

        if (m_state == "one") {
            m_state = "two";
        }
        else if (m_state == "two") {
            m_state = "three";
        }
        else if (m_state == "three") {
            m_state = "one";
        }

        //return tmp;
        return *this;
    }

    string m_state;
};

int main()
{
    int i = 100;
    ++i = ++i + 10;
    cout << i << endl;
    ++++++++++++++++i;
    cout << i << endl;
    cout << (++++++i)++ << endl;
    //i++ = i + 10; expression must be modifiable lvalue

    XState state;

    (++++++++state)++++++++;

    cout << endl;

    ++++++++(state++++++++);

    cout << endl;

    ++++++++state++++++++;

    return 0;
}

int main2()
{
    enum Color { RED, BLUE, GREEN };
    //enum Option {RED, BLUE, GREEN}; //redefinition: previous definition was enumerator
    Color myColor;

    myColor = Color::RED;

    Color myColor2 = RED;

    cout << myColor << endl;




    return 0;
}

enum State {ZERO, ONE, TWO, THREE};

State& operator++(State& aState) {
    cout << "preincrement" << endl;
    cout << "operator++(), operator++(Type& var)" << endl;

    aState = (State)(aState + 1);
    return aState;
}

State& operator++(State& aState, int x) {
    cout << "postincrement x?" << x << endl;
    cout << "operator++(int), operator(Type&, int)" << endl;

    State tmp = aState;
    aState = (State)(aState + 1);
    return tmp;
}

int main3()
{
    enum Color {RED, BLUE, GREEN}; //not conflict with enum Color in main2

    State aState = State::ONE;

    operator++(aState);
    ++aState;

    cout << "=== === ===" << endl;

    operator++(aState, 11011);
    aState++;

    return 0;
}

