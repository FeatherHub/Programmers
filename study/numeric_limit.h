#pragma once

/*
  query properties of numeric types
  information is organized via specialization of std::numeric_limits template

  DR-LWG-201-98
  specialization for all fundamental types be provided
  -> exclude non-arithmetic types (void, pointer,..)
*/
#include <limits>
#include <iostream>

template <typename T>
class my_numeric_limits {
};

template <>
class my_numeric_limits<int> {
public: 
	static constexpr int max() {
		return 100;
	}
};

template <>
class my_numeric_limits<float> {
public:
	static constexpr float max() {
		return 500.600700f;
	}
};

void test_numeric_limits() {
	std::cout << "std int max " << std::numeric_limits<int>::max() << std::endl;
	std::cout << "my int max " << my_numeric_limits<int>::max() << std::endl;
	std::cout << "std float max " << std::numeric_limits<float>::max() << std::endl;
	std::cout << "my float max " << my_numeric_limits<float>::max() << std::endl;
}