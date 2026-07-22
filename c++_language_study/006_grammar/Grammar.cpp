#include "Grammar.h"
#include <iostream>

using namespace std;

Synopsis&& Grammar::synopsis(WORD_CLASS wordClass)
{

    switch (wordClass)
    {
    case WORD_CLASS::VERB:
        return move(verbSynopsis());
    case WORD_CLASS::NOUN:
        return move(nounSynopsis());
    default:
        break;
    }
}

Synopsis&& Grammar::verbSynopsis()
{
    vector<_Category> categories = { 
        Category::person,
        Category::number,
        Category::tense,
        Category::voice,
        Category::mood
    };

    Synopsis verbSynopsis;
    int* currentMemberIdx = new int[categories.size()] {0, };

    string item;
    for (int catIdx = 0; catIdx < categories.size(); catIdx++) {
        item.append(categories.at(catIdx).at(currentMemberIdx[catIdx]));
        currentMemberIdx[catIdx]++;
    }
    verbSynopsis.emplace_back(move(item));

    delete[] currentMemberIdx;

    return move(verbSynopsis);
}

Synopsis&& Grammar::nounSynopsis()
{
    vector<_Category> categories = {
        Category::gender,
        Category::number,
        Category::ncase    
    };

    Synopsis nounSynopsis;

    return move(nounSynopsis);
}

void Grammar::print(const Synopsis& synopsis)
{
    std::cout << "" << std::endl; // <==?

    for (const string& item : synopsis)
    {
        cout << item << " ";
    }
}

