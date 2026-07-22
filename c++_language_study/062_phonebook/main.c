#include <stdio.h>
#include "Person.h"
#include "PhoneBook.h"


void getLine(char* buf)
{
	char c;
	while ((c = getchar()) != EOF && c != '\n')
	{
		*buf++ = c;
	}

	*buf = '\0';
}

int main()
{
	PhoneBook myPBook;
	char userInput[100];
	
	InitPhoneBook(&myPBook);
	while (1)
	{
		printf("1. add 2. show 3. find 4. del 5. exit\n");

		getLine(userInput);
		if (userInput[0] == '1')
		{
			Person p;
			printf("name: ");
			getLine(&p.name);
			printf("number: ");
			getLine(&p.phone);

			AddPerson(&myPBook, &p);
		}

		if (userInput[0] == '2')
		{
			PrintAllPerson(&myPBook);
		}
	}

	return 0;
}