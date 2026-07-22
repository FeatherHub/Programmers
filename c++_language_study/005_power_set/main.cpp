#include <iostream>
#include <string>
#include <vector>

using namespace std;

//example input & output
//input a, b
//output {}, {a}, {b}, {a,b}
vector<string>* comb(const vector<string>& src);
vector<string>* comb2(const vector<string>& src);
void printComb(const vector<string>& src, bool bracket);

int main()
{
	vector<string> src = {"abba", "bet", "com", "def"};

	vector<string>* res = comb2(src);

	printComb(*res, false);

	delete res;

	return 0;
}

//not elegant
vector<string>* comb(const vector<string>& src)
{
	vector<string>* res = new vector<string>;
	int eleNum = src.size();
	int maxMask = pow(2, eleNum);
	
	for (int curMask = 0; curMask < maxMask; curMask++)
	{
		string newStr;
		newStr.append("{");
		for (int eleIdx = 0; eleIdx < eleNum; eleIdx++)
		{
			if (curMask & (int)(pow(2, eleIdx)))
			{
				newStr.append(src.at(eleIdx));
			}
		}
		newStr.append("}");

		res->push_back(newStr);
	}
	
	return res;
}

//first element: select | no select => two instances
//second element: select | no select => four instnaces
//third element: select | no select => eight instances
vector<string>* comb2(const vector<string>& src)
{
	vector<string>* res = new vector<string>;
	int eleNum = src.size();

	res->push_back("");
	for (int eleIdx = 0; eleIdx < eleNum; eleIdx++)
	{
		int curCombNum = res->size();
		for (int combIdx = 0; combIdx < curCombNum; combIdx++)
		{
			string str = res->at(combIdx);
			str.append(src.at(eleIdx));
			res->push_back(str);
		}
	}
	
	return res;
}

void printComb(const vector<string>& src, bool bracket)
{
	if (!bracket) 
		for (const string& str : src)
			cout << str << ", ";
	else 
		for (const string& str : src)
			cout << "{" << str << "}, ";
}
