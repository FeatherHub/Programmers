#pragma once

#include <chrono>
#include <iostream>
#include <ratio>
#include <string>
class Timer {
public:
  Timer(std::string title): title(title) {
    start = std::chrono::high_resolution_clock::now();
  }
  ~Timer() {
    auto end = std::chrono::high_resolution_clock::now();
    auto interval = std::chrono::duration_cast<std::chrono::milliseconds>(end -start);

    std::cout << title << ": " << interval << std::endl;
  }
private:
  std::chrono::time_point<std::chrono::steady_clock> start;
  std::string title;
};