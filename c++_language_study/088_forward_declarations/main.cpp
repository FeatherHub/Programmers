#include <iostream>
#include <vector>
#include "Person.h"
#include "Address.h"

using namespace std;

int main()
{
    Address addr("US", "New York");
    Address* addr2 = new Address("Canada", "Vancouver");

    Person p1(Address("ABC", "DEF"));

    cout << p1.getAddress().getCity() << endl;

    return 0;
}