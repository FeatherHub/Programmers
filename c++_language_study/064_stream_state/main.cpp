#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream ifs;
    string s{};
    string s2{};

    ifs.open("test60.txt", ios::in);

    //skip three from beginning
    cout << "rdstate point 1: " << ifs.rdstate() << endl;
    ifs.seekg(1, ios::beg); //file[3]
    cout << "rdstate point 2: " << ifs.rdstate() << endl;
    ifs >> s;
    cout << "rdstate point 3: " << ifs.rdstate() << endl;
    cout << "1: " << s << endl;
    
    //skip three from end
    ifs.seekg(-5, ios::end); //file[-5]
    cout << "rdstate point 4: " << ifs.rdstate() << endl;
    ifs >> s2;
    cout << "rdstate point 5: " << ifs.rdstate() << endl;
    cout << "2: " << s2 << endl;

    return 0;
}