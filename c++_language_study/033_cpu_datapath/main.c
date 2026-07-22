#include <stdio.h>
#include "Datapath.h"

#define FIRST_INSTRUCTION_ADDR 0

//fetch, decode, execute
int main()
{
	int runbit = 1;
	int PC = FIRST_INSTRUCTION_ADDR;
	
	while (runbit)
	{
		word instr = fetch_mem(PC);

		if(isI)


	}


}


