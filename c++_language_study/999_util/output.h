#pragma once

#include <format>
#include <iostream>
#include <map>
#include <ostream>
#include <string>
#include <type_traits>
#include <utility>


template <typename C>
std::enable_if_t<
  !std::is_same_v<C, std::string> &&
  !std::is_convertible_v<C, const char*>, 
std::ostream&> operator<<(std::ostream& os, const C& container) {
  using namespace std;
  
  using value_type = typename C::value_type;

  os << "[";
  bool first = true;
  for(const auto& elem: container) {
    if(!first) {
      os << ", ";
    }
    os << elem;
    first = false;
  }
  os << "]";

  os << std::format(" ({})", container.size());

  return os;
}

template<typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::map<K, V> Map) {
  using namespace std;

  os << "[";
  bool first = true;
  for(const auto& pair: Map) {
    if(!first) {
      os << ", ";
    }
    os << std::format("({},{})", pair.first, pair.second);
    first = false;
  }
  os << "]";

  os << std::format(" ({})", Map.size());

  return os;
}

template<typename Ty1, typename Ty2>
std::ostream& operator<<(std::ostream& os, const std::pair<Ty1, Ty2>& Pair) {
  os << std::format("({}, {})", Pair.first, Pair.second);

  return os;
}