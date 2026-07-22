#include "BigInt.h"

BigInt::BigInt(const char* digits)
{

}

BigInt BigInt::operator+(const BigInt& bi2)
{
	auto prevres = half_adder(_digits[0], bi2._digits[0]);

	BigInt bi3;
	bi3._digits[0] = prevres.first;

	int i, j, k;
	int opdval1, opdval2;
	bool endopd1, endopd2;
	i = j = k = 1;
	opdval1 = _digits[i]; opdval2 = _digits[j];
	endopd1 = endopd2 = false;

	while (!(endopd1 && endopd2))
	{
		auto curres = full_adder(opdval1, opdval2, prevres.second);
		bi3._digits[k] = curres.first;
		prevres = curres;

		if (_digits[i + 1] != _LAST_DIGIT_MARK) {
			i++;
			opdval1 = _digits[i + 1];
		}
		else {
			endopd1 = true;
			opdval1 = 0;
		}

		if (bi2._digits[j + 1] != _LAST_DIGIT_MARK) {
			j++;
			opdval2 = bi2._digits[j];
		}
		else {
			endopd2 = true;
			opdval2 = 0;
		}

		k++;
	}

	return bi3;
}

BigInt BigInt::operator*(const BigInt& bi2)
{
	return BigInt();
}

std::pair<int, int> BigInt::half_adder(int a, int b)
{
	return a + b >= 10 ?
		std::pair<int, int>{ a + b - 10, 1 } :
		std::pair<int, int>{ a + b, 0 };
}

std::pair<int, int> BigInt::full_adder(int a, int b, int c)
{
	return a + b + c >= 10 ?
		std::pair<int, int>{ a + b + c - 10, 1 } :
		std::pair<int, int>{ a + b + c, 0 };
}
