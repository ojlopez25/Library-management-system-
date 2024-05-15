#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct library
{
    int id;
    char name[50];
    char author[50];
    int year;
};

struct library *books;
int count = 0;

struct borrowedBook
{
    int bookID;
    int borrowerID; // Assuming a borrower ID for simplicity
    // You can add more fields like date borrowed, due date, etc.
};

struct borrowedBook *borrowedBooks;
int borrowedCount = 0;

struct user
{
    char username[50];
    char password[50];
};

struct user *users;
int userCount = 0;

void addBook();
void viewAllBooks();
void searchBook();
void removeBook();
void updateBook();
void borrowBook();
void returnBook();
void addUser();
int login();
void signUp();

int main()
{
    int choice;
    printf("-----------------------------------------------------------------\n");
    printf("|                          WELCOME                              |\n");
    printf("|                            TO                                 |\n");
    printf("|                   TALISAY CITY COLLEGE                        |\n");
    printf("|                 LIBRARY MANAGEMENT SYSTEM                     |\n");
    printf("-----------------------------------------------------------------\n");
    printf("\n\n\n\t\t Press any key continue... ");
    getchar();

    books = (struct library*)malloc(sizeof(struct library));
    borrowedBooks = (struct borrowedBook*)malloc(sizeof(struct borrowedBook));
    users = (struct user*)malloc(sizeof(struct user));

    addUser(); // Add some default users

    int loggedInUser = -1; // Initialize as not logged in

    do
    {
        if (loggedInUser == -1) {
            printf("\n\n\t\t######## Authentication Menu ########");
            printf("\n\t\t#                                  #");
            printf("\n\t\t#    1. Log In                    #");
            printf("\n\t\t#    2. Sign Up                   #");
            printf("\n\t\t#    3. Exit                      #");
            printf("\n\t\t#                                  #");
            printf("\n\t\t####################################");
            printf("\n\n\t\tEnter your choice:");

            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                loggedInUser = login();
                break;
            case 2:
                signUp();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Enter again.\n\n");
                break;
            }
        } else {
            printf("\n\n\t\t######## Main Menu ########");
            printf("\n\t\t#                         #");
            printf("\n\t\t#    1. Add Book          #");
            printf("\n\t\t#    2. View All Books    #");
            printf("\n\t\t#    3. Search Book       #");
            printf("\n\t\t#    4. Remove Book       #");
            printf("\n\t\t#    5. Update Book       #");
            printf("\n\t\t#    6. Borrow Book       #");
            printf("\n\t\t#    7. Return Book       #");
            printf("\n\t\t#    8. Log Out           #");
            printf("\n\t\t#    9. Exit              #");
            printf("\n\t\t#                         #");
            printf("\n\t\t###########################");
            printf("\n\n\t\tEnter your choice:");

            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                addBook();
                break;
            case 2:
                viewAllBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                removeBook();
                break;
            case 5:
                updateBook();
                break;
            case 6:
                borrowBook();
                break;
            case 7:
                returnBook();
                break;
            case 8:
                loggedInUser = -1; // Log out
                printf("Logged out successfully.\n");
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Enter again.\n\n");
                break;
            }
        }
    } while (choice != 9);

    free(books);
    free(borrowedBooks);
    free(users);
    return 0;
}

void addBook()
{
    printf("\n\t\t------ Add New Book Details ------");
    printf("\n\t\t|                              ");
    printf("\n\t\t| Enter Book ID :       ");
    scanf("%d", &books[count].id);
    printf("\t\t| Enter Book Name :     ");
    scanf("%s", books[count].name);
    printf("\t\t| Enter Book Author :   ");
    scanf("%s", books[count].author);
    printf("\t\t| Enter Book Year :     ");
    scanf("%d", &books[count].year);
    count++;
    printf("\t\t|");
    printf("\n\t\t----------------------------------");
}

void viewAllBooks()
{
    printf("\n\t\t------------- View All Book ---------------");
    printf("\n\t\t|-----------------------------------------|");
    printf("\n\t\t| ID - Book Name - Book Author - Book Year|");
    printf("\n\t\t|-----------------------------------------|");

    for (int i = 0; i < count; i++)
    {
        printf("\n\t\t|  %d\t   %s\t\t%s\t\t   %d    |", books[i].id, books[i].name, books[i].author, books[i].year);
    }
    printf("\n\t\t-------------------------------------------");
}

void searchBook()
{
    char bname[50];
    printf("\n\n\t\tEnter Book Name To be Search : ");
    scanf("%s", bname);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(books[i].name, bname) == 0)
        {
            printf("\n\t\t------ Search Book Details ------");
            printf("\n\t\t|");
            printf("\n\t\t| Book ID : %d", books[i].id);
            printf("\n\t\t| Book Name : %s", books[i].name);
            printf("\n\t\t| Book Author : %s", books[i].author);
            printf("\n\t\t| Book Year : %d\n", books[i].year);
            printf("\n\t\t|");
            printf("\t\t------------------------");
        }
    }
}

