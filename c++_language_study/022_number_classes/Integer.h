#pragma once
#include "Natural.h"

class Sign
{
public:
	enum SIGN { PLUS, MINUS };

public:
	Sign();
	Sign(SIGN s);
	bool isPlus();
	bool isMinus();
	bool equal(Sign s);
	Sign mul(Sign s);
	SIGN getSign();
	Sign invertSign();
private:
	SIGN sign;
};

class Integer
{
public:
	Integer();
	Integer(int in);
	Integer(Natural q);
	Integer(int q, Sign s);
	Integer(const Integer& i);
	Integer(Natural q, Sign s);
	Natural getQuantity() const;
	Sign getSign() const;
	Integer add(Integer i);
	Integer sub(Integer i);
	Integer mul(Integer i);
	void init(Natural q, Sign s);
	bool compareSign(Integer i);
	Compare compareQuantity(Integer i);
	Compare compare(Integer i);
	Compare compare(int i);
private:
	Natural quantity;
	Sign sign;
};