#pragma once

#include <numeric>
#include <iostream>
#include <concepts>

#include "../util/util.h"

template <class InputIterator, class T>
T _accumulate(InputIterator first, InputIterator last, T val) {
	while (first != last) {
		val += *first;
		++first;
	}
	return val;
}

template <typename Op, typename T>
concept Bop = requires(Op op, T a, T b) {
	{ op(a, b) } -> std::convertible_to<T>;
};

template <typename Init, typename Val, typename Op>
requires Bop<Op, Val>
Val _accumulate(Init begin, Init end, Val v, Op op) {
	while (begin != end) {
		v = op(v, *begin);
		++begin;
	}
	return v;
}


// data race: the elements in the range [first, last) are accessed exactly once
// exceptions: if any of binary_op, iterator operation throws
// undefined behavior: invalid arguments are passed

/*
  input iterator category

  - forward, bidirectional, random access iterators are all valid input iterators
  - read only once and then incremented
  - supports following operations
    - copy-constructible, copy-assignable, destructible
	- can be compared for equivalence using the equality/inequality operators
	- can be dereferenced as an rvalue (if in a dereferenceable state)
	  *a, a->m
	- lvalues are swappable 

  - std::accumulate performs a left fold
  - the accumulator is on the left side of the binary operation at each step
  - for non-commutative operations, the direction matters.
*/

void test_accumulate() {
	std::vector v{ 1,2,3,4,5 };
	int n = _accumulate(v.begin(), v.end(), 1000);
	std::cout << n << std::endl;

	int n2 = std::accumulate(v.begin(), v.end(), 3000);
	std::cout << n2 << std::endl;

	int n3 = _accumulate(v.begin(), v.end(), 5000, [](int a, int b) { 
		 std::cout << "a: " << a << " b : " << b << std::endl;

		return a + b; 
	});
	std::cout << n3 << std::endl;

	int n4 = std::accumulate(v.begin(), v.end(), 7000, [](int acc, int el) {
		std::cout << "acc: " << acc << " el: " << el << std::endl;

		return acc;
	});
	std::cout << n4 << std::endl;
}