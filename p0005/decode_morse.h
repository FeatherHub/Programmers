#pragma once

#include <string>
#include <unordered_map>

#include "split.h"

inline std::string decode_morse(const std::string& morse_msg)
{
    using namespace std;

    static unordered_map<string, char> morse_map {
        { ".-", 'a' },
        { "-...", 'b' },
        { "-.-.", 'c' },
        { "-..", 'd' },
        { ".", 'e' },
        { "..-.", 'f' },
        { "--.", 'g' },
        { "....", 'h' },
        { "..", 'i' },
        { ".---", 'j' },
        { "-.-", 'k' },
        { ".-..", 'l' },
        { "--", 'm' },
        { "-.", 'n' },
        { "---", 'o' },
        { ".--.", 'p' },
        { "--.-", 'q' },
        { ".-.", 'r' },
        { "...", 's' },
        { "-", 't' },
        { "..-", 'u' },
        { "...-", 'v' },
        { ".--", 'w' },
        { "-..-", 'x' },
        { "-.--", 'y' },
        { "--..", 'z' },
    };

    vector<string> morse_tokens = split(morse_msg, ' ');

    string alpha_msg;
    alpha_msg.reserve(morse_tokens.size());

    for (const string& morse : morse_tokens) {
        const auto& it = morse_map.find(morse);
        if (it != morse_map.end()) {
            alpha_msg.push_back(it->second);
        }
    }

    return alpha_msg;
}
