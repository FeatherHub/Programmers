#include <iostream>
#include <map>
#include <string>

#include "decode_morse.h"

using namespace std;

string solution(string morse)
{
    return decode_morse(morse);
}

int main()
{
    string morse_code_1 = "... --- ... ";
    string result = solution(morse_code_1);
    cout << result << endl;
    cout << "Expected: sos" << endl;

    return 0;
}