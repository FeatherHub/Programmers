#include "mystring.h"
#include "mymath.h"

int myatoi(const char* s)
{
	char buf[100] = "";
	int i = 0;
	int res = 0;

	myreverse(s, buf);

	while (buf[i] != '\0')
	{
		res += mypow(10, i) * (buf[i] - '0');

		i++;
	}

	return res;
}

//assumption: s and t are pointing different string
void myreverse(const char* s, char* t)
{
	int l = mystrlen(s);
	int si = l - 1;
	int ti = 0;

	while (si >= 0)
	{
		t[ti++] = s[si--];
	}

	t[ti] = '\0';
}

char* myreverse2(char* s)
{
	int i = 0;
	int l = mystrlen(s) - 1;

	for (i = 0, l = mystrlen(s) - 1; i < l; i++, l--)
	{
		char t = s[i];
		s[i] = s[l];
		s[l] = t;
	}

	return s;
}

int mystrlen(const char* s)
{
	char* const t = s;

	while (*s++ != '\0');

	return (int)s - (int)t - 1;
}

/*
shrink running identical characters into one
input: "aaabaacdaaaa", 'a'
output: "abacda"
*/
char* mycompact(char* s, char c)
{
	int i, j, cnt;
	i = j = cnt = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c && cnt == 0) {
			cnt++;
			s[j++] = s[i++];
		}
		else if (s[i] == c && cnt != 0) {
			cnt++;
			i++;
		}
		else if (s[i] != c && cnt == 0) {
			s[j++] = s[i++];
		}
		else if (s[i] != c && cnt != 0) {
			cnt = 0;
			s[j++] = s[i++];
		}
		else {
			//impossible
		}
	}

	s[j] = '\0';

	return s;
}

//shrink running occurencies of the character
//input: "aaabbbcccaaabbba", 'a'
//output: "abbbcccabbba"
char* mycompact2(char* s, char c)
{
	int i, j, cnt;

	for (i = j = cnt = 0; s[i] != '\0';)
	{

	}
}


/*
cut all occurence of the character at the front and back of the string
input: "aaabbaaaaccaa", 'a'
output: "bbaaaacc"
*/
char* mytrim(char* s, char c)
{
	mytrimfront(s, c);
	myreverse2(s);
	mytrimfront(s, c);
	myreverse2(s);
	return s;
}

/*
cut all occurence of the character at the front of the string
intput: "aaabbbcccaaa", 'a'
output: "bbbcccaaa"
*/
char* mytrimfront(char* s, char c)
{
	int i, j, flag;

	i = j = flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && flag == 0)
			i++;
		else if (s[i] == c && flag != 0)
			s[j++] = s[i++];
		else if (s[i] != c && flag == 0) {
			flag = 1;
			s[j++] = s[i++];
		}
		else if (s[i] != c && flag != 0)
			s[j++] = s[i++];
		else {
			//impossible
		}
	}
	s[j] = '\0';

	return s;
}







