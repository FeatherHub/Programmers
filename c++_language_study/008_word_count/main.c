#include <stdio.h>

int isws(int c);

#define IN 1
#define OUT 0

int main()
{
	int wordCnt = 0;
	int in = OUT;

	char c;
	while ((c = getchar()) != EOF) {
		//if (in == IN && isws(c) == 0 ) {
		//	;
		//} 
		//else if (in == OUT && isws(c) == 0) {
		//	in = IN;
		//	wordCnt++;
		//}
		//else if (isws(c) == 1) {
		//	in = OUT;
		//}

		if (isws(c) == 0) {
			if (in == OUT) {
				wordCnt++;
				in = IN;
			}
			else {
				;
			}
		}
		else {
			in = OUT;
		}
	}

	printf("wc: %d\n", wordCnt);

	return 0;
}

int isws(int c)
{
	return c == ' ' || c == '\t' || c == '\n';
}
