#include <functional>
#include <iostream>
#include <vector>

using namespace std;

template <typename _TyFirst, typename _TySecond>
vector<pair<_TyFirst, _TySecond>> map_to_pair(vector<_TyFirst> col, _TySecond val) {
    vector<pair<_TyFirst, _TySecond>> vec;

    for (_TyFirst elem : col) {
        pair<_TyFirst, _TySecond> data = pair<_TyFirst, _TySecond>(elem, val);
        vec.push_back(data);
    }

    return vec;
}

int main()
{
    vector<string> data50 = {"tree", "channel", "stream", "collection"};
    string toBePaired = "to be implemented";

    auto newData50 = map_to_pair(data50, toBePaired);

    for (auto elem : newData50) {
        cout << elem.first << " " << elem.second << endl;
    }

    return 0;
}





template <typename T>
T general_apply(function<T(T&&, T&)> f, T&& v1, T& v2) {
    return f(move(v1), v2);
}

string specific_apply(function<string(const string&, const string&)> func, string str1, string str2) {
    return func(str1, str2);
}

int main6()
{
    function<string(const string&, const string&)> myFunc = [](const string& str1, const string& str2)->string {
        return str1 + " " + str2;
    };

    //typeof: string "myFunc2"(const string&, const string&)
    auto myFunc2 = [](const string& str1, const string& str2)->string {
        return str1 + " " + str2;
    };

    vector<string> arr20 = {"Probe", "Observer", "Arbitar"};

    for (auto& e : arr20) {
        cout << specific_apply(myFunc, "Protoss", e) << endl;
    }

    vector<string> arr21 = {"Tank", "Vulture", "Goliath"};

    function <string(string&&, string&)> func35 = [](string&& str1, string& str2)->string {
        return str1 + " " + str2;
    };

    for (auto& e : arr21) {
        cout << general_apply(
            func35,
            string("Terran"), e
        ) << endl;
    }

    return 0;
}


template <typename Pred, typename Proc, typename Col>
void process_if(Pred pred, Proc proc, Col& col) {
    for (auto& e : col) {
        if (pred(e)) {
            proc(e);
        }
    }
}

int main5()
{
    vector<string> arr10 = {"dragoon", "corsair", "archon", "nexus"};

    function<bool(string&)> pred = [](string& e)->bool {
        return e.find("c") != string::npos;
    };

    function<void(string&)> proc = [](string& e)->void {
        e = "nice " + e;
    };

    process_if(pred, proc, arr10);

    for (const auto& e : arr10) {
        cout << e << endl;
    }

    return 0;
}

template <typename Ret, typename Arg1, typename Arg2>
Ret apply(function<Ret(Arg1, Arg2)> func, Arg1 arg1, Arg2 arg2) {
    function<Ret(Arg1, Arg2)> _func;
    _func = func;
    return _func(arg1, arg2);
}

template <typename F>
int apply2(F func, int a, int b) {
    //   F _func;
    //   _func = func;
    return func(a, b);
}

template <typename Pred>
bool myFind(Pred p, vector<int>* arr, int target) {
    for (int elem : *arr) {
        if (p(elem, target))
            return true;
    }
    return false;
}

template <typename Pred>
bool myFind2(Pred p, const vector<int>& arr) {
    for (const int& e : arr) {
        if (p(e))
            return true;
    }
    return false;
}

template <typename Pred, typename Col>
bool myFind3(Pred p, const Col& col) {
    for (const auto& e : col) {
        if (p(e)) return true;
    }
    return false;
}

template <typename Col, typename Process>
void forEach(Col& col, Process proc) {
    for (auto& e : col) {
        proc(e);
    }
}

int main4()
{
    vector<string> arr3 = {"ant", "bear", "doggo"};

    string prefix = "happiest";
    string postfix = "jumps";

    //function<RET([const]ARG1[&*],...)>
    function<void(string&)> lambda = [prefix, postfix](string& e) {
        e = prefix + " " + e + " " + postfix;
    };

    forEach(arr3, lambda);

    for (const string& e : arr3) {
        cout << e << endl;
    }

    return 0;
}

int main3()
{
    vector<int> arr2 = vector<int>{1,2,3,4,5,6,7,8,9};
    int target = 12;

    cout << "myFind3: " << myFind3(
        [](int e)->bool{ return e % 2 == 0; },
        arr2
    ) << endl;

    cout << "myFind2: " << myFind2(
        [target](int e) { return target == e; },
        arr2
    ) << endl;

    vector<string> arr3 = vector<string>{ "mike", "marine", "zergling", "zealot" };

    string target2 = "mike";

    cout << "myFind3(is there " << target2 << "?: " << myFind3(
        [target2](const string& e) { return e == target2; },
        arr3
    ) << endl;

    return 0;
}

int main2()
{
    cout << apply<float, int, float>(
        [](int a, float b) -> float { return a * b; },
        3000, 3.14f
        ) << endl;

    cout << apply2(
        [](int a, int b) { return a + b; },
        10, 20
    ) << endl;

    cout << apply2(
        [](float a, float b) { return 3.14f * a * b; },
        1000, 2000
    ) << endl;

    vector<int> arr = vector<int>{ 0,1,2,3,4,5,6,7,8,9 };
    cout << myFind(
        [](int elem, int target) { return elem == target; },
        &arr,
        1
    ) << endl;
    
    int target = 311;
    auto it = find_if(arr.begin(), arr.end(), [target](const int& elem) { return target == elem; });
    if (it == arr.end()) {
        cout << target << " is not found" << endl;
    }
    else {
        cout << *it << endl;
    }
    int res = it == arr.end() ? -1 : *it;
    cout << res << endl;

    return 0;
}