#include <iostream>
#include <chrono>

using namespace std;


/* 133 Obj
measure the performance difference
between copy and move
*/
class Main133 {
public:
    template <typename Runnable>
    static long long MeasureTime(Runnable codeToExecute) {
        chrono::steady_clock::time_point t1
            = chrono::high_resolution_clock::now();

        codeToExecute();

        chrono::steady_clock::time_point t2
            = chrono::high_resolution_clock::now();

        return chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
    }
};


int produceReturnCopy(int i) {
    return i + 1;
}

int&& produceReturnMove(int i) {
    return move(i + 1);
} 

string produceObjReturnCopy() {
    return string("data")+"x";
}

string&& produceObjReturnMove() {
    return move(string("data")+"x");
}

int main()
{
#define DATA_SIZE 5'000'000

    int* destBuf = new int[DATA_SIZE];

    long long copyTime = Main133::MeasureTime([&]() {
        for (long long i = 0; i < DATA_SIZE; i++) {
            destBuf[i] = produceReturnCopy(i);
        }
    });

    cout << DATA_SIZE << endl;
    cout << "primData, copy: " << copyTime << endl;

    long long moveTime = Main133::MeasureTime([&]() {
        for (long long i = 0; i < DATA_SIZE; i++) {
            destBuf[i] = move(produceReturnMove(i));
        }
    });

    cout << "primData, move: " << moveTime << endl;

    string* destBuf2 = new string[DATA_SIZE];

    long long copyObjectTime = Main133::MeasureTime([&]() {
        for (long long i = 0; i < DATA_SIZE; i++)
        {
            destBuf2[i] = produceObjReturnCopy();
        }
    });

    cout << "objData, copy: " << copyObjectTime << endl;

    long long moveObjectTime = Main133::MeasureTime([&]() {
        for (long long i = 0; i < DATA_SIZE; i++)
        {
            destBuf2[i] = move(produceObjReturnMove());
        }
    });

    cout << "moveObjectTime: " << moveObjectTime << endl;

    cout << "Done" << endl;

    return 0;
}

class Main132 {
public:
    Main132& operator=(Main132&& other) noexcept {
        d = move(other.d);
        f = move(other.f);
        s = move(other.s);
        
        cout << "move assignment operator" << endl;

        return *this;
    }

    int d;
    float f;
    string s;

    void p(const char* m = "") {
        cout << m << "\t" << s << "\t\t" << d << "\t" << f << endl;
    }
};

int main132()
{
    Main132 m1;
    Main132 m2;

    //? primitive values are kept
    m1.d = 2100000000; m1.f = 18000000000000000000;
    //? objects are not kept in moving
    m1.s = "STR_VAL";

    m1.p("m1");
    m2.p("m2");

    m2 = move(m1);

    m1.p("m1");
    m2.p("m2");

    return 0;
}

/* signature and typical usage of special methods
 copy constructor
    (const TYPE& other) 
    { v = other.v; }
 
 move constructor
    (TYPE&& other) 
    { v = move(other.v); }
 
 copy assignment
    TYPE& operator=(const TYPE& other)
    { v = other.v; 
      return *this; }

 move assignment
    TYPE& operator=(TYPE&& other)
    { v = move(other.v);
      return *this; }
 */

class main6$C {
public:
    //ret type req: none
    //param type req: one and only one allowed
    void* operator=(main6$C* other) {
        s = other->s + " (copied)";
        n = other->n * 100;
        f = other->f * -1;

        cout << this << " copy assignment operator (TYPE*)" << endl;

        return (void*)nullptr;
    }

    //standard signature
    main6$C& operator=(const main6$C& other) {
        s = other.s;
        n = other.n;
        f = other.f;

        cout << this << " copy assignment operator (TYPE&)" << endl;
        
        return *this;
    }

    string s;
    int n;
    float f;

    void p(const char* msg = "") {
        cout << msg << " " 
            << s 
            << " " << n << " " << f << endl;
    }
};

int main6()
{
    main6$C c;
    c.s = "original string";
    c.n = 65536;
    c.f = 216;

    c.p("c");

    main6$C c2;
    c2 = &c;

    c2.p("c2");

    main6$C c3;
    c3.operator=(c);

    c3.p("c3");

    return 0;
}

