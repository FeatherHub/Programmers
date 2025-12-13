#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int pick_m_from_n(int n, int m) {
  using Integer = unsigned long long;

  // formula: n! / ((n-m)! * m!)

  vector<int> abc { n, n - m, m };
  sort(abc.begin(), abc.end(), greater<int>());
  // a = n! / bigger! = n * (n-1) ... (bigger+1)  b = smaller! asdasd zxczxcxz qweqweqwe

  // interleave multiply and divide to avoid overflow

  return 1;
  // return a / b;
}

int solution(int balls, int share) { return pick_m_from_n(balls, share); }

int main() {
  (void) solution(3, 2);
  (void) solution(5, 3);
  (void) solution(1, 1);
  (void) solution(5, 3);
  (void) solution(5, 1);
  (void) solution(6, 6);
  (void) solution(10, 9);
  (void) solution(30, 3);
  (void) solution(30, 3);
  (void) solution(30, 29);
  (void) solution(30, 25);
  (void) solution(25, 20);
  (void) solution(30, 2);
  (void) solution(30, 17);
  (void) solution(30, 15);

  return 0;
}
