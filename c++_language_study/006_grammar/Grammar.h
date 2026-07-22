#pragma once
#include <vector>
#include <string>

enum WORD_CLASS { VERB, NOUN };

typedef std::vector<std::string> Synopsis;

class Grammar
{
public:
	Synopsis&& synopsis(WORD_CLASS wordClass);
	void print(const Synopsis& synopsis);
	Grammar();

private:
	typedef std::vector<std::string> _Category;
	void init();
	Synopsis&& verbSynopsis();
	Synopsis&& nounSynopsis();

	struct Category 
	{
		static _Category number;
		static _Category gender;
		static _Category person;
		static _Category tense;
		static _Category voice;
		static _Category mood;
		static _Category ncase;
	};
};