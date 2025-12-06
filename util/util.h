#pragma once

#include <iostream>
#include <vector>
#include <set>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
	os << "[";
	for (size_t i = 0; i < v.size(); ++i) {
		os << v[i];
		if (i < v.size() - 1) {
			os << ", ";
		}
	}
	os << "]";
	return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
	os << "{";
	const auto lastElemIter = std::prev(std::end(s));
	for (auto i = s.begin(); i != s.end(); ++i) {
		os << *i;
		if (i != lastElemIter) {
			os << ", ";
		}
	}
	os << "}";

	return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::multiset<T>& ms) {
	os << "{";
	const auto lastElemIter = std::prev(std::end(ms));
	for (auto i = ms.begin(); i != ms.end(); ++i) {
		os << *i;
		if (i != lastElemIter) {
			os << ", ";
		}
	}
	os << "}";

	return os;
}