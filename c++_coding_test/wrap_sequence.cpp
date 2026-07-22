#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

// v1: simulate shift using index wrapping
int solution_v1(string a, string b) {
    int len = a.size();
    for(int shift = 0; shift < len; ++shift) {
        bool match = true;
        for(int i = 0; i < len; ++i) {
            if(a[(len - shift + i) % len] != b[i]) {
                match = false;
                break;
            }
        }
        if(match) {
            return shift;
        }
    }
    return -1;
}

// v2: using rotate algorithm
int solution_v2(string a, string b) {
    if(a == b) {
      return 0;
    }

    for(int shift = 1; shift < a.size(); ++shift) {
        rotate(a.begin(), a.end()-1, a.end());
        if(a == b) {
          return shift;
        }
    }
    return -1;
}

// v3: clever
int solution_v3(string a, string b) {
    b += b;
    
    size_t pos = b.find(a); 
    return pos != string::npos ? pos : -1;
}

int main() {
  cout << solution_v1("hello", "ohell") << endl;
  cout << solution_v2("hello", "ohell") << endl;
  cout << solution_v3("hello", "ohell") << endl;
  cout << "===" << endl;

  cout << solution_v1("hello", "llohe") << endl;
  cout << solution_v2("hello", "llohe") << endl;
  cout << solution_v3("hello", "llohe") << endl;
  cout << "===" << endl;

  cout << solution_v1("abcdefg", "defgabc") << endl;
  cout << solution_v2("abcdefg", "defgabc") << endl;
  cout << solution_v3("abcdefg", "defgabc") << endl;
  cout << "===" << endl;

  return 0;
}