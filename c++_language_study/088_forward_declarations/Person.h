#pragma once

class Address;

class Person
{
public:
	Person(Address addr);
	~Person();
	Address getAddress();
	void setAddress(Address addr);

private:
};
