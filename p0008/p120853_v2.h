#pragma once
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace v2 {
    enum class TokenType {
        Number,
        CancelPrev,
        Unknown
    };
    TokenType get_token_type(const string& s) {
        return s == "Z" ? TokenType::CancelPrev : TokenType::Number;
    }

    int solution(string s) {
        istringstream iss{ s };
        string token;
        vector<int> numbers;
        while (getline(iss, token, ' ')) {
            switch (get_token_type(token)) {
            case TokenType::Number:
                numbers.push_back(stoi(token));
                break;
            case TokenType::CancelPrev:
                numbers.pop_back();
                break;
            case TokenType::Unknown:
            default:
                break;
            }
        }

        return accumulate(numbers.begin(), numbers.end(), 0);
    }
}