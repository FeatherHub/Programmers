/**
  https://school.programmers.co.kr/learn/courses/30/lessons/120864
*/

#include <iostream>
#include <string>
#include <vector>

#include <sstream>

using namespace std;

string join(const vector<string>& strings, const string& joiner) {
  if(strings.empty()) {
    return "";
  }

  string joined_str = strings[0];
  for(int i = 1; i < strings.size(); ++i) {
    joined_str += joiner;
    joined_str += strings[i];
  }

  return joined_str;
}

int parse_x_coeff(const string& x_token) {
  if(x_token.size() == 1) {
    return 1;
  } else {
    return stoi(x_token.substr(0, x_token.size() - 1));
  }
}

string create_x_term(int coeff) {
  if(coeff == 1) {
    return "x";
  }
  return to_string(coeff)+"x";
}

class Polynomial {
private:
  int coeff_0 = 0; // 상수의 계수
  int coeff_1 = 0; // x^1의 계수

public:
  Polynomial() = default;
  Polynomial(int coeff_1, int coeff_0): coeff_0{coeff_0}, coeff_1{coeff_1} {}

  void add_term(const string& token) {
    if(token.back() == 'x') {
      coeff_1 += parse_x_coeff(token);
    } else if(token == "+") {
      // do nothing
    } else {
      coeff_0 += stoi(token);
    }
  }

  string to_string() const {
    vector<string> coeff_strs;
    if(coeff_1 != 0) {
      coeff_strs.push_back(create_x_term(coeff_1));
    }
    if(coeff_0 != 0) {
      coeff_strs.push_back(std::to_string(coeff_0));
    }

    return join(coeff_strs, " + ");
  }
};

string solution(string polynomial_str) {
    istringstream iss {polynomial_str};

    Polynomial poly;
    string token;
    while(iss >> token) {
      poly.add_term(token);
    }

    return poly.to_string();
}

int main() {
  cout << solution("3x + 7 + x + 8") << "||END " << endl;
  cout << solution("3x + 7 + x + -7") << "||END " << endl;
  // cout << solution("-x + 7 + 2x + -7") << "||END " << endl;
  cout << solution("-2x + 7 + 2x + -7") << "||END " << endl;
  cout << solution("x") << "||END " << endl;
  
  return 0;
}