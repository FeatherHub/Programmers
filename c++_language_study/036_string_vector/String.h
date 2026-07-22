#pragma once
#include <vector>
#include <iostream>

class String
{
public:
	String(const char*);
	void pushBack(char c);
	void pushBack(const char* cstr);
	void pushBack(const String& str);
	void removeBack();
	int length();
	void squeeze(char c);
	int count(char c);
	void reverse();
	void replace(char t, char r);
	char& operator[](int idx);
	friend std::ostream& operator<<(std::ostream& os, const String& obj);

private:
	std::vector<char> _cv;
};