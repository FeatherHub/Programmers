#include <stdio.h>
#include <stdarg.h>
#include "VA.h"

void minprintf(const char* fmt, ...)
{
	CREATE_AND_INIT_VA(va);

	const char* pc;

	union val {
		int i;
		char c;
		float f;
	};
	val v;

	for (pc = fmt; *pc != '\0'; pc++) {
		if (*pc == '%') {
			pc++;
			switch (*pc) {
			case 'd':
				v.i = va.pop<int>();
				printf("%d", v.i);
				break;
			case 'c':
				v.c = va.pop<char>();
				printf("%c", v.c);
				break;
			case 'f':
				v.f = va.pop<float>();
				printf("%f", v.f);
				break;
			case 'm':
				printf("memory");
				break;
			default:
				putchar(*(pc-1));
				putchar(*pc);
				break;
			}
		}
		else {
			putchar(*pc);
		}
	}

	va.clear();
}

int main()
{
	minprintf("%a %b %c %e %f %g \n");
	minprintf("%m = %m = %d + %d = %d and %m   and   nnn	%m\n", 3, 4, 7);
	minprintf("%m = %m = %d + %d = %d and %m \n", 3, 4, 7);
}