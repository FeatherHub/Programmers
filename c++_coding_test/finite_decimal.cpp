#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>
#include "../../_util/output.h"

using namespace std;

class Rational {
public:
    int numer; // 분자
    int denom; // 분모
    
    Rational(int numer, int denom): numer{numer}, denom{denom} {}
    
    Rational reduce() {
        auto [min, max] = minmax(numer, denom);

        for(int i = min; i >= 1; --i) {
          if(min % i == 0 && max % i == 0) {
            return {numer / i, denom / i};
          }
        }

        return *this;
    }

    friend ostream& operator<<(ostream& os, const Rational& r) {
      os << r.numer << "/" << r.denom;
      return os;
    }
};

vector<int> factorize(int n) {
    if(n == 1) {
        return {1};
    }
    
    vector<int> factors;

    int d = 2;
    while(true) {
        while(n % d == 0) {
            factors.push_back(d);
            n /= d;
        }        
        
        ++d;
        
        if(d > n) {
            break;
        }
    }

    return factors;
}

int solution(int a, int b) {
    Rational reduced = Rational(a, b).reduce();
    vector<int> factors = factorize(reduced.denom);

    cout << reduced << endl;
    cout << factors << endl;
    cout << "===" << endl;
    for(int factor: factors) {
        if(factor != 1 && factor != 2 && factor != 5) {
            return 2;
        }
    }
    
    return 1;
}

int main() {
  solution(62, 61);
  solution(61, 60);
  solution(557, 779);
  solution(9, 3);

  return 0;
}