void removeBook()
{
    char bname[50];
    printf("\n\n\t\tEnter Book Name to be Remove : ");
    scanf("%s", bname);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(books[i].name, bname) == 0)
        {
            printf("\n\t\t------ Remove Book Details ------");
            printf("\n\t\t|");
            printf("\n\t\t| Book ID :     %d", books[i].id);
            printf("\n\t\t| Book Name :   %s", books[i].name);
            printf("\n\t\t| Book Author : %s", books[i].author);
            printf("\n\t\t| Book Year :   %d\n", books[i].year);
            printf("\n\t\t|");
            printf("\t\t-------------------------------");
            for (int j = i; j < count - 1; j++)
            {
                books[j] = books[j+1];
            }
            count--;
            break; // Exit the loop once the book is removed
        }
    }
}

void updateBook()
{
    char bname[50];
    printf("\n\n\t\tEnter Book Name to be Update : ");
    scanf("%s", bname);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(books[i].name, bname) == 0)
        {
            printf("\n\t\t------- Update Book Details -------");
            printf("\n\t\t| Book ID : %d", books[i].id);
            printf("\n\t\t| Book Name : %s", books[i].name);
            printf("\n\t\t| Book Author : %s", books[i].author);
            printf("\n\t\t| Book Year : %d\n", books[i].year);
            printf("\n\t\t------------------------------");

            printf("\n\n\t\t### Enter Updated Book Details ###");
            printf("\n\t\t# Enter Book ID : ");
            scanf("%d", &books[i].id);
            printf("\t\t# Enter Book Name : ");
            scanf("%s", books[i].name);
            printf("\t\t# Enter Book Author : ");
            scanf("%s", books[i].author);
            printf("\t\t# Enter Book Year : ");
            scanf("%d", &books[i].year);
            printf("\t\t##################################");

            break;
        }
    }
}

void borrowBook()
{
    int bookID;
    printf("\n\n\t\tEnter Book ID to Borrow : ");
    scanf("%d", &bookID);

    for (int i = 0; i < count; i++)
    {
        if (books[i].id == bookID)
        {
            // Check if the book is already borrowed
            for (int j = 0; j < borrowedCount; j++)
            {
                if (borrowedBooks[j].bookID == bookID)
                {
                    printf("\n\t\tThis book is already borrowed.\n");
                    return;
                }
            }

            borrowedBooks[borrowedCount].bookID = bookID;
            // For simplicity, assume borrower ID is entered directly
            printf("\n\t\tEnter your ID: ");
            scanf("%d", &borrowedBooks[borrowedCount].borrowerID);
            borrowedCount++;
            printf("\n\t\tBook borrowed successfully.\n");
            return;
        }
    }

    printf("\n\t\tBook not found.\n");
}

void returnBook()
{
    int bookID;
    printf("\n\n\t\tEnter Book ID to Return : ");
    scanf("%d", &bookID);

    for (int i = 0; i < borrowedCount; i++)
    {
        if (borrowedBooks[i].bookID == bookID)
        {
            // Remove the book from the borrowed list
            for (int j = i; j < borrowedCount - 1; j++)
            {
                borrowedBooks[j] = borrowedBooks[j + 1];
            }
            borrowedCount--;
            printf("\n\t\tBook returned successfully.\n");
            return;
        }
    }

    printf("\n\t\tBook not found in the borrowed list.\n");
}

void addUser()
{
    // Adding default users for demonstration
    strcpy(users[0].username, "admin");
    strcpy(users[0].password, "admin");

    strcpy(users[1].username, "user");
    strcpy(users[1].password, "user");

    userCount = 2;
}

int login()
{
    char username[50];
    char password[50];

    printf("\n\n\t\tEnter username: ");
    scanf("%s", username);
    printf("\t\tEnter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
        {
            printf("\n\t\tLogin successful!\n");
            return i; // Return the index of the logged-in user
        }
    }

    printf("\n\t\tInvalid username or password.\n");
    return -1; // Return -1 if login fails
}

void signUp()
{
    char username[50];
    char password[50];

    printf("\n\n\t\tEnter username: ");
    scanf("%s", username);
    printf("\t\tEnter password: ");
    scanf("%s", password);

    // Check if username already exists
    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(users[i].username, username) == 0)
        {
            printf("\n\t\tUsername already exists. Please choose another username.\n");
            return;
        }
    }

    // Add new user
    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    userCount++;

    printf("\n\t\tSign up successful!\n");
}
    
