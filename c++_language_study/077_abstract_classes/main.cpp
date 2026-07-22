#include <iostream>

using namespace std;

class Movable {
public:
    virtual void move(const char* msg) = 0;
};

class Unit : public Movable {
public:
    virtual void attack(const char* msg) {
        cout << "Unit Attack\t" << msg << endl;
    }

    //pure specifier / abstract override specifier (= 0)
    //is only allowed on the virtual function
    virtual void defend(const char* msg) = 0; 
};

class Marine : public Unit {
public:
    void attack(const char* msg) override {
        cout << "Marine Attack\t" << msg << endl;
    }

    void defend(const char* msg) override {
        cout << "Marine Defend\t" << msg << endl;
    }

    void move(const char* msg) override {
        cout << "Marine Move\t" << msg << endl;
    }
};

class HeroMarine : public Marine {
public:
    void attack(const char* msg) override {
        cout << "HeroMarine Attack\t" << msg << endl;
    }

    void defend(const char* msg) override {
        cout << "HeroMarine Defend\t" << msg << endl;
    }

    void move(const char* msg) override {
        cout << "HeroMarine Move\t" << msg << endl;
    }
};


int main()
{
    //Unit* u = new Unit(); // object of abstract class, which contains pure virtual function
    
    Marine* m = new Marine(); //overrider of pure virtual function
    HeroMarine* h = new HeroMarine();

    //u->attack("unit in the unit pointer");
    m->attack("marine in its pointer");
    m->defend("marine in its pointer");
    m->move("marine in its pointer");

    h->attack("hero marine in its pointer");
    h->defend("hero marine in its pointer");
    h->move("hero marine in its pointer");

    Unit* u2 = m;
    u2->attack("marine in the unit pointer");
    u2->defend("marine in the unit pointer");
    u2->move("marine in the unit pointer");

    Marine* m2 = h;
    m2->attack("hero marine in the marine pointer");
    m2->defend("hero marine in the marine pointer");
    m2->move("hero marine in the marine pointer");

    Unit* u3 = h;
    u3->attack("hero marine in the unit pointer");
    u3->defend("hero marine in the unit pointer");
    u3->move("hero marine in the unit pointer");

    return 0;
}