#include <stdio.h>

#define isws(c) (c==' ' || c=='\t' || c=='\n')
#define IN 1
#define OUT 0

int main()
{
	int in = OUT; //running whitespace
	
	char c;
	while ((c = getchar()) != EOF) {
		if (isws(c)) {
			if (in == OUT) {
				putchar(' ');
				in = IN;
			}
			else {
				;
			}
		}
		else {
			putchar(c);
			in = OUT;
		}
	}

	return 0;
}