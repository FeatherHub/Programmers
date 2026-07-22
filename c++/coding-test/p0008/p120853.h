#pragma once
#include <cctype>
#include <string>
#include <vector>

using namespace std;
namespace v1 {
    bool is_num(const string& s) {
        if (s.empty()) {
            return false;
        }

        bool has_sign = s.front() == '+' || s.front() == '-';

        // Test "+", "-"
        if (s.size() == 1 && has_sign) {
            return false;
        }

        int start_idx = has_sign ? 1 : 0;
        for (int i = start_idx; i < s.size(); ++i) {
            if (!isdigit(s[i])) {
                return false;
            }
        }

        return true;
    }

    vector<string> tokenize(string s, char delim) {
        vector<string> tokens;

        string token;
        for (char c : s) {
            if (c == delim) {
                tokens.push_back(token);
                token.clear();
            }
            else {
                token += c;
            }
        }

        if (!token.empty()) {
            tokens.push_back(token);
        }

        return tokens;
    }

    enum class TokenType {
        Number,
        SubtractPrev,
        Unknown
    };

    TokenType get_token_type(const string& token) {
        if (token == "Z") {
            return TokenType::SubtractPrev;
        }

        if (is_num(token)) {
            return TokenType::Number;
        }

        return TokenType::Unknown;
    }

    int solution(string s) {
        vector<string> tokens = tokenize(s, ' ');
        int sum = 0;
        int prev_num = 0;
        for (const string& token : tokens) {
            TokenType token_type = get_token_type(token);
            switch (token_type) {
            case TokenType::SubtractPrev:
                sum -= prev_num;
                break;
            case TokenType::Number: {
                int num = stoi(token);
                sum += num;
                prev_num = num;
                break;
            }
            case TokenType::Unknown:
            default:
                break;
            }
        }

        return sum;
    }
}