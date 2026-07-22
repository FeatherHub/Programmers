#include "String.h"

#define DATA_MEMBER_NAME _cv
#define _d	DATA_MEMBER_NAME.data()

String::String(const char* cstr)
{
	_cv.push_back('.'); //dummy
	pushBack(cstr);
}

void String::pushBack(char c)
{
	_cv.pop_back();
	_cv.push_back(c);
	_cv.push_back('\0');
}

void String::pushBack(const char* cstr)
{
	_cv.pop_back();

	for (; *cstr != '\0'; cstr++)
		_cv.push_back(*cstr);

	_cv.push_back('\0');
}

void String::pushBack(const String& str)
{
	pushBack(str._d);
}

void String::removeBack()
{
	if (_cv.front() == '\0')
		return;

	_cv.pop_back();
	_cv.pop_back();
	_cv.push_back('\0');
}

int String::length()
{
	auto i = _d;
	while (*i++ != '\0');

	return i - _d -1;
}

void String::squeeze(char c)
{
	int i, j, n;
	
	for (i = j = 0, n = length(); i < n; i++)
	{
		if (_d[i] == c)
			continue;

		_d[j++] = _d[i];
	}
	_d[j] = '\0';
}

int String::count(char c)
{
	int n = 0;
	for (auto i = _d; *i != '\0'; i++)
	{
		if (*i == c)
			n++;
	}
	return n;
}

void String::reverse()
{
	for (int i = 0, j = length() - 1; i < j; i++, j--)
	{
		
	}
}

void String::replace(char t, char r)
{
}

char& String::operator[](int idx)
{
	return _cv.at(idx);
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	os << obj._d;
	return os;
}
