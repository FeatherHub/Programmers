#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


bool contain_v1(const string& s, char target) {
  for(char c: s) {
    if(c == target) {
      return true;
    }
  }
  return false;
}

bool contain_v2(const string& s, char target) {
  return find(s.begin(), s.end(), target) != s.end();
}

int count_v1(const string& s, char target) {
  int cnt = 0;
  for(char c: s) {
    if(c == target) {
      ++cnt;
    }
  }
  return cnt;
}

int count_v2(const string& s, char target) {
  return count(s.begin(), s.end(), target);
}


void test_set_1() {
  string s1 {"hello"};
  cout << contain_v1(s1, 'l') << endl;
  cout << contain_v2(s1, 'l') << endl;
  cout << "===" << endl;
  cout << contain_v1(s1, 'e') << endl;
  cout << contain_v2(s1, 'e') << endl;
  cout << "===" << endl;
  cout << contain_v1(s1, 'q') << endl;
  cout << contain_v2(s1, 'q') << endl;
  cout << "===" << endl;
  cout << "===" << endl;
  cout << "===" << endl;
  cout << count_v1(s1, 'l') << endl;
  cout << count_v2(s1, 'l') << endl;
  cout << "===" << endl;
  cout << count_v1(s1, 'o') << endl;
  cout << count_v2(s1, 'o') << endl;
  cout << "===" << endl;
  cout << count_v1(s1, 'q') << endl;
  cout << count_v2(s1, 'q') << endl;
  cout << "===" << endl;
}

void test_set_2() {
  string s {"11"};
  cout << count_v1(s, '1') << endl;
  cout << count_v2(s, '1') << endl;

}

int main() {
  test_set_2(); 
  return 0;
}