#pragma once

#include "Person.h"

typedef struct PhoneBook {
	Person list[100];
	int cnt;
} PhoneBook;

void InitPhoneBook(PhoneBook* pb);
int ValidateSpace(const PhoneBook* pb);
void PrintAllPerson(const PhoneBook* pb);
void AddPerson(PhoneBook* pb, const Person* p);
Person FindPersonByIndex(const PhoneBook* pb, int i);
Person FindPersonByName(const PhoneBook* pb, const char* n);
Person FindPersonByPhoneNumber(const PhoneBook* pb, const char* p);
void DeletePersonByIndex(PhoneBook* pb, int i);
void DeletePersonByName(PhoneBook* pb, const char* n);
void DeletePersonByPhoneNumber(PhoneBook* pb, const char* p);
