#include <future>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

#include "../_util/timer.h"

using namespace std;

vector<string> make_unique_strings(int n, string prefix = "key") {
    vector<string> v;
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
        v.push_back(prefix + to_string(i));
    }
    return v;
}

int count_common_set(vector<string> ss1, vector<string> ss2) {
    Timer timer  {"ds case " + to_string(ss1.size())};

    unordered_set<string> hashed_strings { ss2.begin(), ss2.end() };
    
    int count = 0;
    for(const string& s: ss1) {
      if(hashed_strings.contains(s)) {
        ++count;
      }
    }
    
    return count;
}

int count_common_brute(vector<string> ss1, vector<string> ss2) {
    Timer timer  {"brute case " + to_string(ss1.size())};

    int count = 0;
    for(const string& s1: ss1) {
      for(const string& s2: ss2) {
        if(s1 == s2) {
          ++count;
          break;
        }
      }
    }
    
    return count;
}

int main() {
  vector<string> s1 = make_unique_strings(10'000);
  vector<string> s2 = make_unique_strings(100'000, "abc");
  vector<string> s3 = make_unique_strings(10'000'000, "zxczxc");
  vector<string> s4 = make_unique_strings(10'000'000, "zxczxc");

  auto fut_brute = async(launch::async, [&](){ return count_common_brute(s1, s2); });
  auto fut_set = async(launch::async, [&](){ return count_common_set(s3, s4); });

  cout << fut_brute.get() << endl;
  cout << fut_set.get() << endl;

  return 0;
}