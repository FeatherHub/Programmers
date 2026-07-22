#include <stdio.h>
#include <stdlib.h>

#define ALPHA_NUM 26
#define DECIMAL_DIGIT_NUM 10

int main()
{
	int alphaCnt[ALPHA_NUM] = { 0, };
	int digitCnt[DECIMAL_DIGIT_NUM] = { 0, };
	int wsCnt = 0;

	char c;
	while ((c = getchar()) != EOF) { // ctrl + z = EOF
		if ('a' < c && c < 'z') {
			alphaCnt[c - 'a']++;
		}
		else if ('A' < c && c < 'Z') {
			alphaCnt[c - 'A']++;
		}
		else if ('0' < c && c < '9') {
			digitCnt[c - '0']++;
		}
		else if (c == ' ' || c == '\n' || c == '\t') {
			wsCnt++;
		}
	}

	for (int i = 0; i < ALPHA_NUM; i++) {
		printf("%c%c:", i + 'a', i + 'A');
		for (int j = 0; j < alphaCnt[i]; j++) {
			putchar('=');
		}
		putchar('\n');
	}

	return 0;
}