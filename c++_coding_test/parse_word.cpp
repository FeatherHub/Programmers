#include <iostream>
#include <optional>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

long long convert_v1(const string& en_digits) {
    static const unordered_map<string, int>  dic {
        {"zero", 0},
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
    };

    string number;
    string word;
    for(char c: en_digits) {
        word.push_back(c);
        auto it = dic.find(word);
        if(it != dic.end()) {
            number.push_back(it->second);
            word.clear();
        }
    }
    
    long long result = 0LL;
    for(int i = 0; i<number.size(); ++i) {
        result += pow(10, number.size() - i - 1) * number[i];
    }
    return result;
}


// *** VERSION 2 ***
// separate tokenize logic and convert logic
// *****************

class Parser {
private:
  const unordered_map<string, int>& dic;
  const string& input;
  int cursor = 0;

public:
  Parser(const unordered_map<string, int>& dic, const string& input): dic{dic}, input{input} {}
  
  optional<int> next() {
    string word;

    while(cursor < input.size()) {
      word.push_back(input[cursor]);
      ++cursor;
      auto it = dic.find(word);
      if(it != dic.end()) {
        return it->second;
      }
    }

    return nullopt;
  }
};

static const unordered_map<string, int>  dic {
    {"zero", 0},
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9},
};

long long convert_v2(const string& en_digits) {
    Parser parser { dic, en_digits };
    long long number = 0;
    while(optional digit = parser.next()) {
      number = number * 10 + *digit;
    }

    return number;
}

int main() {
  cout << convert_v1("one") << endl;
  cout << convert_v2("one") << endl;

  cout << convert_v1("zerozeroonetwozerozero") << endl;
  cout << convert_v2("zerozeroonetwozerozero") << endl;

  cout << "end" << endl;
  return 0;
}