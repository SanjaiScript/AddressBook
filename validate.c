#include "contact.h"
#include<string.h>
#include<ctype.h>

int validatename(char *Name)
{
    int i = 0;
    while(Name[i])
    {
        if((Name[i] >= 'A' && Name[i] <= 'Z') || (Name[i] >= 'a' && Name[i] <= 'z') || ( Name[i] ==' ')) // string should contain only alphabet
        {
            i++;
        }
        else
        {
            return -1;
        }
    }
    return 1;
}
int validatephone(char *num, AddressBook *addressBook)
{
    int i = 0;
    int len = strlen(num); // finding length of the string
    if(len != 10)
    {
        return -1;
    }
    for(int i = 0; i < len; i++)
    {
        if(num[i] < '0' && num[i] > '9') // checking string only contains digits
        {
            return -1;
        }
    }
    for(int i = 0; i < addressBook -> contactCount; i++)
    {
        if(strcmp(num, addressBook -> contacts[i].phone) == 0) // checking number is already present
        {
            return 0;
        }
    }
    return 1;
}
int validateemail(char *mail, AddressBook *addressBook)
{
    int i = 0;
    for(int i = 0; i < addressBook -> contactCount; i++)
    {
        if(strcmp(mail, addressBook -> contacts[i].email) == 0) // checking duplicate
        {
            return 0;
        }
    }
    char* at = strchr(mail, '@'); // storing address of @
    char* dot = strchr(mail, '.'); // storing address of .
    for(int i = 0; i < (at - mail); i++)
    {
        if(!(islower(mail[i]) || isdigit(mail[i]))) // checking all the alphabets are lowercase & if digits are also present
        {
            return -1;
        }
    }
    if((at < dot) && (at != NULL) && (dot != NULL) && ( at != mail) && (dot != mail) && (*(dot + 1) != '\0')) // checking @ is present before . 
    {
        return 1;
    }
    return -1;
}
        