#include <iostream>
#include <vector>
#include <array>

using namespace std;

constexpr int LOEWR_BOUND = -100;
constexpr int UPPER_BOUND = 100;

class NumberCounter {
private:
    array<int, UPPER_BOUND - LOEWR_BOUND> counter {};
public:
    int& operator[](int index) {
        return counter[index-LOEWR_BOUND];
    }
};

int solution_v1(vector<vector<int>> lines) {
    NumberCounter counter;

    for(const vector<int>& line: lines) {
        for(int n = line[0]; n < line[1]; ++n) {
            ++counter[n];
        } 
    }    
    
    int overlap_len = 0;
    for(int n = LOEWR_BOUND; n < UPPER_BOUND; ++n) {
      if(counter[n] > 1) {
        ++overlap_len;
      }
    }
    
    return overlap_len;
}

int main() {
  cout << solution_v1({{1,2},{1,3},{5,6}}) << endl;
  // 1 2 3 4 5 6 
  // 1 1
  // 1 1 1
  //         1 1
  cout << solution_v1({{0,1},{2,5},{3,9}}) << endl;
  // 0 1 2 3 4 5 6 7 8 9 
  // 1 1  
  //     1 1 1 1
  //       1 1 1 1 1 1 1

  cout << solution_v1({{-100,100},{-100,100},{-100,100}}) << endl;
  cout << solution_v1({{-100,0},{0,100},{-100,100}}) << endl;
  cout << solution_v1({{-100,0},{0,1},{-100,100}}) << endl;
  cout << solution_v1({{0, 2},{-3,-1},{-2,1}}) << endl;
  // -3 -2 -1 +0 +1 +2 +3
  //           V  V  V
  //  V  V  V
  //     V  V  V  V
  //  1  2  2  2  2  1

  return 0;
}