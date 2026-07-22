#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int eval_expr(const string& expr) {
    istringstream iss { expr };

    int result;
    int n;
    char op;
    
    iss >> result;
    while(iss >> op >> n) {
        if(op == '+') {
            result += n;
        } else {
            result -= n;
        }
    }
    
    return result;    
}

int main() {
  istringstream iss {"abczqw def   123 qpqp"};

  cout << iss.width() << endl;
  cout << iss.gcount() << endl;
  cout << iss.bad() << endl;

  cout << (char)iss.get() << endl;
  cout << (char)iss.get() << endl;
  // cout << iss.str() << endl;
  // cout << iss.rdbuf() << endl;
  // cout << iss.view() << endl;

  string t;
  
  iss >> t;
  cout << t << endl;

  iss >> t;
  cout << t << endl;

  iss >> t;
  cout << t << endl;

  istringstream iss2 {"32 - 50"};

  int a;
  int b;
  char op;

  iss2 >> a >> op >> b;

  cout << a << " " << op << " " << b << endl;
  cout << ((op == '+') ? (a + b) : (a - b)) << endl;

  return 0;
}
