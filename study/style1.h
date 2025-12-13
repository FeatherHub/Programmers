#pragma once

#include <cmath>
#include <iostream>
#include <vector>

void style1(std::vector<int> num_vec) {
  // cnt_vec[0] = count of even numbers
  // cnt_vec[1] = count of odd numbers
  std::vector<int> cnt_vec{0, 0};

  // style 1
  for (const int el : num_vec) {
    if (el % 2 == 0) {
      ++cnt_vec[0];
    } else {
      ++cnt_vec[1];
    }
  }

  // style 2
  for (const int el : num_vec) {
    const int slot = el % 2 == 0 ? 0 : 1;
    ++cnt_vec[slot];
  }

  // style 3
  for (const int el : num_vec) {
    ++cnt_vec[el % 2];
  }
}

void style1_generalization(std::vector<int> num_vec, const int d) {
  // each slot represents a count of a remainder from [0, d)
  std::vector<int> cnt_vec(std::abs(d), 0);

  for (const int el : num_vec) {
    ++cnt_vec[el % d];
  }

  for (int i = 0; i < cnt_vec.size(); ++i) {
    std::cout << i << ": " << cnt_vec[i] << std::endl;
  }
}