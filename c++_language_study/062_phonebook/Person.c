#include "Person.h"
#include <stdio.h>

void PrintPerson(const Person* p)
{
	printf("name: %s phone number: %s", p->name, p->phone);
}
