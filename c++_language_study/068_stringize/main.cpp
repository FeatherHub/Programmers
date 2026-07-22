#include <iostream>
using namespace std;

#define CONCAT(x, y) #x ## #y

#define MKSTR(X) #X
#define PACK(X) X, MKSTR(X)

template <typename T>
void reflective(T v, const char* n) {
    cout << " " << n << " is " << v << endl;
}

int main()
{
    int init_val = 40;
    char thirdLastAlpha = 'X';
    string special_message = "hello";
    const char* cStyleString = "printf";
    const char* concatedOne = CONCAT(con, cdr);
    const char* concatedTwo = "bar""foo";

    reflective<int>(PACK(init_val));
    reflective<char>(PACK(thirdLastAlpha));
    reflective<string>(PACK(special_message));
    reflective<const char*>(PACK(cStyleString));
    reflective<const char*>(PACK(concatedOne));
    reflective<const char*>(PACK(concatedTwo));

    return 0;
}