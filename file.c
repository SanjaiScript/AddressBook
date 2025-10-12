#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) 
{
    FILE *ptr = fopen("contacts.csv", "w");
    if(ptr == NULL) // checking whether the file is present or not
    {
        printf("Opening file failed\n");
        return;
    }
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        fprintf(ptr, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email); // writing inside a file
    }

    fclose(ptr);
    printf("Contacts saved successfully\n");
}

void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *fptr = fopen("contacts.csv", "r");
    if(fptr == NULL) // checking whether the file is present or not
    {
        printf("Opening file failed\n");
        return;
    }
    while (fscanf(fptr, "%[^,],%[^,],%[^\n]\n",
                  addressBook->contacts[addressBook->contactCount].name,
                  addressBook->contacts[addressBook->contactCount].phone,
                  addressBook->contacts[addressBook->contactCount].email) == 3) // reading from the file
    {
        addressBook->contactCount++;
        if (addressBook->contactCount >= MAX_CONTACTS) // preventing overflow
        {
            printf("Addressbook full\n");
            break;
        } 
    }
    
    fclose(fptr); // closing the file using pointer name
}

