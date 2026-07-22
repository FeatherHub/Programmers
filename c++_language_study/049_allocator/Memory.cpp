#include "Memory.h"
#include <iostream>

using namespace std;

//find available block
//add inuse entry with the first address of the found block and the given size
//modify mbit occupied by the block
void* Memory::getmem(int size)
{
	int first = 0;
	int satcnt = 0;
	bool satisfied = false;
	for (int i = 0; i < MCAP; i++)
	{
		mbit[i] == AVAILABLE ? satcnt += 1 : satcnt = 0;

		if (satcnt == size)
		{
			satisfied = true;
			first = i - size;
			break;
		}
	}

	if (!satisfied) {
		cout << "no memory available" << endl;
		return nullptr;
	}

	auto membloc = make_pair(first, size);
	inuse.push_back(membloc);

	for (int i = 0; i < membloc.second; i++)
	{
		mbit[membloc.first + i] = INUSE;
	}

	return &m[first];
}

//find inuse entry
//remove the entry
//modify mbit occupied by the block
void Memory::delmem(void* ptr)
{
	bool found = false;
	pair<int, int> foundbloc;

	for (auto& ubloc : inuse)
	{
		if (m + ubloc.first == ptr)
		{
			found = true;
			foundbloc = ubloc;
			inuse.remove(ubloc);
			break;
		}
	}



}
