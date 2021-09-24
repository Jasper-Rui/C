#ifndef __Contact_HEADER
#define __Contact_HEADER


#define NAME_MAX 20
#define SEX_MAX 10
#define TEL_MAX 20
#define ADDRESS_MAX 30

#define MAX 1000
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//MAX number of people
struct PerInfo
{
    char name[NAME_MAX];
    int age;
    char sex[SEX_MAX];
    int tel[TEL_MAX];
    char address[ADDRESS_MAX];
};

struct Contact
{
    struct PerInfo data[MAX];
    int sz; // currnt active amount of people
};

void InitContact(struct Contact * pc);

//add contact
void AddContact(struct Contact * pc);

//show all contacts
void ShowContact(struct Contact * pc);

//delete a specific contact
void DelContact(struct Contact * pc);

//find a contact
int FindContactByName(struct Contact * pc, char name[]);

//search contact
void SearchContact(const struct Contact * pc);

//Modify Contact
void ModifyContact(struct Contact * pc);
#endif