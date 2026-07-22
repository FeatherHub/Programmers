#pragma once
#include "Integer.h"
#include <iostream>

using namespace std;

static class IntegerUtility
{
public:
	static char puts(Integer i) { return puts(i.getSign()); }
	static char puts(Sign s) { return s.isPlus() ? '+' : '-'; }
	static void printi(Integer i) { cout << puts(i) << i.getNatural().getValue() << endl; }
	static void puti(Integer i) { cout << puts(i) << i.getNatural().getValue(); }
	static int convert(Integer i) { return i.getNatural().getValue() * (i.getSign().isPlus() ? 1 : -1); }
	static Integer convert(int i) { return i >= 0 ? Integer(i) : Integer(-i, SignValue::MINUS); }
};