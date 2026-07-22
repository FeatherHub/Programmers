#include "Grammar.h"

Grammar::_Category Grammar::Category::number;
Grammar::_Category Grammar::Category::gender;
Grammar::_Category Grammar::Category::person;
Grammar::_Category Grammar::Category::tense;
Grammar::_Category Grammar::Category::voice;
Grammar::_Category Grammar::Category::mood;
Grammar::_Category Grammar::Category::ncase;

Grammar::Grammar()
{
    init();
}

//to do: load from json file
void Grammar::init()
{
    Category::gender = { "male", "female" };
    Category::mood = { "indicative", "subjuctive", "optative", "imperative", "infinitive" };
    Category::number = { "singular", "plural" };
    Category::person = { "first person", "second person", "third person" };
    Category::tense = { "present", "future", "imperfect", "aorist", "perfect", "pluperfect" };
    Category::voice = { "active", "middle", "passive" };
    Category::ncase = { "nominative", "genitive", "dative", "accusative", "vocative"};
}