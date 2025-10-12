#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the chosen criteria
    if(sortCriteria == 1)
    {
        for(size_t i = 0; i < addressBook -> contactCount - 1; i++)
        {
            for(size_t j = i + 1; j < addressBook -> contactCount; j++)
            {
                if(strcmp(addressBook -> contacts[i].name, addressBook -> contacts[j].name) > 0) //selection sort method used to sort
                {
                    Contact temp = addressBook -> contacts[i];
                    addressBook -> contacts[i] = addressBook -> contacts[j];
                    addressBook -> contacts[j] = temp;
                }
            } 
        }
            printf("\n----------------------------------------------------------------------------\n");
            printf("| %-5s | %-25s | %-15s | %-25s\n", "Index" ,"Name", "phone number", "email Id");
            printf("----------------------------------------------------------------------------\n");

        for(size_t i = 0; i < addressBook -> contactCount; i++)
        {
            printf("| %-5zu | %-25s | %-15s | %-25s\n", 
                  i,
                  addressBook -> contacts[i].name,
                  addressBook->contacts[i].phone, 
                  addressBook->contacts[i].email); //using %zu data specifier because i is unsigned long int
        }
            printf("----------------------------------------------------------------------------\n");
    }
    else if(sortCriteria == 2)
    {
        for(size_t i = 0; i < addressBook -> contactCount - 1; i++)
        {
            for(size_t j = i + 1; j < addressBook -> contactCount; j++)
            {
                if(strcmp(addressBook -> contacts[i].phone, addressBook -> contacts[j].phone) > 0) // if contacts[j] is greater than contacts[i] strcmp will return 1
                {
                    Contact temp = addressBook -> contacts[i];
                    addressBook -> contacts[i] = addressBook -> contacts[j];
                    addressBook -> contacts[j] = temp;
                }
            }  
        }
            printf("\n----------------------------------------------------------------------------\n");
            printf("| %-5s | %-25s | %-15s | %-25s\n", "Index" ,"Name", "phone number", "email Id");
            printf("----------------------------------------------------------------------------\n");

        for(size_t i = 0; i < addressBook -> contactCount; i++)
        {
            printf("| %-5zu | %-25s | %-15s | %-25s\n", 
                i,
                addressBook -> contacts[i].name, 
                addressBook->contacts[i].phone, 
                addressBook->contacts[i].email);
        }
            printf("----------------------------------------------------------------------------\n");
    }
    else if(sortCriteria == 3)
    {
        for(size_t i = 0; i < addressBook -> contactCount - 1; i++)
        {
         for(size_t j = i + 1; j < addressBook -> contactCount; j++)
            {
                if(strcmp(addressBook -> contacts[i].email, addressBook -> contacts[j].email) > 0)
                {
                    Contact temp = addressBook -> contacts[i];
                    addressBook -> contacts[i] = addressBook -> contacts[j];
                    addressBook -> contacts[j] = temp;
                }
            }  
        }
            printf("\n----------------------------------------------------------------------------\n");
            printf("| %-5s | %-25s | %-15s | %-25s\n", "Index" ,"Name", "phone number", "email Id");
            printf("----------------------------------------------------------------------------\n");

        for(size_t i = 0; i < addressBook -> contactCount; i++)
        {
            printf("| %-5zu | %-25s | %-15s | %-25s\n", 
                i,
                addressBook -> contacts[i].name, 
                addressBook -> contacts[i].phone, 
                addressBook -> contacts[i].email);
        }
            printf("----------------------------------------------------------------------------\n");
    }
    else if(sortCriteria == 4)
    {
            printf("\n----------------------------------------------------------------------------\n");
            printf("| %-5s | %-25s | %-15s | %-25s\n", "Index" ,"Name", "phone number", "email Id");
            printf("----------------------------------------------------------------------------\n");

        for(size_t i = 0; i < addressBook -> contactCount; i++)
        {
            printf("| %-5zu  | %-25s | %-15s | %-25s\n",
                i,
                addressBook -> contacts[i].name, 
                addressBook -> contacts[i].phone, 
                addressBook -> contacts[i].email);
        }
            printf("----------------------------------------------------------------------------\n");
    }
}

