#include <stdio.h>
#include "contact.h"

int main() {
    int choice, sortChoice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\nAddress Book Menu:\n");
        printf("------------------\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save contacts\n");		
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:
                printf("Display sort Menu:\n");
                printf("------------------\n");
                printf("1. Sort by Name\n");
                printf("2. Sort by Number\n");
                printf("3. Sort by email\n");
                printf("4. Normal method\n");
                printf("Enter your choice: ");
                scanf("%d", &sortChoice);
                if(sortChoice >= 1 && sortChoice <= 4)
                {         
                    listContacts(&addressBook, sortChoice);
                }
                else
                {
                    printf("Invalid choice\n");
                }
                break;
            case 6:
               // printf("Saving and Exiting...\n");
                saveContactsToFile(&addressBook);
                break;
            case 7:
                printf("Thank You, Exiting\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    
       return 0;
}