class main5$C {
public:
    main5$C() = default;

    //copy consturctor
    main5$C(const main5$C& other) {
        //(main5$C& other) { //also recognized

        n = other.n;
        m = other.m;
        s = other.s;
        
        cout << "copy constructor" << endl;
    }

    //move constructor
    main5$C(main5$C&& other) noexcept {
        //(const main5$C&& other) {
        //don't use move on const variable 
        n = move(other.n);
        m = move(other.m);
        s = move(other.s);

        cout << "move constructor\n";
    }

    void checkStatus(const char* id) {
        cout << id << " " << n << " " << m  << " " 
            << ((s.empty()) ? "EMPTY" : s) << endl;
    }

    int n;
    float m;
    string s;
};

int main5()
{
    main5$C c1;
    c1.n = 10;
    c1.m = 3.1415f;
    c1.s = "MOVE FROM c1 TO c2";

    main5$C c2 = move(c1);
    
    //c1 is left with garbage value 
    c1.checkStatus("c1");
    c2.checkStatus("c2");

    main5$C c3 = c1;

    c1.checkStatus("c1");
    c3.checkStatus("c3");

    main5$C c4;
    c4.n = 9950;
    c4.m = 4.294967296f;
    c4.s = "COPY FROM c4 to c5";

    main5$C c5 = c4;

    c4.checkStatus("c4");
    c5.checkStatus("c5");

    main5$C c6 = move(c5);

    //c5 is left with garbage value
    c5.checkStatus("c5");
    c6.checkStatus("c6");

    return 0;
}

class main4$C {
public:
    main4$C() {
        cout << this << " constructor\n";
        p = new int;  *p = 88888;
    }
    ~main4$C() {
        cout << this << " destructor\n";
        delete p;
    }
    main4$C* toThis() { return this; }
    int* p;
};


main4$C m4f1() {
    main4$C c;
    cout << &c << " in f()\n";
    return c;
}

main4$C& m4f2() {
    main4$C c;
    cout << &c << " in f2()\n";
    return c;
}

int main4()
{
    //cout << m4f1().toThis() << " f1 in main()\n";
    //auto& c = m4f2(); cout << &c << " " << *c.p << " f2 in main()\n";
    return 0;
}

class main3$C {
public:
    void printMe(main3$C* c) {
        cout << c << "\t" << this << endl;
    }

    void printMe2(main3$C& c) {
        cout << &c << "\t" << this << endl;
    }

    void printMe3(main3$C c) {
        cout << &c << "\t" << this << endl;
    }

    void printMe4(main3$C&& c) {
        cout << &c << "\t" << this << endl;
        
        main3$C mc = move(c);
        cout << &mc << "\t" << this << endl;
    }
};

int main3()
{
    main3$C c3;
    cout << &c3 << "\t";
    c3.printMe(&c3);

    c3.printMe2(c3);

    c3.printMe3(c3);

    c3.printMe4(main3$C());

    return 0;
}

#define M2_PRINFO(V, ACC) \
    cout << "address of pointer\tvalue of pointer\tdereference of pointer\tid of this object\n"; \
    cout << &V ## ACC p << "\t" << V ## ACC p << "\t" << *V ## ACC p << "\t\t\t" << V ## ACC id << endl;

#define M2_PRLINE \
    cout << "==-== --=-- ==-== --=-- ==-== --=-- ==-== --=-- ==-== --=-- ==-== --=--\n";

class main2$C {
public:
    static int cnt;

    main2$C(int val) {
        p = new int;
        *p = val;
        id = cnt++;
    }

    ~main2$C() {
        cout << "\t~main2$C\n";
        M2_PRINFO(this, ->);
        M2_PRLINE

        delete p;
    }

    int id;
    int* p;
};

int main2$C::cnt = 1000;

void m$2shallowCopy(main2$C c) {
    return;
}

int main2()
{
    main2$C c{ main2$C(9900) };
    main2$C* c2{ new main2$C(-1000) };

    M2_PRINFO(c, .);
    M2_PRLINE;
    M2_PRINFO(c2, ->);
    M2_PRLINE;

//    m$2shallowCopy(c);
//    delete c2;

    return 0;
}