void initialize(AddressBook *addressBook) 
{
    addressBook->contactCount = 0;
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


int createContact(AddressBook *addressBook)
{
	/* Define the logic to  create a Contacts */
    char Name[20];
    char num[12];
    char mail[20];
    printf("Enter the name        : ");
    getchar(); // removes the newline character
    scanf("%[^\n]", Name);
    if(sizeof(Name) == 0 || Name[0] == ' ') // checking the name of 1st index contains only space or empty string
    {
        printf("Name should not be empty\n");
        return -1;
    }
    int ret = validatename(Name); // validatename returns 1 if all the conditions passed

    if(ret == -1)
    {
        printf("Invalid name!\n");
        return -1;
    }
    printf("Enter the phone number: ");
    scanf(" %s", num);

    ret = validatephone(num, addressBook); // we are passing address of addressBook to check duplicates 

    if(ret == -1)
    {
        printf("Invalid number!\n");
        return -1;
    }
    else if(ret == 0)
    {
        printf("Number alredy exists\n");
        return -1;
    }
    printf("Enter the email.Id    : ");
    scanf("%s", mail);

    ret = validateemail(mail, addressBook);
    
    if(ret == -1)
    {
        printf("Invalid email.Id\n");
        return -1;
    }
    else if(ret == 0)
    {
        printf("Email.id already exists\n");
        return -1;
    }
    strcpy(addressBook -> contacts[addressBook -> contactCount].name,Name);
    strcpy(addressBook -> contacts[addressBook -> contactCount].phone, num);
    strcpy(addressBook -> contacts[addressBook -> contactCount].email, mail);
    addressBook->contactCount++;
    printf("Contact updated successfully\n");
}

int searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int option;
    int found = 1; // flag to check the contact is present or not
    printf("1. Search by name\n");
    printf("2. Search by phone number\n");
    printf("3. Search by email id\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
        switch (option) //passing the option to switch case
        {
            case 1: // search by name
            {
                char Name[20];
                printf("Enter the Name: ");
                getchar(); // removing newline from the buffer
                scanf("%[^\n]", Name);
                for(size_t i = 0; i < addressBook -> contactCount; i++)
                {
                    if(strcasecmp(addressBook -> contacts[i].name, Name) == 0)
                    {
                        printf("\nContact Found\n");
                        printf("----------------------------------------------------------------------------\n");
                        printf("| %-5s | %-25s | %-15s | %-30s\n","Index", "Name", "phone number", "email Id");
                        printf("----------------------------------------------------------------------------\n");
                        printf("| %-5zu | %-25s | %-15s | %-30s\n",
                            i,
                            addressBook -> contacts[i].name,  
                            addressBook -> contacts[i].phone, 
                            addressBook -> contacts[i].email);
                            found = 0;
                            break;
                    }
                }
                if(found == 1) // if found remains the same as it declared
                {
                    printf("\nContact not found\n");
                    return 0;
                }
            }
            break;
            case 2: // search by phone number
            {
                char num[20];
                printf("Enter the Phone Number: ");
                scanf("%s", num);
                for(size_t i = 0; i < addressBook -> contactCount; i++)
                {
                    if(strcmp(addressBook -> contacts[i].phone, num) == 0)
                    {
                        printf("\nContact Found\n");
                        printf("----------------------------------------------------------------------------\n");
                        printf("| %-5s | %-25s | %-15s | %-30s\n","Index", "Name", "phone number", "email Id");
                        printf("----------------------------------------------------------------------------\n");
                        printf("| %-5zu | %-25s | %-15s | %-30s\n",
                            i,
                            addressBook -> contacts[i].name,  
                            addressBook -> contacts[i].phone, 
                            addressBook -> contacts[i].email);
                            found = 0;
                            break;
                    }
                }
                if(found == 1)
                {
                    printf("\nContact not found\n");
                    return 0;
                }
            }
            break;
            case 3: // search by email
            {
                char mail[20];
                printf("Enter the Mail.ID: ");
                scanf("%s", mail);
                for(size_t i = 0; i < addressBook -> contactCount; i++)
                {
                    if(strcmp(addressBook -> contacts[i].email, mail) == 0)
                    {
                        printf("\nContact Found\n");
                        printf("----------------------------------------------------------------------------\n");
                        printf("| %-5s | %-25s | %-15s | %-30s\n","Index", "Name", "phone number", "email Id");
                        printf("----------------------------------------------------------------------------\n");
                        printf("| %-5zu | %-25s | %-15s | %-30s\n",
                            i,
                            addressBook -> contacts[i].name,  
                            addressBook -> contacts[i].phone, 
                            addressBook -> contacts[i].email);
                            found = 0;
                            break;
                    }
                }
                if(found == 1)
                {
                    printf("\nContact not found\n");
                    return 0;
                }
            }
            break;
            default:
                printf("\nInvalid search option\n");
                return 0;
        }
        return 1;
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    int ret = searchContact(addressBook); // calling search function to find particular contact to edit
    if(ret == 0)
    {
        return;
    }
    int index; // getting index for accuracy
    printf("Enter the index to edit: \n");
    scanf("%d", &index);
    if(index < 0 || index >= addressBook -> contactCount) // to check the index is within the limit
    {
        printf("Invalid index\n");
        return;
    }
    int choice;
    printf("What you want edit\n");
    printf("1. Name\n");
    printf("2. Phone number\n");
    printf("3. Email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) // edit by name
    {
        case 1:
            char Name[20];
            printf("Enter Name: ");
            getchar(); // removes newline inside the buffer
            scanf("%[^\n]", Name);
            int ret = validatename(Name); // validatename returns 1 if all the conditions passed

            if(ret == -1)
            {
                printf("Invalid Name!\n");
                return;
            }
            strcpy(addressBook -> contacts[index].name, Name);
            printf("Contact updated successfully\n");
            break;

        case 2: // edit by phone number
            char num[12];
            printf("Enter Phone number: ");
            scanf("%s", num);
            ret = validatephone(num, addressBook);

            if(ret == -1)
            {
                printf("Invalid Number\n");
                return;
            }
            strcpy(addressBook -> contacts[index].phone, num);
            printf("Contact updated successfully\n");
            break;

        case 3: // edit by email
            char mail[20];
            printf("Enter Email.ID: ");
            scanf("%s", addressBook -> contacts[index].email);
            ret = validatephone(mail, addressBook);

            if(ret == -1)
            {
                printf("Invalid Mail.ID\n");
                return;
            }
            strcpy(addressBook -> contacts[index].email, mail);
            printf("Contact updated successfully\n");
            break;

        default:
            printf("Invalid choice\n");
            return;
    }     
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    int ret = searchContact(addressBook);
    if (ret == 0) // checking if the contact is found
    {
        return;
    }
    int index;
    printf("\nEnter the index to delete: \n");
    scanf("%d", &index);
    if(index < 0 || index >= addressBook -> contactCount)
    {
        printf("Invalid index\n"); // if index not found
        return;
    }
    for(int i = index; i < addressBook -> contactCount - 1; i++)
    {
        addressBook -> contacts[i] = addressBook -> contacts[i + 1]; // shifting the contacts one index up
    }
    addressBook -> contactCount--; // decreamenting the contacts count
    printf("Contact deleted successfully\n"); // prompt to the user after successfull deletion
    
}
