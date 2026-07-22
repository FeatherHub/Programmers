#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

int main()
{
    map<char, int> aMap;
    try {
        int val = aMap.at('a');
    }
    catch (exception le) {
        cout << le.what() << endl;
    }

    return 0;
}