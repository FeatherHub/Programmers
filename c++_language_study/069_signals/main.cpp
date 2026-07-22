#include <iostream>
#include <csignal>
#include <Windows.h>

using namespace std;

#define DEAL_CASE(X, Y) case X: sigName=#X; desc=#Y; break; 

int main();

void signalHandlerGeneral(int sig) {
    static int calledNum[NSIG] = { 0, };
    calledNum[sig]++;
 
    //build message begin
    string sigName{ "" };
    string desc{ "" };
    switch (sig) {
        DEAL_CASE(SIGABRT, "call abort()");
        DEAL_CASE(SIGBREAK, "ctrl+break seq");
        DEAL_CASE(SIGINT, "ctrl+c");
        DEAL_CASE(SIGFPE, "floating point error");
        DEAL_CASE(SIGTERM, "call kill() / not responsive to taskkill");
        DEAL_CASE(SIGSEGV, "segment violation");
    } 
    //build message end
    
    //display message
    cout << __TIME__ << " " <<  sig << " " + sigName + " " + desc + " " << calledNum[sig] << " times" << endl;

    //re-register signal
    for (int i = 0; i < NSIG; i++) {
        signal(i, signalHandlerGeneral);
    }
}

int main()
{
    cout << __DATE__ " " __TIME__ << endl;
    cout << "At " __FILE__ << endl;

    for (int i = 0; i < NSIG; i++) {
        signal(i, signalHandlerGeneral);
    }

    while (1) {
        string cmd = "default";
        cin >> cmd;
        
        if (cmd == "int") {
            raise(SIGINT);
        }
        else if (cmd == "abort") {
            abort();
        }
        else if (cmd == "sigfpe") {
            raise(SIGFPE);
        }

        else if (cmd == "default") {
            cout << "___DEFAULT___" << endl;
            Sleep(500);
        }
        else {
            cout << "Arizel" << endl;
            Sleep(500);
        }

        cmd = "default";
    }

    cout << "come here" << endl;

    return 0;
}