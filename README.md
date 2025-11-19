📅 Project Information
Project Name : Address Book Management System in C
Author       : Sanjai Kumar M

📝 Description

The Address Book Management System is a C-based console application designed to manage personal or organizational contacts. It provides the following features:

->Create new contacts
->Search existing contacts
->Edit contact information
->Delete contacts
->List all saved contacts
->Sort contacts (Name / Number / Email / Normal)
->Save data to a CSV file

This project demonstrates file handling, string manipulation, structures, and menu-driven programming in C.

📌 Menu Interface
Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Save contacts
7. Exit
Enter your choice:

🧪 Sample Input 1: Listing Contacts
Enter your choice: 5
Display sort Menu:
1. Sort by Name
2. Sort by Number
3. Sort by Email
4. Normal method
Enter your choice: 4

📤 Sample Output 1
Index  | Name            | Phone Number  | Email ID
-------------------------------------------------------------
0      | John Doe        | 1234567890    | john@example.com
1      | Alice Smith     | 0987654321    | alice@example.com
2      | Bob Johnson     | 1112223333    | bob@company.com
3      | Carol White     | 4445556666    | carol@company.com
4      | David Brown     | 7778889999    | david@example.com
5      | Eve Davis       | 6665554444    | eve@example.com
6      | Frank Miller    | 3334445555    | frank@example.com
7      | Sanjai          | 8825657765    | sanjai@12.com

🧪 Sample Input 2: Adding a Contact
Enter your choice: 1
Enter the name        : Kumar
Enter the phone number: 8825657755
Enter the email ID    : kumar@gmail.com
Contact added successfully

💾 Saving Contacts
Enter your choice: 6
Contacts saved successfully

📤 Updated Contact List
Index  | Name            | Phone Number  | Email ID
-------------------------------------------------------------
0      | John Doe        | 1234567890    | john@example.com
1      | Alice Smith     | 0987654321    | alice@example.com
2      | Bob Johnson     | 1112223333    | bob@company.com
3      | Carol White     | 4445556666    | carol@company.com
4      | David Brown     | 7778889999    | david@example.com
5      | Eve Davis       | 6665554444    | eve@example.com
6      | Frank Miller    | 3334445555    | frank@example.com
7      | Sanjai          | 8825657765    | sanjai@12.com
8      | Kumar           | 8825657755    | kumar@gmail.com

🚀 How to Compile
gcc address_book.c -o address_book

▶️ How to Run
./address_book

🔮 Future Enhancements

->Add JSON or binary storage format
->Password-protected address book
->Import/export contacts
->GUI version using GTK/QT
->Duplicate contact detection


MIT License
