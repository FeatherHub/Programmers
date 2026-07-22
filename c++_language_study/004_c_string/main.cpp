#include <stdio.h>

#include "myString.h"

void log1(myStr::string* myStr);
int main()
{
	myStr::string* myStr = myStr::make("This is not your scrapeyard");

	printf("%s (%d) \n", myStr->data, myStr->len);
	log1(myStr);
	

	int* dirty = new int[1024];


	myStr::set(myStr, "Those are my scrapeyards");
	printf("%s (%d) \n", myStr->data, myStr->len);
	log1(myStr);

	myStr::free(myStr);

	dirty[1023] = 1023;
	printf("%d \n", dirty[1023]);

	return 0;
}

void log1(myStr::string* myStr)
{
	printf("1 myStr\t\t %p\n", myStr);
	printf("2 &myStr\t %p\n", &myStr);
	printf("3 *myStr\t %p\n", *(myStr+0));
	printf("4 myStr->data\t %p\n", myStr->data);
	printf("5 &myStr->data\t %p\n", &myStr->data);
	printf("6 &myStr->len\t %p\n", &myStr->len);

}
