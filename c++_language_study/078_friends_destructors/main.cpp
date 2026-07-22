#include <iostream>

using namespace std;

#define PRILINE cout << "LINE: " << __LINE__ << endl

class FreeClass {
public:
    int* pi;
    int* arr;

    ~FreeClass() {
        static int callCnt = 0;
        PRILINE;
        cout << "one: " << ++callCnt << endl;
        if (pi) {
            cout << "two:\t\t";
            cout << *pi << endl;
            delete[] pi;
            //delete pi
            cout << "after two:\t";
            cout << *pi << endl;
            pi = nullptr;
        }
        if (arr) {
            cout << "three:\t\t";
            cout << *arr << endl;
            delete[] arr;
            cout << "after three:\t";
            cout << *arr << endl;
            arr = nullptr;
        }
    }

    void allocpi(int val) {
        pi = new int[1];
        //pi = new int;
        *pi = val;
    }

    void allocArr(const initializer_list<int>& initList) {
        arr = new int[initList.size()];
        int i = 0;
        for (const int& e : initList) {
            arr[i++] = e;
        }
        arr[i - 1] = -1;
    }

    void printPi() {
        cout << *pi << endl;
    }

    void printArr() {
        for (int i = 0; arr[i] != -1; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    initializer_list<int> init_list = { 1,23,4,5,6,7,8,54 };

    FreeClass c;

    c.allocpi(500);
    c.allocArr(init_list);

    c.printPi();
    c.printArr();

    c.~FreeClass();

    cout << "four" << endl;

    cout << "pointer to integer: " << c.pi << endl;
    cout << "arr: " << c.arr << endl;

    return 0;
}

class Class2;

class Class1 {
public:
    void intervene(Class2& c2);
    void intervene2(Class2 c2);
    void intervene3(Class2 c2);
};

class Class2 {
public:
    void printSelf();
    friend void Class1::intervene(Class2&);
    friend void Class1::intervene2(Class2);
private:
    int data1;
    string data2;
};

void Class1::intervene(Class2& c2) {
    c2.data1 = 100;
    c2.data2 = "John";
}

void Class1::intervene2(Class2 c2) {
    c2.data1 = 600600;
    c2.data2 = "Ultraling";
    c2.printSelf();
}

void Class1::intervene3(Class2 c2) {
    c2.printSelf();
}

void Class2::printSelf() {
    cout << data1 << data2 << endl;
}

int main3()
{
    Class1 c1;
    Class2 c2;
    Class2 c23;
    
    c1.intervene(c2);
    c2.printSelf();

    c1.intervene2(c23);
    c23.printSelf();

    c1.intervene3(c23);

    string str;
    cout << str << endl;

    return 0;
}

class C {
public:
    friend void Func();
    friend void operator+(C&);
    friend void operator+(C&, const char*);
    friend void operator+(C&, C&);
    
private:
    int _d;
};

void Func() {
    C c; 
    c._d = 10;
    cout << c._d << endl;
}

void Func2() { // Func2 is not a friend of C
    C c;
    //c._d = 50; //member c._d is inaccessible
}

void operator+(C& c) {
    c._d = 5050;
    cout << c._d << endl;
}

void operator+(C& c, const char* m) {
    c._d = 900999;
    cout << c._d << " " << m << endl;
}

void operator+(C& c1, C& c2) {
    c1._d = 100010;
    c2._d = 700070;
    cout << c1._d + c2._d << endl;
}

int main2()
{
    Func();
    C c, c2;
    operator+(c);
    operator+(c, "wow");
    c + c2;
    +c;
    //+c("hello");
    c + "hello";

    return 0;
}