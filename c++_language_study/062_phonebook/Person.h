#pragma once

typedef struct Person {
	char name[100];
	char phone[100];
} Person;

void PrintPerson(const Person* p);