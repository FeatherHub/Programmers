
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

// parameter pattern
// seq - first it, last it
// knob1: v, pr (value, pred)
// knob2: p? (execution policy)

// w/wo policy
// p seq v
// p seq pr
// seq v
// seq pr

// value or *_if
// seq v
// p seq v
// seq pr
// p seq pr

// --- --- ---

// history

// C++ 17
// adds ExecutionPolicy

// C++ 20
// adds constexpr to non ExecutionPolicy overloads

// C++ 26
// adds iterator_traits<ForwardIt>::value_type

// --- --- ---

void my_remove(string& s, char v) {
  int j = 0;
  for(int i = 0; i < s.size(); ++i) {
    if(s[i] != v) {
      s[j] = s[i];
      ++j;
    }
  }
}

string::iterator my_remove(string::iterator first, string::iterator last, char v) {
  string::iterator pos = first;
  while(first != last) {
    if(*first != v) {
      *pos = *first;
      ++pos;
    }
    ++first;
  }
  return pos;
}

int main() {

  // b     [b+1              e-1)  e
  // 0     1     2     3     4     5
  // h     e     l     l     o  
  //       e     l     l
  // h                       o
  string s { "hello" };
  cout << s << endl;
  string::iterator it1 = s.erase(s.begin()+1, s.end()-1);
  cout << s << endl;
  cout << *it1 << endl;
  cout << s.size() << endl;
  cout << s.capacity() << endl;

  cout << "===" << endl;
  string s2 { "lalblcldlel" };
  //          "abcde
  //           012345
  cout << s2 << endl;
  string::iterator it2 = remove(s2.begin(), s2.end(), 'l');
  cout << s2 << endl;
  cout << *it2 << endl;
  cout << distance(s2.begin(), it2) << endl;
  cout << distance(s2.begin(), s2.begin()) << endl;

  cout << "===" << endl;
  string s3 { "lalblcldlel" };
  my_remove(s3, 'l');
  cout << s3 << endl;

  cout << "===" << endl;
  string s4 { "lalblcldlel" };
  //           0123456789A
  string::iterator it4 = remove(s4.begin()+4, s4.end(), 'l');
  cout << s4 << endl;
  cout << *it4 << endl;
  
  string s5 { "lalblcldlel" };
  string::iterator it5 = my_remove(s5.begin()+4, s5.end(), 'l');
  cout << s5 << endl;
  cout << *it5 << endl;

  cout << "===" << endl;
  return 0;
}