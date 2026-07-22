#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class person {
public:
    person(int id, char* name) {
        _id = id;
        _name = name;
    }
    ~person() {
        delete _name;
    }

    int _id;
    char* _name;
};


template <class _Ty>
_Ty* xnew(_Ty aTy) {
    _Ty* pTy = (_Ty*)malloc(sizeof(_Ty));

    memcpy(pTy, &aTy, sizeof(_Ty));
    *pTy = aTy;

    return pTy;
}

int main()
{
    vector<string>* vecStr = xnew(vector<string>());

    vector<string> vecStr2;
    vecStr2.push_back("Sam");

    vector<string>* vecStr3 = new vector<string>();
    vecStr3->push_back("Sussman");
    cout << vecStr3->back() << endl;

    vecStr->push_back("Mike");
    cout << vecStr->back() << endl;

    return 0;
}

person* createPerson() {
    char* name = new char[100] {"Smith"};
    person p0 = person(5005, name);

    cout << "name.c_str()\t\t" << (void*)name << endl;
    cout << "p0._name\t\t" << (void*)p0._name << endl;

    person* p1 = xnew(p0);

    return p1;
}

person* createPerson2() {
    char* name = new char[100] {"Mike\0"};
    person p = person(8787, name);
    person* pp = new person(p);

    cout << pp->_name << endl;

    return pp;
}
int main4()
{
    person* p = createPerson2();

    cout << p->_name << endl;

    delete p;

    return 0;
}

int main3()
{
    person* p1 = createPerson();

    cout << p1->_id << " " << p1->_name << endl;

    free(p1);
    //delete p1

    return 0;
}

person* pnew(person p) {
    person* pPerson = (person*)malloc(sizeof(person));

    if (pPerson == nullptr) {
        return nullptr;
    }

    memcpy(pPerson, &p, sizeof(person));
    memset(&p, 0, sizeof(person));

    return pPerson;
}

int main2()
{
    string* pStr = (string*)malloc(sizeof(string));
    string str2 = "Hello World";

    *pStr = str2;

    free(pStr);

    return 0;
}


