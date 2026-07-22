#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ofstream ofs;
    ifstream ifs;

    cout << "!===== --- == START == --- =====!" << endl;

    while (true) 
    {
        cout << "=-=-=input stream is opened=-=-=" << endl;
        ifs.open("test.txt", ios::in);

        string str2{};

        int lineNum = 1;
        while (!(ifs >> str2).eof())
        {
            cout << lineNum++ << "/" << ifs.eof() << ": ";
            cout << str2 << endl;; //write to output stream
        }
        
        cout << "=-=-=input stream is closed=-=-=" << endl;
        ifs.close();

        cout << "=-=-=output stream is opened=-=-=" << endl;
        ofs.open("test.txt", ios::out);

        string str{};
        while (true)
        {
            cin >> str; //read from input stream

            if (str == "break")
                break;
            else if (str == "return") {
                ofs.close();
                return 1;
            }

            ofs << str << endl; //write to output stream

            cout << str << endl; 
        }

        cout << "=-=-=output stream is closed=-=-=" << endl;
        ofs.close();
    }
    return 0;
}