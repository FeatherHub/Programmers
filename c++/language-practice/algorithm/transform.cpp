#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <ostream>
#include <string>
#include <vector>
#include "../_util/output.h"

using namespace std;

// use transform when
//   the function already exists and has a name
//   e.g. transform(v.begin(), v.end(), out.begin(), std::tolower)
//
//   자기자신을 수정할 때
//   destination 관련한 요구사항을 신경쓰지 않아도 됨
//   reserve, back_inserter 등의 처리가 필요할 수 있기 때문   
//   e.g. transform(s.begin(), s.end(), s.begin(), std::lower)

//  transform 단점
//    에러발생 시점이 빌드 후
//    디버깅이 복잡해짐
//    람다에서 auto 타입추론이 약함

vector<int> get_string_lengths_1(const vector<string>& strlist) {
  vector<int> len_list;
  len_list.reserve(strlist.size());
  for(const string& s: strlist) {
    len_list.push_back(s.size());
  }
  return len_list;
}

vector<int> get_string_lengths_v2(const vector<string>& strlist) {
  vector<int> strlen_list;
  strlen_list.reserve(strlist.size());
  transform(strlist.begin(), strlist.end(), back_inserter(strlen_list), [](const string& s){
    return s.size();
  });
  return strlen_list;
}

vector<int> get_age(const map<string, int>& person_map) {
  vector<int> age_list;
  for(const auto& entry: person_map) {
    age_list.push_back(entry.second);
  }
  return age_list;
}

vector<int> get_age_v2(const map<string, int>& person_map) {
  vector<int> age_list;
  age_list.reserve(person_map.size());
  transform(person_map.begin(), person_map.end(), age_list.begin(), [&](const auto& entry){
    cout << "v2_entry: " << entry << endl;
    cout << "v2_age_list[1]: " << age_list[1] << endl;
    cout << "v2_age_list.size(): " << age_list.size() << endl;
    cout << "v2_age_list.max_size(): " << age_list.max_size() << endl;
    cout << "v2_age_list.capacity(): " << age_list.capacity() << endl;
    return entry.second;
  });

  // transform(person_map.begin(), person_map.end(), back_inserter(age_list), [](const auto& entry){
  //   return entry.second;
  // });
  
  return age_list;
}

vector<int> get_age_v3(const map<string, int>& person_map) {
  vector<int> age_list;
  transform(person_map.begin(), person_map.end(), age_list.begin(), [](const auto& entry){
    return entry.second;
  });
  return age_list;
}

int main() {
  vector<string> strlist {
    "abcd", "abc", "ab", "a", "",
  };

  cout << strlist << endl;
  cout << get_string_lengths_1(strlist) << endl;
  cout << get_string_lengths_v2(strlist) << endl;

  map<string, int> person_map {
    {"jake", 10}, 
    {"davi", 20},
    {"colli", 30},
  };

  cout << person_map << endl;
  cout << get_age(person_map) << endl;
  cout << get_age_v2(person_map) << endl;
  cout << get_age_v3(person_map) << endl;
}