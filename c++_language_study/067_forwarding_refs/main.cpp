#include <iostream>

using namespace std;

//for accepting named variable, use &
template <typename DstTy, typename SrcTy>
DstTy addThenMapTo(SrcTy a, SrcTy& b) {
    return (DstTy)(a + b);
}

template <typename DstTy, typename SrcTy>
//for accepting temporal variable, use &&
DstTy addThenMapTo(SrcTy a, SrcTy&& b) {
    return (DstTy)(a + b);
}

template <typename DstTy, typename SrcTy>
void testAddThenMapTo(SrcTy s1, SrcTy s2) {
    for (int i = 0; i < 26; i++) {
        //s1+1 produces an argument mismatch
        DstTy d = addThenMapTo<DstTy, SrcTy>(s1, (s2*i));
        cout << d << " ";
    }
    cout << endl;
}

int main()
{
    testAddThenMapTo<char, int>(65, 1);
    testAddThenMapTo<int, float>(11.5678f, 6.85f);
    testAddThenMapTo<int, char>('a', 1);

    return 0;
}