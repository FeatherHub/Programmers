#pragma once

#include <utility>
#include <list>

#define MCAP 1000

class Memory
{
public:
	void* getmem(int size);
	void delmem(void* ptr);
	
private:
	char m[MCAP];

	enum {AVAILABLE = 0, INUSE = 1};
	char mbit[MCAP];

	//first: first address
	//second: size
	std::list<std::pair<int, int>> inuse;
};