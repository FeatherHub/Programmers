#pragma once
#include <utility>

class BigInt
{
public:
	BigInt() {};
	BigInt(const char* digits);

	BigInt operator+(const BigInt& bi2);
	BigInt operator*(const BigInt& bi2);

private:
	std::pair<int, int> half_adder(int a, int b);
	std::pair<int, int> full_adder(int a, int b, int c);

	static const int _LAST_DIGIT_MARK = -1;
	int _digits[100];
};