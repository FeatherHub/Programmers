#include <iostream>
#include <string_view>

using namespace std;

// use string_view when passing a string for read-only purpose
// rather than const string& or const char* because 
// const string& makes copy when passed a const char* and
// const char* makes std::string user call data() or c_str() method to interface it
void view_even(string_view sv) {
	for (size_t i{ 0 }; i < sv.size(); ++i) {
		if (i % 2 == 0) {
			cout << sv.at(i);
		}
	}
	cout << endl;
}

int main()
{
	string s1 = "hello world";
	auto s2{ "lorem ipsum" };
	auto s3{ "foobar"s };
	char s4[]{ "brooks instrument" };

	view_even(s1);
	view_even(s2);
	view_even(s3);
	view_even(s4);

    return 0;
}