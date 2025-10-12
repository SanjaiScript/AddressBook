#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100 // defining contact limit to 100
#include<stdio.h>

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;// structure variable named as Contact

typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook; // structure variable named AddressBook 

int createContact(AddressBook *addressBook);
int  validatename(char *Name);
int  validatephone(char *num, AddressBook *addressBook);
int  validateemail(char *mail, AddressBook *addressBook);
int  searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook, int sortCriteria);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);

#endif
