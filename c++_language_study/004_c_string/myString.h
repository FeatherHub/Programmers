#pragma once

namespace myStr 
{
typedef struct {
	char* data;
	int len;
} string;

string* make(const char* src);
string* _make(const char* src, int len);
string* _init(string* target, const char* src, int len);
int len(const char* src);
void set(string** dst, const char* src); //avoid using **
void set(string* dst, const char* src);
void free(string* target);
void copy(char* dst, const char* src, int num);
}
