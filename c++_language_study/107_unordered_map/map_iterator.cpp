#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<string, int> my_map {
    {"one", 1}, {"two", 2}, {"three", 3}
  };

  for(auto it: my_map) {
    cout << it.first << " " << it.second << endl; 
  }
   
  return 0;
}