#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "../_util/output.h"

using namespace std;

vector<int> solution_v1(int divider, vector<int> nums) {
    vector<int> divisibles;
    
    for(int num: nums) {
        if(num % divider == 0) {
            divisibles.push_back(num);
        }
    }
    
    return divisibles;
}

vector<int> solution_v2(int divider, vector<int> nums) {
    vector<int> divisibles;
    copy_if(nums.begin(), nums.end(), back_inserter(divisibles), [divider](int num){
      return num % divider == 0;
    });

    return divisibles;
}

int main() {
  cout << solution_v1(3, {0, 11,3,11,6,9,9,11}) << endl;  
  cout << solution_v2(3, {0, 11,3,6,9,9,11}) << endl;  
  return 0;
}