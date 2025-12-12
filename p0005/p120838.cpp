#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<string> split(const string& s, const char delimiter) {
  vector<string> tokens;

  string token = "";
  for(const char c: s) {
    if(c == delimiter) {
      tokens.push_back(token);
      token = "";    
    } else {
      token.push_back(c);
    }
  }

  if(token.length() > 0) {
    tokens.push_back(token);
  }

  return tokens;
}

string map_morse_to_letter(const string& morse_msg) {
    static unordered_map<string, char> morse_map {
        {".-"  ,  'a'},
        {"-...",  'b'},
        {"-.-.",  'c'},
        {"-.." ,  'd'},
        {"."   ,  'e'},
        {"..-.",  'f'},
        {"--." ,  'g'},
        {"....",  'h'},
        {".."  ,  'i'},
        {".---",  'j'},
        {"-.-" ,  'k'},
        {".-..",  'l'},
        {"--"  ,  'm'},
        {"-."  , 'n'},
        {"---" ,  'o'},
        {".--.",  'p'},
        {"--.-",  'q'},
        {".-." ,  'r'},
        {"..." ,  's'},
        {"-"   ,'t'},
        {"..-" ,  'u'},
        {"...-",  'v'},
        {".--" ,  'w'},
        {"-..-",  'x'},
        {"-.--",  'y'},
        {"--..",  'z'},
    };    
    
    vector<string> morse_tokens = split(morse_msg, ' ');

    string alpha_letter = "";
    for(const string& token: morse_tokens) {
        const auto& alpha_it = morse_map.find(token);
        if(alpha_it != morse_map.end()) {
            alpha_letter.push_back((*alpha_it).second);
        }
    }
    
    return alpha_letter;
}

string solution(string morse) {
    return map_morse_to_letter(morse);
}

int main() {
    string morse_code_1 = "... --- ... ";
    string result = solution(morse_code_1);
    cout << result << endl; 
    cout << "Expected: sos" << endl;

    return 0;
}