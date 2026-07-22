#include <stdio.h>
#include <stdlib.h>


typedef struct Base {
	void(*cry)(void);
	int(*getLeg)(void);
	const char* (*getName)(void);
} Base;

typedef struct Derive1 {
	void(*cry)(void);
	int(*getLeg)(void);
	const char* (*getName)(void);

	const char* name;
	int leg;
} Derive1;

typedef struct Derive2 {
	void(*cry)(void);
	int(*getLeg)(void);
	const char* (*getName)(void);

	const char* name;
	int leg;
} Derive2;

void* this;

void cry$D1()
{
	printf("%p\t%s which has %d leg%s is bow-wowing \n",
		cry$D1,
		((Derive1*)this)->getName(),
		((Derive1*)this)->getLeg(),
		((Derive1*)this)->getLeg() > 1 ? "s" : ""
	);
}

const char* getName$D1()
{
	return ((Derive1*)this)->name;
}

int getLeg$D1()
{
	return ((Derive1*)this)->leg;
}

void cry$D2()
{
	printf("%p\t%s which has %d leg%s is mew-mewing \n",
		cry$D2,
		((Derive2*)this)->getName(),
		((Derive2*)this)->getLeg(),
		((Derive2*)this)->getLeg() > 1 ? "s" : ""
	);
}

const char* getName$D2()
{
	return ((Derive2*)this)->name;
}

int getLeg$D2()
{
	return ((Derive2*)this)->leg;
}

int main()
{
	Derive1* pd1 = malloc(sizeof(Derive1));
	pd1->leg = 4;
	pd1->name = "Dog001";
	pd1->cry = cry$D1;
	pd1->getName = getName$D1;
	pd1->getLeg = getLeg$D1;

	this = pd1;
	pd1->cry();

	Base* pb = pd1;
	
	this = pb;
	pb->cry();

	Derive2* pd2 = malloc(sizeof(Derive2));
	pd2->leg = 1;
	pd2->name = "Cat002";
	pd2->cry = cry$D2;
	pd2->getName = getName$D2;
	pd2->getLeg = getLeg$D2;

	this = pd2;
	pd2->cry();

	pb = pd2;
	pb->cry();

	return 0;
}