#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "../util/util.h"

using namespace std;

void scratch1() {
    string s{ "hello world" };
    vector<char> v{ s.begin(), s.end() };

    cout << v << "\n";
}
