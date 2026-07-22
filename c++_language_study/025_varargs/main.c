#include <stdarg.h>
#include <stdio.h>

int minprintf(const char* fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);

	printf("%d \n", va_arg(ap, int));

	va_end(ap);

	return 0;
}

int main()
{
	minprintf(" ", (char)342432432);

	return printf("123 \n");
}