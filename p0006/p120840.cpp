
#include <algorithm>
#include <functional>
using namespace std;

int pick_m_from_n(int n, int m) {
  using Integer = unsigned long long;

  // formula: n! / ((n-m)! * m!) = C(n, m)
  // 1. pick the bigger from (n-m) and m
  // 2. reduce n! / bigger! to P[bigger+1, n]
  //   the number of term is (n-bigger)
  // 3. interleave P[bigger+1,n] / P[smaller]
  //   purpose: prevent overflow
  //   the number of term in both numerator and denominator is the same
  //   because smaller + bigger = n

  // note
  // P[i, j] means i * (i+1) * ... * j

  const Integer bigger = max(n - m, m);
  const Integer smaller = min(n - m, m);

  greater<int>();

  Integer prod = 1;
  for (Integer i = 1; i <= smaller; ++i) {
    prod *= bigger + i;
    prod /= i;
  }

  return static_cast<int>(prod);
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
