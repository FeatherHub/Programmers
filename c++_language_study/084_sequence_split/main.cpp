#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
template <typename _FwdIt, typename _Ty>
vector<vector<_Ty>> /* [&, &&, *] */
xsplit
( _FwdIt first, _FwdIt last, _Ty delim) {
    vector<vector<_Ty>> tokens;
    
    vector<_Ty> aToken;
    for (; first != last; ++first)
    {
        if (*first != delim) {
            aToken.push_back(*first);
        } 
        else {
            tokens.push_back(move(aToken));
        }
    }

    if (!aToken.empty()) {
        tokens.push_back(move(aToken));
    }

    return tokens; 
}

template <class _Col2d> 
void print2dCollection(const _Col2d& col2d) {
    for (const auto& i : col2d) {
        for (const auto& j : i) {
            cout << j << " ";
        }
        cout << ":: ";
    }
    cout << endl;
}

int main()
{
    string instr = "add 5 10";
    auto res = xsplit(instr.begin(), instr.end(), ' ');
    print2dCollection(res);

    string instr2 = "https://www.google.com/welcome.";
    auto res2 = xsplit(instr2.begin(), instr2.end(), '.');
    print2dCollection(res2);

    vector<int> intVec {1,2,3,4,777, 15,24,33,42, 777};
    auto res3 = xsplit(intVec.begin(), intVec.end(), 777);
    print2dCollection(res3);

    return 0; 
}


/*
    [const] [type] [*] [const] [IDENTIFIER]
    --------------     --------------------
*/
int main2()
{
    int n = 65536;
    int m = 216;
    int* const p1 = &n;
    //p1 = &m;  // p1 is not modifiable
    *p1 = 44;   // *p1 is modifiable

    //////////////////////////////////////

    int a = 32;
    int b = 64;
    const int* p2;
    p2 = &a;
    p2 = &b;    // p2 is modifiable
    //*p2 = 22; // *p2 is not modifiable

    int f = 128;
    int g = 256;
    const int* const p3 = &f;

    return 0;
}