#pragma once

class Compare
{
public:
	enum COMPARE { LT, LEQ, EQ, GEQ, GT, NEQ };

public:
	Compare();
	Compare(const COMPARE& result);
	Compare invertResult();
	COMPARE getResult();
	bool equal(Compare result);

private:
	COMPARE res;
};

class Natural
{
public:
	Natural();
	Natural(int number);
	Natural(const Natural& natural);
	int getNumber() const;
	void setNumber(unsigned number);
	Compare compare(Natural n);
	Natural add(Natural n);
	Natural sub(Natural n);
	Natural mul(Natural n);
private:
	unsigned int n;
};	