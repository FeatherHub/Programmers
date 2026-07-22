#include <iostream>
#include <vector>

using namespace std;

// typedef sourceType MY_NAME;
// using MY_NAME = sourceType;

template <class _Value_type, class _Size_type>
struct templateTest {
    using value_type = _Value_type;
    using size_type = _Size_type;
};

/*
using _Scary_val = 
    _String_val<
        conditional_t<
            _Is_simple_alloc_v<_Alty>, 
            _Simple_types<_Elem>,
            _String_iter_types<_Elem, 
                                typename _Alty_traits::size_type, 
                                typename _Alty_traits::difference_type,
                                typename _Alty_traits::pointer,
                                typename _Alty_traits::const_pointer,
                                _Elem&, 
                                const _Elem&
                               >
                      >
               >;
*/

template <class _Val_types>
class usingTest {
public:
    using value_type = typename _Val_types::value_type;
    using size_type = typename _Val_types::size_type;
    using value_reference = value_type&;
    using value_pointer = value_type*;

    void printThisAndThat(value_reference refthatVal) {
        cout << this->val << " " << refthatVal << endl;
    }

    void printThisAndThat(value_pointer pthatVal) {
        cout << this->val << " " << *pthatVal << endl;
    }

public:
    value_type val;
    size_type sz;
};

int main()
{
    string s;

    templateTest<int, int> aTemplate;
    //usingTest<aTemplate> //aTemplate is not a type name

    usingTest<templateTest<int, float>> c;
    cout << typeid(c.val).name() << " " << typeid(c.sz).name() << endl;

    c.val = 10010;
    int val = 5005005;
    c.printThisAndThat(val);
    c.printThisAndThat(&val);


    return 0;
}

template <typename T>
using flexible_array = std::vector<T>;

int main3()
{
    flexible_array<string> fArray = flexible_array<string>({ "Mike", "Sam", "David" });

    for (const auto& elem : fArray) {
        cout << elem << " ";
    } cout << endl;

    return 0;
}

using nice_string = basic_string<int>;
using nice_vec = vector<nice_string>;

typedef std::pair<nice_string, nice_vec> nice_pair;

int main2()
{
    nice_string nstr;

    nice_vec nvec;

    nstr.push_back(105080);
    nstr.push_back(700560);

    nvec.push_back(nstr);

    nice_pair npair = nice_pair(nstr, nvec);

    cout << nvec.back().back() << endl;

    cout << npair.second.back().front() << endl;

    return 0;
}