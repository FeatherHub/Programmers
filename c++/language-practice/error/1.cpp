#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string solution(string s) {
    transform(s.begin(), s.end(), s.begin(), &std::tolower);
    sort(s.begin(), s.end());
    return s;
}

int main() {
  cout << solution("hello")  << endl;
  return 0;
}