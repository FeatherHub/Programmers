#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> sides) {
  int max_side = *max_element(sides.begin(), sides.end());

  cout << "max_side: " << max_side << endl;

  int res = accumulate(sides.begin(), sides.end(), 0, [](int acc, int elem){
    cout << "acc: " << acc << " elem: " << elem << endl;
    return acc + elem;
  });

  // int max_side = *max_element(sides.begin(), sides.end());
  // int sum = accumulate(sides.begin(), sides.end(), [max_side](int side){
  //     return side == max_side ? 0 : side;        
  // }, 0);
  // return sum > max_side;

  return 0;
}

int main() {
  solution({4,5,6,7,8,9,10});
  return 0;
}