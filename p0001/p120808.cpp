#include <vector>
#include <utility>
#include <iostream>

#include "../util/util.h"

int calcGCD(int a, int b) {
	if (a < b) {
		std::swap(a, b);
	}

	for (int i = b; i > 0; --i) {
		if (b % i == 0 && a % i == 0) {
			return i;
		}
	}

	return 1;
}

std::vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
	const int numer3 = numer1 * denom2 + numer2 * denom1;
	const int denom3 = denom1 * denom2;
	const int gcd = calcGCD(numer3, denom3);

	return { numer3 / gcd, denom3 / gcd };
}

int main() {
	auto answer = solution(1, 2, 3, 4);

	std::cout << answer << std::endl;

	return 0;
}
