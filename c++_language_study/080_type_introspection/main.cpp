#include <iostream>
#include <vector>
#include <type_traits>
#include <algorithm>

using namespace std;

//template <class TypeName> RetType FuncName (ArgType) {}
template <class Col> void _reverse(Col& col) {
    //decltype(col[0]) -> Val&
    //tmp <=> col[8]
    int targetIdx = 5;
    decltype(col[0]) tmp = col[targetIdx];
    
    if(is_reference<decltype(col[0])>::value) {
        cout << "it is reference" << endl;
    }

    for (auto elem : col) {
        cout << elem << " ";
    }
    cout << endl;

    cout << "tmp: " << tmp << endl;
    cout << "tmp is col[" << targetIdx << "]" << endl;

    for (int i = 0, j = col.size() - 1;
        i <= j;
        i++, j--) 
    {
        cout << "NEXT STEP" << endl;

        cout << "tmp\tcol[i]\tcol[j]\tbefore" << endl << tmp << "\t" << col[i] << "\t" << col[j] << endl;
        
        tmp = col[i]; 
        cout << "tmp\tcol[i]\tcol[j]\ttmp = col[i]" << endl << tmp << "\t" << col[i] << "\t" << col[j] << endl;
        
        col[i] = col[j]; 
        cout << "tmp\tcol[i]\tcol[j]\tcol[i] = col[j]" << endl << tmp << "\t" << col[i] << "\t" << col[j] << endl;
        
        col[j] = tmp;
        cout << "tmp\tcol[i]\tcol[j]\tcol[j] = tmp" << endl << tmp << "\t" << col[i] << "\t" << col[j] << endl;

        for (auto elem : col)
            cout << elem << " ";
        cout << "\tafter: [" << targetIdx << "]:" << col[targetIdx] << endl;
    }
}

int main()
{
    vector<int> vi {1, 2, 3, 4, 5, 6, 7, 8, 9};

    _reverse<vector<int>>(vi);

    return 0;
}

template <typename _Ty>
string xtypename(const _Ty& inspect) {
    return string{typeid(decltype(inspect)).name()};
}

#include <vector>

int main3()
{
    int i; float f; vector<int> v; vector<vector<int>> vv;
    string s;

    cout << xtypename(i) << endl;
    cout << xtypename(f) << endl;
    cout << xtypename(v) << endl;
    cout << xtypename(vv) << endl;
    cout << xtypename(s) << endl;
    return 0;
}

// typeid(GENERIC TYPE).name()
// typeid(CONCRETE TYPE).raw_name()

// decltype(var name) => TYPE
// -> decltype(unit) otherUnit;

// typeid(decltype(var name)).name()


template <typename _Ty>
void f(_Ty v, _Ty w) {
    //type_info
    string s = string{typeid(_Ty).name()}.substr(0, 12);
    
    //decltype expects an expression, not a type
    if (s == "float") {
        decltype(v) var = 3.141519f;
        cout << var << " ";
    }
   
    cout << s << endl;
}

struct TAG10010 {
    explicit TAG10010() = default;
};

//template specializtion
template <>
void f(TAG10010 v, TAG10010 w) {
    cout << "congratulation " << typeid(decltype(v)).raw_name() << endl;
}

int main2()
{
    TAG10010 tag;

    //void f<int>(int, int)
    f<int>(11, 22);
    f<float>(1.1f, 2.2f);

    f(tag, tag);
    
    //too many template arguments
    //f<TAG10010, TAG10010>(0, 0);

    f<TAG10010>(TAG10010{}, TAG10010{});

    string s;

    return 0;
}