
#include <string>
#include <unordered_set>

using namespace std;

string remove_dup_v1(const std::string& s) {
  unordered_set<char> seen;
  string out;

  for(char c: s) {
    if(seen.insert(c).second) {
      out.push_back(c);
    }
  }

  return out;
}

int main() {

  return 0;
}