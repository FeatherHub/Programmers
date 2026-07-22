#pragma once

#include <string>
#include <vector>

inline std::vector<std::string> split(const std::string& s, const char delimiter)
{
    using namespace std;

    vector<string> tokens;

    string token;
    for (const char c : s) {
        if (c == delimiter) {
            if (!token.empty())
                tokens.push_back(token);
            token = "";
        } else {
            token.push_back(c);
        }
    }

    if (!token.empty()) {
        tokens.push_back(token);
    }

    return tokens;
}
