#include <string>
#include <vector>

using namespace std;

inline vector<int> solution(vector<int> input, string direction) {
    const bool shift_right = direction == "right";
    vector<int> output(input.size(), 0);

    for (int i = 0; i < input.size(); ++i) {
        // shift input index according to the direction
        // and wrap with input size
        const int j = shift_right
            ? (i + 1) % input.size()
            : (i + input.size() - 1) % input.size();

        output[j] = input[i];
    }

    return output;
}

inline vector<int> solution2(vector<int> input, string direction) {
    const bool shift_right = direction == "right";
    vector<int> output(input.size(), 0);

    if (shift_right) {
        for (int i = 0; i < input.size() - 1; ++i) {
            output[i + 1] = input[i];
        }
        output.front() = input.back();
    } else {
        for (int i = 1; i < input.size(); ++i) {
            output[i - 1] = input[i];
        }
        output.back() = input.front();
    }

    return output;
}