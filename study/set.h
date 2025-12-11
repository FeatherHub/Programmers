#pragma once

#include <set>
#include <iostream>
#include "../util/util.h"

// *** set ***
// manages unique objects of type Key
//   uniqueness is determined by using equivalence relation
//   !cmp(a,b) && !cmp(b,a)
// Sorting is done using Compare = std::lest<Key>
// Search, Removal, Insertion operations have logarithmic complexity
// usually implemented as RBT

// iterator category
// LegacyBidirectionalIterator
// ConstexprIterator (C++26)

// iterator originates from a Container
// iterator's value_type is the same as the container's value_type
// can be moved in both directions (++, --)

// iterators are a generalization of pinters
// allow a program to work with different data structures
// in a uniform manner

// duck typing (structural typing)
// each category of iterator is defined by the operations that can be performed on it
// this definitions implies that any type supporting the necessary operations can be identified as an iterator

// Iterator 
// OutputIterator, InputIterator 
// ForwardIterator, BidirectionalIterator >
// RandomAccessIterator, ContiguousIterator (C++17)
// Constexpr Iterator (C++20)


// *** multiset ***
// - sorted
// - everywhere the standard library uses the Comparer requirements
//   equivalence is determined by using !cmp(a,b) && !cmp(b,a)
// - C++11, the order of the elements that compare equivalent preserves the order of insertion

class BiIterator {
public:
	using difference_type = std::ptrdiff_t;
	using value_type = int;

	BiIterator(); // default ctor 
	BiIterator(const BiIterator&); // copy ctor
	
	BiIterator& operator=(const BiIterator&); // copy assign

	int operator*() const; // deref

	BiIterator& operator++(); // preinc
	BiIterator operator++(int); //postinc
	
	BiIterator& operator--(); // predec
	BiIterator operator--(int); //postdec

	bool operator==(const BiIterator&) const; // equality
};

static_assert(std::bidirectional_iterator<BiIterator>);

void test_set() {
	std::set<int> s{ 1,2,3,4,5 };

	std::cout << s << std::endl;

	auto insertR1 = s.insert(7);
	std::cout << *insertR1.first << " " << insertR1.second << std::endl;
	std::cout << s << std::endl;

	auto insertR2 = s.insert(7);

	std::cout << *insertR2.first << " " << insertR2.second << std::endl;
	std::cout << s << std::endl;

	auto eraseR1 = s.erase(3);
	std::cout << eraseR1 << std::endl;
	std::cout << s << std::endl;

	auto eraseR2 = s.erase(3);
	std::cout << eraseR2 << std::endl;
	std::cout << s << std::endl;
}

void test_multiset() {
	std::multiset<int> ms{ 1,1,2,2,3,3,4,4,5,5,1,1,2,2,3,1,1 };

	std::cout << ms << std::endl;

	std::cout << ms.count(1) << std::endl;
	std::cout << ms.count(2) << std::endl;
	std::cout << ms.count(11) << std::endl;

	std::set<int> s{ ms.begin(), ms.end() };

	std::cout << s << std::endl;

	auto s_eqrange = s.equal_range(1);
	auto ms_eqrange = ms.equal_range(1);

	std::cout << *s_eqrange.first << " " << *s_eqrange.second << std::endl;
	std::cout << *ms_eqrange.first << " " << *ms_eqrange.second << std::endl;
	for (auto it = ms_eqrange.first; it != ms_eqrange.second; ++it) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
}