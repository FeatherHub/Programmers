
#include <exception>
#include <iostream>
#include <optional>
#include <string>

using namespace std;

optional<string> create_opt(bool b) {
  if(b) {
    return "hello";
  } else {
    return nullopt;
  }
}

int main() {
  cout << *create_opt(true) << endl;
  cout << *create_opt(false) << endl;


  cout << "===" << endl;
  const optional<string> opt_res_no = create_opt(false);
  try {
    cout << opt_res_no.value() << endl; // throws
  } catch(const exception& e) {
    cout << "opt_res_no.value(): ";
    cout << e.what() << endl;
  }
  cout << opt_res_no.value_or("world") << endl;
  cout << opt_res_no.has_value() << endl;



  cout << "===" << endl;
  const auto opt_res_yes = create_opt(true);
  cout << opt_res_yes.value() << endl;
  cout << *opt_res_yes << endl;
  cout << opt_res_yes.value_or("world2") << endl;
  cout << opt_res_yes.has_value() << endl;

  return 0;
}