#include <exception>
#include <iostream>
#include <string>
#include <format>

using namespace std;

class my_exception : public exception {
public:
    my_exception(const string& msg, const string& data) 
        : exception(msg.c_str()), _data(data) {
    }

    void print_data() const noexcept {
        cout << _data << endl;
    }

private:
    string _data;
};


void general_handle(exception& e) {
    cout << e.what() << endl;
}

int main()
{
    string str{}, msg{};
    int time {1};
LABEL1:
    try {
        cin >> str;
        msg = format("<str:{}><time:{}>", str, time);
        
        if (str == "case1") {
            msg += "<length_error>";
            throw std::length_error(msg);
        }
        else if (str == "case2") {
            msg += "<out_of_range>";
            throw std::out_of_range(msg);
        } 
        else if (str == "case3") {
            msg += "<my_exception>";
            throw my_exception(msg, "happy dog");
        }
        else if (str == "exit") {
            goto LABEL2;
        }
        else {
            cout << "all is well" << endl;
        }
    } 
    catch (std::length_error& e) {
        general_handle(e);
    }
    catch (std::out_of_range& e) {
        general_handle(e);
    }
    catch (my_exception e) {
        general_handle(e);
        e.print_data();
    }

    time++;
    str = "";
    goto LABEL1;
LABEL2:
    cout << "goodbye" << endl;
    return 0;
}