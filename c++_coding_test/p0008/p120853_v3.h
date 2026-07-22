#pragma once
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


// istringstream

namespace v3 {
    int solution(string s) {
        istringstream iss{ s };
        string token;
        vector<int> numbers;
        while (iss >> token) {
            if (token == "Z") {
                numbers.pop_back();
            }
            else {
                numbers.push_back(stoi(token));
            }
        }

        return accumulate(numbers.begin(), numbers.end(), 0);
    }
}