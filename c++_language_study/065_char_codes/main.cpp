#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream ifs;
    
    ifs.open("test61.txt");

    char c = 0;

    
    while ((c = ifs.get()) != EOF) {
        cout << "[" << (int)c << "]";
    }

    for (int i = 0; i > -10; i--) {
        cout << (char)i << endl;
    }

    return 0;
}