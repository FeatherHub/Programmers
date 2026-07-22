#include "myString.h"

using namespace myStr;

string* myStr::make(const char* src)
{
	return _make(src, len(src));
}

string* myStr::_make(const char* src, int len)
{
	return _init(new string, src, len);
}

string* myStr::_init(string* target, const char* src, int len)
{
	target->data = new char[len];
	target->len = len;
	copy(target->data, src, len);

	return target;
}

int myStr::len(const char* src)
{
	int len = 0;
	while(src[len++] != 0) {}
	return len;
}

void myStr::set(string** dst, const char* src)
{
	free(*dst);
	*dst = _make(src, len(src));
}

void myStr::set(string* dst, const char* src)
{
	delete[] dst->data;
	_init(dst, src, len(src));
}

void myStr::free(string* target)
{
	delete[] target->data;
	delete target;
}

void myStr::copy(char* dst, const char* src, int num)
{
	num--;
	while (num >= 0)
	{
		dst[num] = src[num];
		num--;
	} 
}
