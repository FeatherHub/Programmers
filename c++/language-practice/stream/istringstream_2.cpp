
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../_util/output.h"

using namespace std;


vector<string> solution(vector<string> equations) {
    vector<string> marks;
    marks.reserve(equations.size());

    istringstream iss;
    for(const string& equation: equations) {
      iss.clear();
      iss.str(equation);

      int a;
      int b;
      char op;
      char eq;
      int c;

      iss >> a >> op >> b >> eq >> c;

      int answer = (op == '+') ? a + b : a - b;
      string mark = (answer == c) ? "O" : "X";
      marks.push_back(mark);
    }
    
    return marks;
}

vector<string> solution_v2(vector<string> equations) {
    vector<string> marks;
    marks.reserve(equations.size());

    for(const string& equation: equations) {
      istringstream iss {equation};

      int a, b, c;
      char op, eq;
      iss >> a >> op >> b >> eq >> c;

      int answer = (op == '+') ? a + b : a - b;
      marks.push_back((answer == c) ? "O" : "X");
    }
    
    return marks;
}

/*
  solution_v3
*/
struct Equation {
  int a, b, result;
  char op;
};
Equation parse(const string& equation_str) {
  istringstream iss { equation_str };

  Equation eq;
  char equal;
  iss >> eq.a >> eq.op >> eq.b >> equal >> eq.result; 

  return eq;
}

// batch produce vs. stream produce
vector<Equation> produce(const vector<string>& equation_strs) {
  vector<Equation> equations (equation_strs.size());
  transform(equation_strs.begin(), equation_strs.end(), equations.begin(), &parse);
  return equations;
}

bool test(const Equation& eq) {
  int answer = eq.op == '+' ? eq.a + eq.b : eq.a - eq.b;
  return answer == eq.result;
}

// batched input vs streamed input
vector<string> pipe(const vector<Equation>& equations) {
  vector<string> marks;
  marks.reserve(equations.size());

  for(const Equation& equation: equations) {
    marks.push_back(test(equation) ? "O" :"X");
  }

  return marks;
}

void orchestrate(const vector<string>& equation_strs) {
  vector<Equation> equations = produce(equation_strs);
  vector<string> marks = pipe(equations);
 
  // consume
  cout << marks << endl;
}

int main() {
  // reserve vs vector (10)

  vector<int> v1 (5);
  cout << v1 << endl;
  cout << v1.capacity() << " " << v1.size() << endl;
  v1.push_back(99);
  cout << v1 << endl;
  cout << v1.capacity() << " " << v1.size() << endl;

  cout << "=== === ===" << endl;

  vector<int> v2;
  cout << v2 << endl;
  cout << v2.capacity() << " " << v2.size() << endl;
  v2.reserve(10);
  cout << v2.capacity() << " " << v2.size() << endl;
  v2.push_back(77);
  cout << v2 << endl;
  cout << v2.capacity() << " " << v2.size() << endl;

  return 0;
}