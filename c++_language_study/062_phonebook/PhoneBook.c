#include "PhoneBook.h"
#include <string.h>

void InitPhoneBook(PhoneBook* pb)
{
	pb->cnt = 0;
}

int ValidateSpace(const PhoneBook* pb)
{
	return pb->cnt == 100 ? 0 : 1;
}

void PrintAllPerson(const PhoneBook* pb)
{
	for (int i = 0; i < pb->cnt; i++)
	{
		printf("%d ", i + 1);
		PrintPerson(&pb->list[i]);
		printf("\n");
	}
}

//Function execution failure
//	invalid input
//	not enough space
//Function execution success
//	valid input
//	enough space
void AddPerson(PhoneBook* pb, const Person* p)
{
	if (pb == 0)
		printf("AddPerson nullpointer input (pb)\n");
	if (p == 0)
		printf("AddPerson nullpointer input (p)\n");
	if (!ValidateSpace(pb))
		printf("AddPerson !ValidateSpace\n");

	pb->list[pb->cnt] = *p;
	pb->cnt++;

	printf("AddPerson success\n");
	printf("name %s\n", pb->list[pb->cnt - 1].name);
	printf("phone number %s\n", pb->list[pb->cnt - 1].phone);
}

//Find and Return Issue
//signal invalid index
//signal found
Person FindPersonByIndex(const PhoneBook* pb, int i)
{
	if(i < pb->cnt)
		return pb->list[i];
}

//ReferByIndex
// valid index -> exist 
void DeletePersonByIndex(PhoneBook* pb, int i)
{
	//invalid index
	if (i < 0 && i >= pb->cnt) {
		//signal invalid input
		printf("DeletePersonByIndex: Index out of range\n");
		return;
	}

	for (int j = i; j < pb->cnt - 1; j++)
	{
		pb->list[j] = pb->list[j + 1];
	}
	pb->cnt--;

	//signal requested operation executed
	printf("DeletePersonByIndex: Operation success\n");
}
