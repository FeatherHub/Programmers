#include "discount_policy.h"
#include <iostream>

int main() {
	const auto policy = discount::Policy::create_default();

	std::cout << policy.get_discount_rate(100'000) << std::endl;
	std::cout << policy.get_discount_rate(200'000) << std::endl;
	std::cout << policy.get_discount_rate(300'000) << std::endl;
	std::cout << policy.get_discount_rate(400'000) << std::endl;
	std::cout << policy.get_discount_rate(500'000) << std::endl;
	std::cout << policy.get_discount_rate(600'000) << std::endl;

	return 0;
}