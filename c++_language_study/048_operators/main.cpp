#include <iostream>

using namespace std;

/*
++ --	increment / decrement suffix
+ -		preserve / inverse prefix

+ - * / %			
& | << >>		binary arithmatic operators
+= -= *= /= %=	 
&= |= <<= >>=	

== != && ||

. , -> [] ()


*/


class Object
{
public:

	//six essential operators for a class
	//constructor
	//destructor
	//copy constructor, copy assignment
	//move constructor, move assignment

	Object operator=(const Object& c);
	
	Object operator+=(const Object& c);
	Object operator-=(const Object& c);
	Object operator*=(const Object& c);
	Object operator/=(const Object& c);
	Object operator%=(const Object& c);
	Object operator++();
	Object operator--();
	
	Object operator&=(const Object& c);
	Object operator|=(const Object& c);
	
	Object operator<<=(const Object& c);
	Object operator>>=(const Object& c);

	bool operator==(const Object& c);
	bool operator!=(const Object& c);
	bool operator>(const Object& c);
	bool operator<(const Object& c);
	bool operator>=(const Object& c);
	bool operator<=(const Object& c);
	bool operator&&(const Object& c);
	bool operator||(const Object& c);


	Object operator+(const Object& c);
	Object operator-(const Object& c);
	Object operator*(const Object& c);
	Object operator/(const Object& c);
	Object operator%(const Object& c);
	
	Object operator+(); //unary +
	Object operator-(); //unary -

	Object operator&(const Object& c);
	Object operator|(const Object& c);
	Object operator!();
	Object operator~();

	Object operator<<(const Object& c);
	Object operator>>(const Object& c);

	Object operator&(); //unary & (address of)
	Object operator->(); //member access operator 
	Object operator[](int idx);
	Object operator()();
	Object operator()(const Object& c);
	Object operator,(const Object& c);

};