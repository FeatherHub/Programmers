#pragma once

#include <algorithm>
#include <functional>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

inline vector<int> solution(vector<int> emergency) {
  vector<int> emergency_sorted { emergency }; // sorted desc
  sort(emergency_sorted.begin(), emergency_sorted.end(), greater<int>());

  vector<int> emergency_priority(emergency.size()); // reserve for size() elements
  for (int i = 0; i < emergency.size(); ++i) {
    for (int j = 0; j < emergency_sorted.size(); ++j) {
      if (emergency[i] == emergency_sorted[j]) {
        emergency_priority[i] = j + 1;
      }
    }
  }

  return emergency_priority;
}

inline vector<int> map_to_ranks(const vector<int>& vals) {
  // extract unique val and order by desc
  set<int, greater<int>> vals_unique_desc(vals.begin(), vals.end());

  // build val -> ranking map
  unordered_map<int, int> rank_map;
  int rank = 1; // counts from 1
  for (int val : vals_unique_desc) {
    rank_map[val] = rank;
    ++rank;
  }

  // map vals to ranks
  vector<int> ranks(vals.size());
  transform(vals.begin(), vals.end(), ranks.begin(), [&rank_map](int val) {
    return rank_map[val];
  });

  return ranks;
}