#include <iostream>

using namespace std;

char* reverse(char* str);
char* reverseByWord(char* str);

int main()
{
	cout << reverseByWord(new char[100] {"123 456 789 \n"});
	cout << reverseByWord(new char[100] {"apple melon tomato \n"});
	cout << reverseByWord(new char[100] {"hello world, bye world \n"});
	cout << reverseByWord(new char[100] {"FABF AQWA DFGD \n"});
	cout << reverseByWord(new char[100] {"foobar raboof \n"});

	return 0;
}

char* reverse(char* str)
{
	char stk[100];
	int sp = -1;

	for (int i = 0; str[i] != '\0'; ++i)
		stk[++sp] = str[i];
	
	for (int i = 0; str[i] != '\0'; ++i)
		str[i] = stk[sp--];

	return str;
}

char* reverseByWord(char* str)
{
	const int IN = 1;
	const int OUT = 0;

	int in = OUT;
	int wordStart = 0;
	int i = 0;
	char tmp;
	while (true)
	{
		if (in == IN && (str[i] == ' ' || str[i] == '\0')) { // IN->OUT
			in = OUT;

			tmp = str[i];
			str[i] = '\0';
			reverse(&str[wordStart]);
			str[i] = tmp;
		}
		else if(in == OUT && str[i] != ' ') { // OUT->IN
			in = IN;

			wordStart = i;
		}

		if (str[i] == '\0')
			break;

		i++;
	}

	return str;
}
