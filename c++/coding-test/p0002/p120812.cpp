#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "../util/util.h"
#include <utility>

using namespace std;

// input
//   an array of non-negative integers
//   size > 0
// output
//   the mode of an array 
//   or -1 if there are more than one mode

int solution(const vector<int> array) {
	// handle special case
	if (array.size() == 1) {
		return array[0];
	}

	// build a map of number -> count
	unordered_map<int, int> cnt_map{};
	for (int el : array) {
		++cnt_map[el]; //note. [] default-initializes for new keys
	}

	// build a vector of pair<count, number>
	vector<pair<int, int>> v;
	for (auto el : cnt_map) {
		v.push_back({el.second, el.first});
	}

	// sort the vector desc on the first
	sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first;  });

	// return -1 if there are more than one mode 
	// otherwise return the mode 
	const pair<int, int> cnt_mode = v[0];
	if (v.size() > 1 && v[1].first == cnt_mode.first) {
		return -1;
	}
	else {
		return cnt_mode.second;
	}
}

int main() {
	const vector<int> test1{ 2, 1, 3, 1, 4, 1 };
	cout << test1 << "\t\t" << solution(test1) << endl;

	const vector<int> test2{ 2, 1, 3, 1, 4, 1, 2, 2 };
	cout << test2 << "\t\t" << solution(test2) << endl;

	const vector<int> test3{ 1 };
	cout << test3 << "\t\t" << solution(test3) << endl;

	const vector<int> test4{ 1, 1 };
	cout << test4 << "\t\t" << solution(test4) << endl;

	const vector<int> test5{ 1, 2 };
	cout << test5 << "\t\t" << solution(test5) << endl;

	const vector<int> test6{ 1, 2, 3 };
	cout << test6 << "\t\t" << solution(test6) << endl;

	const vector<int> test7{ 77, 1, 2, 3, 77, 77 };
	cout << test7 << "\t\t" << solution(test7) << endl;

	return 0;
}