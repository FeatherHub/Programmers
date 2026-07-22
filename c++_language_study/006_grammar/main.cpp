#include "Grammar.h"
#include <iostream>

int main()
{
	Grammar grammar;
	
	auto&& verbSynopsis = grammar.synopsis(WORD_CLASS::VERB);
	
	grammar.print(verbSynopsis);

	return 0;
}