#include "string.h"

using namespace my;

char my::string::_tmp[2] = { '\0', };

my::string::string() : string("", 0)
{
}

my::string::string(const char* str) : string(str, calcLength(str))
{
}


my::string::string(const char* str, int len)
{
    setLength(len);
    setString(alloc(getBufferSize()));
    copy(getString(), str, getBufferSize());
}

//copy constructor
my::string::string(const string& s) : string(s.getString(), s.getLength())
{
}

my::string::~string()
{
    delstr();
    setLength(-1);
}

//integer number to string
string& my::string::convert(int)
{
    // TODO: insert return statement here
}

//string to integer number
int& my::string::convert(const string&)
{
    // TODO: insert return statement here
}

string& my::string::reverse()
{
    // TODO: insert return statement here
}

string& my::string::concat(const string& s)
{
    return insert(getLength(), s);
}

string& my::string::remove(const char)
{
    // TODO: insert return statement here
}

string& my::string::removeAt(int)
{
    // TODO: insert return statement here
}

string& my::string::replace(const char, const char)
{
    // TODO: insert return statement here
}

string& my::string::insert(int at, const string&)
{
    // TODO: insert return statement here
}

string& my::string::insert(int at, const char* cstr)
{
    return insert(at, string(cstr));
}

string& my::string::insert(int at, char c)
{
    settmp(c);
    return insert(at, _tmp);
}

string& my::string::pushback(char c)
{
    settmp(c);
    return pushback(_tmp);
}

string& my::string::pushback(const char* cstr)
{
    return pushback(string(cstr));
}

string& my::string::pushback(const string& str)
{
    return insert(getLength(), str);
}

string& my::string::pushfront(char c)
{
    settmp(c);
    return pushfront(_tmp);
}

string& my::string::pushfront(const char* cstr)
{
    return pushfront(string(cstr));
}

string& my::string::pushfront(const string& str)
{
    return insert(0, str);
}

string& my::string::removeback()
{
    return removeAt(getLength());
}

string& my::string::removefront()
{
    return removeAt(0);
}

char my::string::at(int i) const
{
    if (i < 0 || i > getBufferSize() - 1)
        return -1;

    return getString()[i];
}

char* my::string::getString() const
{
    return _str;
}

int my::string::getLength() const
{
    return _len;
}

int my::string::getBufferSize() const
{
    return getLength() + 1;
}

void my::string::setString(char* str)
{
    delstr();
    _str = str;
}

void my::string::setLength(int len)
{
    _len = len;
}

char* my::string::alloc(int n)
{
    return new char[n];
}

void my::string::copy(char*, const char*, int)
{
}

void my::string::init(const char*, int)
{
}

void my::string::delstr()
{
    if (_str != nullptr)
        delete[] _str;
}

//buffer size = length + 1 (for '\0')
int my::string::calcLength(const char* str)
{
    if (str == nullptr)
        return -1;

    const char* p;
    for (p = str; *p; p++);

    return p - str;
}

//store char in char*
void my::string::settmp(char c)
{
    _tmp[0] = c; _tmp[1] = '\0';
}