#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person(string _name, int _id) : name(_name), id(_id) 
    {}
    
    string name;
    int id;
};

Person& return_object_as_Lreference() {
    Person p("John", 10010);
    return p;
}

Person&& return_object_as_Rreference() {
    Person p("Mary", 50050);
    //return p; //Person&& cannot bind to an lvalue

    return Person("B", 77777);
}

void printPerson(const char* marker, const Person& p) {
    cout << marker << " ";
    cout << p.id << p.name << endl;
}

int main3()
{
    Person p1 = return_object_as_Lreference();
    Person& p2 = return_object_as_Lreference();
    //Person&& p3 = return_object_as_Lreference();
    Person p3 = return_object_as_Rreference();
    //Person& p4 = return_object_as_Rreference();
    Person&& p5 = return_object_as_Rreference();

    //cout << "p3: " << p3.id << p3.name << endl;
    //cout << "p5: " << p5.id << p5.name << endl;

    printPerson("p1 &->=", p1);
    printPerson("p2 &->&", p2);
    printPerson("p3 &&->=", p3);
    printPerson("p5 &&->&&", p5);

    return 0;
}

int& return_local_as_Lreference() {
    int x = 100;
    //return x+100; //it must be lvalue
    return x;
}

int&& return_local_as_Rreference() {
    int x = 100;
    //return x; //cannot bind lvalue to rvalue reference
    return x+100;
}

void printNumber(const char* marker, int n) {
    cout << marker << " " << n << endl;
}

int main2()
{
    int x1 = return_local_as_Lreference();
    int& x2 = return_local_as_Lreference();
    int y1 = return_local_as_Rreference();
    int&& y2 = return_local_as_Rreference();

    cout << x1 << endl;
    cout << x2 << endl;
    cout << y1 << endl;
    cout << y2 << endl;

    printNumber("x1", x1);
    printNumber("x2", x2);
    printNumber("y1", y1);
    printNumber("y2", y2);

    return 0;
}