#include <iostream>
#include <string>

using namespace std;

bool is_related_to_3(int n) {
    if(n % 3 == 0) {
        return true;
    }
    
    string digits = to_string(n);
    for(char digit: digits) {
        if(digit == '3') {
            return true;
        }
    }    
    
    return false;
}

int solution(int n) {
    int i = 1;
    int j = 1;
    
    while(i <= n) {
        while(is_related_to_3(j)) {
            ++j;
        }
        ++i;
        ++j;
    }
    
    return j;
}

int main() {
  cout << solution(5) << endl;
  cout << solution(10) << endl;
  cout << solution(15) << endl;
  cout << solution(40) << endl;

  return 0;
}