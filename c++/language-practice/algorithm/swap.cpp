#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int solution(vector<int> nums) {
    vector<int> _nums {nums};
     
    auto it = max_element(_nums.begin(), _nums.end());
    int max = *it;
    swap(*it, _nums.back()); 
    auto it2 = max_element(_nums.begin()  , _nums.end()-1);
    int second_max = *it2;
    
    return max * second_max;
}

int main() {
  cout << solution({1,2,3,4,5}) << endl;
  cout << solution({1,2,3,-4,-5}) << endl;
  cout << solution({5,4,3,2,1}) << endl;
  cout << solution({-5,4,-3,2,-1}) << endl;
  cout << solution({-55}) << endl;
  cout << "Case Empty: " << solution({})  << endl;

  return 0;
}