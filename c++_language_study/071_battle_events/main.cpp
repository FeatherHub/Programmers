#include "Unit.h"
#include "GameManager.h"

using namespace std;

int main()
{
    Unit u1{ "Marine", 40, 6 };
    Unit u2{ "Zergling", 35, 5 };
    Unit u3{ "Reaver", 200, 100 };

    GameManager gm;

    gm.addUnit(&u1);
    gm.addUnit(&u2);
    gm.addUnit(&u3);

    while (true) {
        gm.getEvent();

        gm.processEvent();
    }

    return 0;
}