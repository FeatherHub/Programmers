#include <iostream>
#include <thread>
#include <cstdlib>

using namespace std;

void func(string d) {
    static int cnt = 0;
    cout << "[" + d + "]" << endl;
}

int main()
{
    thread threads[100];

    for (int i = 0; i < 100; i++) {
        string userData;
        cin >> userData;

        threads[i] = thread(func, userData);
    }

    cout << "=-=--=MAIN_THREAD=--=-=" << endl;

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}