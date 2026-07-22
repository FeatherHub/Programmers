#include "Person.h"
#include "Address.h"

Person::Person(Address address)
{
}

Person::~Person()
{
}

Address Person::getAddress()
{
	return Address("Default", "Default");
}


void Person::setAddress(Address addr)
{
}
