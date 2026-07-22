/*
  https://school.programmers.co.kr/learn/courses/30/lessons/120864#
*/

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <numeric>

using namespace std;

int solution_v1(string my_string) {
    vector<int> nums;
    string digits;
    for(char c: my_string) {
        if(isdigit(c)) {
            digits += c;
        } else if(!digits.empty()) {
            nums.push_back(stoi(digits));
            digits.clear();
        }
    }
    // 잔여 데이터 처리
    if(!digits.empty()) {
        nums.push_back(stoi(digits));
    }
    
    return accumulate(nums.begin(), nums.end(), 0);
}

// sentinel 기법: 경계조건을 데이터에 추가한다.
int solution_v2(string my_string) {
    my_string += 'd'; // 경계값 추가
    vector<int> nums;
    string digits;
    for(char c: my_string) {
        if(isdigit(c)) {
            digits += c;
        } else if(!digits.empty()) {
            nums.push_back(stoi(digits));
            digits.clear();
        }
    }
    
    return accumulate(nums.begin(), nums.end(), 0);
}

// 적극적으로 consume 하는 방식 (lookahead 방식)
// vector 사용하지 않음
// index 조작부를 일관성있게 변경
int solution_v3(string s) {
    int sum = 0;
    string digits;
    int i = 0;
    while(i < s.size()) {
      if(isdigit(s[i])) {
         while(i < s.size() && isdigit(s[i])) {
          digits += s[i];
          ++i;
         }
         sum += stoi(digits);
         digits.clear();
      } else {
        ++i;
      }
    }

    return sum;
}

// 함수 호출 1회 = digits 인스턴스 생명주기 1개 
int parse_number(const string& s, int& i) {
  string digits;
  
  while(i < s.size() && isdigit(s[i])) {
    digits += s[i];
    ++i;
  }

  return stoi(digits);
}

// consume 부분을 함수로 분리
//   digits가 본문에서 하위함수로 사라진다
//     이 상태가 루프의 모든 구간에서 필요한지
//     아니면 특정 구간에서만 필요한지 질문한다
int solution_v4(string s) {
    int sum = 0;

    int i = 0;
    while(i < s.size()) {
      if(isdigit(s[i])) {
         sum += parse_number(s, i);
      }
      else {
        ++i;
      }
    }

    return sum;
}

int main() {
  cout << solution_v4("11aa11") << endl;
  cout << solution_v4("aa22aa11aa") << endl;
  cout << solution_v4("1a1a1a") << endl;
  cout << solution_v4("1a1a1a1") << endl;
  cout << solution_v4("a1111aa1a1a") << endl;

  return 0;
}
