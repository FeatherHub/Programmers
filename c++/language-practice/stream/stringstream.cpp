#include <iostream>
#include <sstream>
#include <string>

// <sstream> stringstream
// ios_base <- ios <- istream, ostream <- iostream <- stringstream

// io stream that operates on strings
//   string buffer: contains a sequence of characters

// characters can be extracted(read) or inserted(write) to the stream
// using operator >> or <<

// internal state from ios_base, ios, and istream

// <sstream> istringstream
// ios_base <- ios <- istream <- istringstream

// input stream that operates on strings
// >> extraction operator
//   read until whitespace is reached or stream failure

using namespace std;
int main() {
  string s { "123   abc   goo" };
  istringstream iss {s};
  string t;

  // boolean context 
  //   condition statement, bool initialization
  bool b { iss >> t };
  //   bool conversion operator: operator bool()
  // istringstream returns false on EOF or error
  while(iss >> t) {
    cout << t << " | ";
  }

  return 0;
}