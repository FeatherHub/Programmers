#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    std::pair<int, string> pair1 = make_pair<int, string>(100, "hello");

    std::pair<string, int> pair2 = std::pair<string, int>("Mike", 50050);

    //concise
    auto pair3 = make_pair(500, string("World"));

    // World World 
    // Morph Mould
    
    auto pair4 = std::pair<string, int>("James", 100010);

    //std::pair<> pair5 = std::pair<int, int>(10203040, 50607080);

    //std::pair<> pair6 = make_pair(1010, string("Mould"));

    cout << pair1.first << " " << pair1.second << endl;
    cout << pair2.first << " " << pair2.second << endl;

    cout << pair3.second.size() << endl;

    return 0;
}