#pragma once

#include <iostream>
#include <iterator>
#include <ranges>
#include <string>

// range
// any object with begin and end

// view
// non-onwing range
// just copy pointer/iterator
// composable using pipe operator
// lazy evaluation

void test_range_view() {
    std::string str{ "ABC" };

    // explicit use of iterators
    for (std::reverse_iterator<std::string::iterator> it = str.rbegin(); it != str.rend(); ++it) {
        const char c = *it;
        std::cout << c;
    }
    std::cout << std::endl;

    // range
    const auto rev_range = std::ranges::subrange(str.rbegin(), str.rend());
    for (const char c : rev_range) {
        std::cout << c;
    }
    std::cout << std::endl;
    
    // view
    const auto rev_view = std::views::reverse(str); // style1
    const auto rev_view2 = str | std::views::reverse; // style2
    const auto rev_view3 = std::ranges::subrange(str.begin(), str.end()) | std::views::reverse; // style3
    
    for (const char c : rev_view3) {
        std::cout << c;
    }
    std::cout << std::endl;

    // view - lazy evaluation
    const auto lazy_view = str | std::views::transform([](auto c) {
        std::cout << "eval " << c << std::endl;
        return c;
        });

    std::cout << "--- ---" << std::endl;

    for (const char c : lazy_view) {
        std::cout << "consume " << c << std::endl;
    }

    std::cout << std::endl;
}