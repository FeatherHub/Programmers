#include <iostream>
#include <vector>

using namespace std;

template <typename _Ty, int _Sz>
class xArray {
public:
    _Ty m_dummy;
    _Ty m_data[_Sz];
    xArray(const initializer_list<_Ty>& li);

    pair<bool,_Ty&> operator[](int idx);
};

template <typename _Ty, int _Sz>
pair<bool, _Ty&> 
xArray<_Ty, _Sz>::operator[](int idx) {
    if (idx >= _Sz) {
        return pair<bool, _Ty&>(false, idx);
    }

    return pair<bool, _Ty&>(true, m_data[idx]);
}

template <typename _Ty, int _Sz>
xArray<_Ty, _Sz>::xArray(const initializer_list<_Ty>& li) {
    auto it = li.begin();
    const size_t _Limit =
        _Sz < li.size() ? _Sz : li.size();
    for (int i = 0; i < _Limit; i++)
    {
        m_data[i] = *it++;
    }
}

int main()
{
    xArray<int, 10> arr {1, 2, 3, 4, 5, 6};

    for (int i = 0; i < 20; i++)
    {
        pair<bool, int&> res = arr[i];
        if (res.first) {
            cout << arr[i].second << endl;
            arr[i].second *= 100;
        }
        else {
            cout << arr[i].second << ": invalid index" << endl;
            arr[i].second *= -100;
        }
    }

    for (int i = 0; i < 20; i++)
    {
        pair<bool, int&> res = arr[i];
        if (res.first) {
            cout << arr[i].second << endl;
        }
        else {
            cout << arr[i].second << ": invalid index" << endl;
        }
    }

    return 0;
}