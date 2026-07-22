#include <iostream>

using namespace std;

char* _rm(char* src, const char rm);
char* _rm2(char* src, const char rm);
char* _rms(char* src, const char* rms);
char* _rms2(char* src, const char* rms);

int main()
{
	cout << _rm2(new char[100] {"afdsfsdfv  aa  sadwq"}, 'a');

	cout << endl;

	cout << _rms(new char[100] {"xayb zchd je \n and yoyu"}, "abcd aaaa \n\n \b\b");

	return 0;
}

char* _rm(char* src, const char rm)
{
	int i, j;
	i = j = 0;

	while (src[i] != '\0') 
	{
		if (src[i] == rm) 
			j--;

		src[++j] = src[++i];
	}

	return src;
}

//assumption on arguments
// src is not null
// src is null terminated
// rm is not null character
char* _rm2(char* src, const char rm)
{
	int i, j;
	for (i = j = 0; src[i] != '\0'; i++)
		if (src[i] != rm)
			src[j++] = src[i];
	
	src[j] = '\0';

	return src;
}

char* _rms2(char* src, const char* rms)
{
	int i, j;
	i = j = 0;

	while (src[i] != '\0')
	{
		for (int k = 0; rms[k] != '\0'; k++)
		{
			if (src[i] == rms[k]) {
				j--;
				break;
			}
		}

		src[++j] = src[++i];
	}

	return src;
}

char* _rms(char* src, const char* rms)
{
	int i = 0;

	while (rms[i] != '\0')
		_rm2(src, rms[i++]);

	return src;
}
