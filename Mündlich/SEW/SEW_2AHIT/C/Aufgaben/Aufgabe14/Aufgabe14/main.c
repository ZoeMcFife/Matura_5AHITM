#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include "ConFun.h"
#include <windows.h>

#define LASTUSED "startup/lastUsedFile.bin"

/// This color scheme looks better in the new Windows 11 terminal, for standard CMD I'd change the default color to WHITE
#define DEFAULTCOLOR DARKORANGE
#define ERRORCOLOR RED
#define WARNINGCOLOR YELLOW
#define OKCOLOR GREEN
#define INPUTCOLOR MAGENTA

/// I adopted the _t naming scheme for typedefs now
/// might make my code easier to read

typedef struct
{
    char keyword1[35];
    char keyword2[35];
    char keyword3[35];
} keywords_t;

typedef struct
{
    char familyName[35];
    char firstName[35];
} name_t;

typedef struct
{
    char streetWithHousenumber[40];
    unsigned int ZIP;
    char city[30];
} address_t;

typedef struct
{
    unsigned int day;
    unsigned int month;
    unsigned int year;
} date_t;

typedef struct
{
    char id[20];
    name_t name;
    address_t homeAddress;
    date_t returnDate;
} loaningData_t;

typedef struct
{
    char author[40];
    char coAuthor[40];
} authors_t;

typedef struct
{
    unsigned int bookNumber;
    char borrowType;
    char title[80];
    authors_t author;
    unsigned int releaseYear;
    char publisher[30];
    keywords_t keywords;
    loaningData_t loaningData;
} book_t;

typedef struct bookNode_t
{
    book_t bookData;

    struct bookNode_t *next;
} bookNode_t;

/// Menu Functions
void displayMainMenu();
char getMenuOption(int x, int y);
void handleMenuOption(char option, bookNode_t **head);
void displayCurrentFile(char currentFile[], int x, int y);

/// Basic List Functions
void pushElement(book_t data, bookNode_t **head);
void appendElement(book_t data, bookNode_t **head);
void insertElement(unsigned int index, book_t data, bookNode_t **head);
void deleteElement(unsigned int index, bookNode_t **head);
void deleteFirstElement(bookNode_t **head);

/// Print Books
void printBooks(bookNode_t **head);
void printBookData(book_t book);

/// READ-ONLY bookNode_t funtions
int bookCount(bookNode_t **head);
int isBookNumberUnique(unsigned int bookNumber, bookNode_t **head);
book_t getBookWithBookNumber(int bookNumber, bookNode_t **head);

/// EDIT bookNode_t functions
void removeBook(bookNode_t **head);
void addBook(bookNode_t **head);
void addLoaningInfo(bookNode_t **head);

/// Search functions
void searchAuthor(bookNode_t **head);
void searchKeyword(bookNode_t **head);

bookNode_t* getBooksWithAuthor(char author[40], bookNode_t **head);
bookNode_t* getBooksWithKeyword(char keyword[35], bookNode_t **head);

int hasAuthor(char author[], authors_t authors);
int hasKeyword(char keyword[], keywords_t keywords);
int findIndexWithBookNumber(unsigned int bookNumber, bookNode_t **head);

/// File functions
bookNode_t* importBookFile(char filename[]);
void exportBookFile(char filename[], bookNode_t **head);

void getCurrentFile(char currentFile[]);
void updateCurrentFile(char *currentFile);

void createFile();
void createBackUp(bookNode_t **head);
void loadFile(bookNode_t **head);

int getLineCount(char filename[]);

void startupSetup();
void setupNewLine(int x, int *y);

int main()
{
    bookNode_t *books = NULL;

    char currentFile[100];

    startupSetup();

    getCurrentFile(currentFile);

    books = importBookFile(currentFile);

    while (1)
    {
        displayMainMenu();
        displayCurrentFile(currentFile,10, 55);
        handleMenuOption(getMenuOption(100, 13), &books);
        exportBookFile(currentFile, &books);
        getCurrentFile(currentFile);
    }

    return EXIT_SUCCESS;
}

/// This function makes sure that there is a file available to store the bookNode_t list
/// if files are unavailable, new blank files will be created
void startupSetup()
{
    FILE *fp;

    mkdir("startup");

    char currentFile[100];
    getCurrentFile(currentFile);

    if (access(LASTUSED, F_OK) == 0 && access(currentFile, F_OK) == 0)
        return;

    /// Creates the default file "biblio.dat", if no other file is present

    fp = fopen(LASTUSED, "wb");
    fwrite("biblio.dat", 11, 1, fp);
    fclose(fp);

    if (access("biblio.dat", F_OK) == 0)
        return;

    fp = fopen("biblio.dat", "wt");
    fclose(fp);
}

/// updates LASTUSED to the currently used file
void updateCurrentFile(char *currentFile)
{
    FILE *fp;

    fp = fopen(LASTUSED, "wb");

    fwrite(currentFile, 100, 1, fp);

    fclose(fp);
}

/// Gets the currently used file
void getCurrentFile(char currentFile[])
{
    FILE *fp;

    fp = fopen(LASTUSED, "rb");

    fread(currentFile, 100, 1, fp);

    fclose(fp);
}

/// Creates a copy of the current list in a new file
void createBackUp(bookNode_t **head)
{
    char filename[100];
    int currentLine = 2;

    printf("------------------------------------Create a backup-------------------------------------\n");
    setupNewLine(3, &currentLine);
    printf("Create file: ");
    gotoxy(16, 2);

    textcolor(INPUTCOLOR);
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;
    textcolor(DEFAULTCOLOR);

    if (strcmp(filename, "") == 0)
    {
        gotoxy(1, 4);
        textcolor(ERRORCOLOR);
        printf("Invalid filename!\n");
        textcolor(DEFAULTCOLOR);
        return;
    }

    gotoxy(1, 4);
    exportBookFile(filename, head);

    textcolor(OKCOLOR);
    printf("Backup created at '%s'.\n", filename);
    textcolor(DEFAULTCOLOR);
}

/// Creates a new file
void createFile()
{
    char filename[100];
    int currentLine = 2;

    printf("------------------------------------Create a file---------------------------------------\n");
    setupNewLine(3, &currentLine);
    printf("Create file: ");
    gotoxy(16, 2);

    textcolor(INPUTCOLOR);
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;
    textcolor(DEFAULTCOLOR);

    gotoxy(1, 4);

    FILE *fp;

    fp = fopen(filename, "wt");

    textcolor(OKCOLOR);
    printf("File created at '%s'.\n", filename);
    textcolor(DEFAULTCOLOR);
}

/// sets a new file to be used
void loadFile(bookNode_t **head)
{
    int currentLine = 2;
    char filename[100];

    printf("--------------------------------------Load a file---------------------------------------\n");
    setupNewLine(3, &currentLine);
    printf("Choose file: ");
    gotoxy(16, 2);

    textcolor(INPUTCOLOR);
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;
    textcolor(DEFAULTCOLOR);

    gotoxy(1, 4);

    if (access(filename, F_OK) == -1)
    {
        textcolor(ERRORCOLOR);
        printf("No file '%s' found.\n", filename);
        textcolor(DEFAULTCOLOR);
        return;
    }

    *head = importBookFile(filename);

    updateCurrentFile(filename);

    textcolor(OKCOLOR);
    printf("Backup '%s' loaded.\n", filename);
    textcolor(DEFAULTCOLOR);
}

/// displays the currently used file to the user
void displayCurrentFile(char currentFile[], int x, int y)
{
    gotoxy(x, y);

    textcolor(WARNINGCOLOR);

    printf("------------current file----------");
    gotoxy(x, y + 1);
    printf("| %-31s|", currentFile);
    gotoxy(x, y + 2);
    printf("----------------------------------");

    textcolor(DEFAULTCOLOR);
}

/// displays the main menu
void displayMainMenu()
{
    system("cls");
    textcolor(DEFAULTCOLOR);
    printf(" ------------------------------------Main Menu-------------------------------------------\n");
    printf(" |\t- Create new file (c)                                                           |\n");
    printf(" |                                                                                      |\n");
    printf(" |\t- Create backup (b)                                                             |\n");
    printf(" |                                                                                      |\n");
    printf(" |\t- Load file (n)                                                                 |\n");
    printf(" |                                                                                      |\n");
    printf(" |\t- Quit (q)                                                                      |\n");
    printf(" ------------------------------------Library---------------------------------------------\n");
    printf(" |\t- View Library (t)                                                              |\n");
    printf(" |                                                                                      |\n");
    printf(" |\t- Add a new Book (a)                                                            |\n");
    printf(" |                                                                                      |\n");
    printf(" |\t- Remove a Book (r)                                                             |\n");
    printf(" |                                                                                      |\n");
    printf(" |\t- Loan entry (l)                                                                |\n");
    printf(" --------------------------------------Search--------------------------------------------\n");
    printf(" |\t- Search for author (1)                                                         |\n");
    printf(" |                                                                                      |\n");
    printf(" |\t- Search for keyword (2)                                                        |\n");
    printf(" ----------------------------------------------------------------------------------------\n");
}

/// displays a square prompt where the user can select a menu option
char getMenuOption(int x, int y)
{
    gotoxy(x - 5, y - 2);

    textcolor(WARNINGCOLOR);

    printf("-----------");
    gotoxy(x - 5, y - 1);
    printf("|         |");
    gotoxy(x - 5, y);
    printf("|         |");
    gotoxy(x - 5, y + 1);
    printf("|         |");
    gotoxy(x - 5, y + 2);
    printf("-----------");

    textcolor(DEFAULTCOLOR);

    gotoxy(x, y);

    return tolower(getch());
}

/// calls the functions of each menu option
void handleMenuOption(char option, bookNode_t **head)
{
    switch (option)
    {
        case ('q'):
            system("cls");
            textcolor(OKCOLOR);
            exit(EXIT_SUCCESS);
        case ('b'):
            system("cls");
            createBackUp(head);
            printf("Press any key to continue\n");
            getch();
            break;
        case ('c'):
            system("cls");
            createFile();
            printf("Press any key to continue\n");
            getch();
            break;
        case ('n'):
            system("cls");
            loadFile(head);
            printf("Press any key to continue\n");
            getch();
            break;
        case ('t'):
            system("cls");
            printBooks(head);
            printf("Press any key to continue\n");
            getch();
            break;
        case ('a'):
            system("cls");
            addBook(head);
            printf("Press any key to continue\n");
            getch();
            break;
        case ('r'):
            system("cls");
            removeBook(head);
            printf("Press any key to continue\n");
            getch();
            break;
        case ('l'):
            system("cls");
            addLoaningInfo(head);
            printf("Press any key to continue\n");
            getch();
            break;
        case ('1'):
            system("cls");
            searchAuthor(head);
            printf("Press any key to continue\n");
            getch();
            break;
        case ('2'):
            system("cls");
            searchKeyword(head);
            printf("Press any key to continue\n");
            getch();
            break;
    }
}

/// prints all books of user selected author
void searchAuthor(bookNode_t **head)
{
    char author[40];
    bookNode_t *booksWithAuthor = NULL;
    int currentLine = 2;

    printf("------------------------------------Search for an author--------------------------------\n");
    setupNewLine(3, &currentLine);
    printf("Author: ");
    gotoxy(11, 2);

    textcolor(INPUTCOLOR);
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = 0;
    textcolor(DEFAULTCOLOR);

    booksWithAuthor = getBooksWithAuthor(author, head);

    if (booksWithAuthor == NULL)
    {
        gotoxy(1, 4);
        textcolor(ERRORCOLOR);
        printf("No books from '%s' found.\n", author);
        textcolor(DEFAULTCOLOR);
    }
    else
    {
        system("cls");
        printBooks(&booksWithAuthor);
    }
}

/// prints books with user selected keyword
void searchKeyword(bookNode_t **head)
{
    char keyword[35];
    bookNode_t *booksWithKeyword = NULL;
    int currentLine = 2;

    printf("------------------------------------Search for books with keyword-----------------------\n");
    setupNewLine(3, &currentLine);
    printf("Keyword: ");
    gotoxy(12, 2);

    textcolor(INPUTCOLOR);
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = 0;
    textcolor(DEFAULTCOLOR);

    booksWithKeyword = getBooksWithKeyword(keyword, head);

    if (booksWithKeyword == NULL)
    {
        gotoxy(1, 4);
        textcolor(ERRORCOLOR);
        printf("No books with keyword '%s' found.\n", keyword);
        textcolor(DEFAULTCOLOR);
    }

    else
    {
        system("cls");
        printBooks(&booksWithKeyword);
    }
}

/// allows the user to add a new book to the list
void addBook(bookNode_t **head)
{
    book_t newBook;
    char tempString[100];
    char *eptr = NULL;
    unsigned int currentLine = 2;

    printf("------------------------------------Create a new entry----------------------------------\n");
    setupNewLine(3, &currentLine);
    printf("Book Title: ");
    textcolor(INPUTCOLOR);
    fgets(newBook.title, sizeof(newBook.title), stdin);
    textcolor(DEFAULTCOLOR);
    newBook.title[strcspn(newBook.title, "\n")] = 0;
    setupNewLine(3, &currentLine);
    textcolor(OKCOLOR);
    printf("Book Title '%s' added.\n", newBook.title);
    textcolor(DEFAULTCOLOR);

    setupNewLine(3, &currentLine);
    printf("Author: ");
    textcolor(INPUTCOLOR);
    fgets(newBook.author.author, sizeof(newBook.author.author), stdin);
    textcolor(DEFAULTCOLOR);
    newBook.author.author[strcspn(newBook.author.author, "\n")] = 0;
    setupNewLine(3, &currentLine);
    textcolor(OKCOLOR);
    printf("Author '%s' added.\n", newBook.author.author);
    textcolor(DEFAULTCOLOR);

    setupNewLine(3, &currentLine);
    printf("Co-Author: ");
    textcolor(INPUTCOLOR);
    fgets(newBook.author.coAuthor, sizeof(newBook.author.coAuthor), stdin);
    textcolor(DEFAULTCOLOR);
    newBook.author.coAuthor[strcspn(newBook.author.coAuthor, "\n")] = 0;
    setupNewLine(3, &currentLine);
    textcolor(OKCOLOR);
    printf("Co-Author '%s' added.\n", newBook.author.coAuthor);
    textcolor(DEFAULTCOLOR);

    setupNewLine(3, &currentLine);
    printf("Release year: ");
    textcolor(INPUTCOLOR);
    fgets(tempString, sizeof(tempString), stdin);
    textcolor(DEFAULTCOLOR);
    newBook.releaseYear = (int)strtol(tempString, &eptr, 10);
    setupNewLine(3, &currentLine);
    textcolor(OKCOLOR);
    printf("Release Year '%d' added.\n", newBook.releaseYear);
    textcolor(DEFAULTCOLOR);

    setupNewLine(3, &currentLine);
    printf("Publisher: ");
    textcolor(INPUTCOLOR);
    fgets(newBook.publisher, sizeof(newBook.publisher), stdin);
    textcolor(DEFAULTCOLOR);
    newBook.publisher[strcspn(newBook.publisher, "\n")] = 0;
    setupNewLine(3, &currentLine);
    textcolor(OKCOLOR);
    printf("Publisher '%s' added.\n", newBook.publisher);
    textcolor(DEFAULTCOLOR);

    int unique = 0;

    setupNewLine(3, &currentLine);

    do
    {
        printf("Book number: ");
        textcolor(INPUTCOLOR);
        fgets(tempString, sizeof(tempString), stdin);
        textcolor(DEFAULTCOLOR);
        newBook.bookNumber = (int)strtol(tempString, &eptr, 10);

        unique = isBookNumberUnique(newBook.bookNumber, head);

        if (unique == 0)
        {
            gotoxy(3, currentLine - 1);
            textcolor(WARNINGCOLOR);
            printf("                             Book number must be unique!");
            textcolor(DEFAULTCOLOR);
            gotoxy(3, currentLine - 1);
        }
        else
        {
            setupNewLine(3, &currentLine);
            textcolor(OKCOLOR);
            printf("Book number '%d' added.\n", newBook.bookNumber);
            textcolor(DEFAULTCOLOR);
        }
    }
    while (unique == 0);

    setupNewLine(3, &currentLine);
    printf("Keywords: \n");
    setupNewLine(3, &currentLine);
    printf(" - ");
    textcolor(INPUTCOLOR);
    fgets(newBook.keywords.keyword1, sizeof(newBook.keywords.keyword1), stdin);
    textcolor(DEFAULTCOLOR);
    newBook.keywords.keyword1[strcspn(newBook.keywords.keyword1, "\n")] = 0;
    setupNewLine(3, &currentLine);
    printf(" - ");
    textcolor(INPUTCOLOR);
    fgets(newBook.keywords.keyword2, sizeof(newBook.keywords.keyword2), stdin);
    textcolor(DEFAULTCOLOR);
    newBook.keywords.keyword2[strcspn(newBook.keywords.keyword2, "\n")] = 0;
    setupNewLine(3, &currentLine);
    printf(" - ");
    textcolor(INPUTCOLOR);
    fgets(newBook.keywords.keyword3, sizeof(newBook.keywords.keyword3), stdin);
    textcolor(DEFAULTCOLOR);
    newBook.keywords.keyword3[strcspn(newBook.keywords.keyword3, "\n")] = 0;
    setupNewLine(3, &currentLine);
    textcolor(OKCOLOR);
    printf("Keywords '%s', '%s', '%s' added.\n", newBook.keywords.keyword1, newBook.keywords.keyword2, newBook.keywords.keyword3);
    textcolor(DEFAULTCOLOR);
    printf("----------------------------------------------------------------------------------------\n");

    strcpy(newBook.loaningData.id, "");
    strcpy(newBook.loaningData.homeAddress.city, "");
    strcpy(newBook.loaningData.homeAddress.streetWithHousenumber, "");
    newBook.loaningData.homeAddress.ZIP = 0;
    strcpy(newBook.loaningData.name.familyName, "");
    strcpy(newBook.loaningData.name.firstName, "");
    newBook.borrowType = ' ';
    newBook.loaningData.returnDate.day = 0;
    newBook.loaningData.returnDate.month = 0;
    newBook.loaningData.returnDate.year = 0;

    getch();
    system("cls");

    printBookData(newBook);

    printf("Add this book? y \\ n \n");

    if (getch() == 'y')
    {
        appendElement(newBook, head);
        textcolor(OKCOLOR);
        printf("Book added!\n");
        textcolor(DEFAULTCOLOR);
    }
    else
    {
        printf("Okay, nothing was done.\n");
    }
}

/// adds loaning info to an existing book
/// separate from addBook() to fit in a unedited cmd window --> makes the "expanding box effect" possible
void addLoaningInfo(bookNode_t **head)
{
    char tempString[100];
    char *eptr = NULL;
    int currentLine = 2;
    bookNode_t *current = *head;

    printf("----------------------------------Add loan----------------------------------------------\n");
    setupNewLine(3, &currentLine);
    printf("Book number of book: ");
    gotoxy(24, 2);

    textcolor(INPUTCOLOR);
    fgets(tempString, sizeof(tempString), stdin);
    textcolor(DEFAULTCOLOR);
    int bookNumber = (int)strtol(tempString, &eptr, 10);

    int index = findIndexWithBookNumber(bookNumber, head);

    if (index == -1)
    {
        textcolor(ERRORCOLOR);
        gotoxy(1, 4);
        printf("ERROR: No element with bookNumber '%d' exists.\n", bookNumber);
        textcolor(DEFAULTCOLOR);
        return;
    }

    int i;
    for (i = 0; i < index; i++)
    {
        current = current->next;
    }

    book_t tempBook = current->bookData;

    currentLine+=2;
    printf("\n----------------------------------------------------------------------------------------\n");

    setupNewLine(3, &currentLine);
    printf("Loaning ID: ");
    textcolor(INPUTCOLOR);
    fgets(tempBook.loaningData.id, sizeof(tempBook.loaningData.id), stdin);
    textcolor(DEFAULTCOLOR);
    tempBook.loaningData.id[strcspn(tempBook.loaningData.id, "\n")] = 0;
    setupNewLine(3, &currentLine);
    textcolor(OKCOLOR);
    printf("Loaning ID '%s' added.\n", tempBook.loaningData.id);
    textcolor(DEFAULTCOLOR);

    setupNewLine(3, &currentLine);
    printf("Loaner first name: ");
    textcolor(INPUTCOLOR);
    fgets(tempBook.loaningData.name.firstName, sizeof(tempBook.loaningData.name.firstName), stdin);
    textcolor(DEFAULTCOLOR);
    tempBook.loaningData.name.firstName[strcspn(tempBook.loaningData.name.firstName, "\n")] = 0;
    setupNewLine(3, &currentLine);
    textcolor(OKCOLOR);
    printf("First name '%s' added.\n", tempBook.loaningData.name.firstName);
    textcolor(DEFAULTCOLOR);

    setupNewLine(3, &currentLine);
    printf("Loaner family name: ");
    textcolor(INPUTCOLOR);
    fgets(tempBook.loaningData.name.familyName, sizeof(tempBook.loaningData.name.familyName), stdin);
    textcolor(DEFAULTCOLOR);
    tempBook.loaningData.name.familyName[strcspn(tempBook.loaningData.name.familyName, "\n")] = 0;
    setupNewLine(3, &currentLine);
    textcolor(OKCOLOR);
    printf("Family name '%s' added.\n", tempBook.loaningData.name.familyName);
    textcolor(DEFAULTCOLOR);

    setupNewLine(3, &currentLine);
    printf("Loaner address: \n");
    setupNewLine(3, &currentLine);
    printf(" - Street with housenumber: ");
    textcolor(INPUTCOLOR);
    fgets(tempBook.loaningData.homeAddress.streetWithHousenumber, sizeof(tempBook.loaningData.homeAddress.streetWithHousenumber), stdin);
    textcolor(DEFAULTCOLOR);
    tempBook.loaningData.homeAddress.streetWithHousenumber[strcspn(tempBook.loaningData.homeAddress.streetWithHousenumber, "\n")] = 0;

    setupNewLine(3, &currentLine);
    printf(" - ZIP code: ");
    textcolor(INPUTCOLOR);
    fgets(tempString, sizeof(tempString), stdin);
    textcolor(DEFAULTCOLOR);
    tempBook.loaningData.homeAddress.ZIP = (int)strtol(tempString, &eptr, 10);

    setupNewLine(3, &currentLine);
    printf(" - City: ");
    textcolor(INPUTCOLOR);
    fgets(tempBook.loaningData.homeAddress.city, sizeof(tempBook.loaningData.homeAddress.city), stdin);
    textcolor(DEFAULTCOLOR);
    tempBook.loaningData.homeAddress.city[strcspn(tempBook.loaningData.homeAddress.city, "\n")] = 0;

    setupNewLine(3, &currentLine);
    textcolor(OKCOLOR);
    printf("Loaner address '%s %d %s' added.\n", tempBook.loaningData.homeAddress.streetWithHousenumber, tempBook.loaningData.homeAddress.ZIP, tempBook.loaningData.homeAddress.city);
    textcolor(DEFAULTCOLOR);

    setupNewLine(3, &currentLine);
    printf("Borrow type: ");
    textcolor(INPUTCOLOR);
    fgets(tempString, sizeof(tempString), stdin);
    textcolor(DEFAULTCOLOR);
    tempBook.borrowType = tempString[0];
    if (tempBook.borrowType == '\n')
       tempBook.borrowType = ' ';
    setupNewLine(3, &currentLine);
    textcolor(OKCOLOR);
    printf("Borrow type '%c' added.\n", tempBook.borrowType);
    textcolor(DEFAULTCOLOR);

    setupNewLine(3, &currentLine);
    printf("Return by date: \n");

    setupNewLine(3, &currentLine);
    printf(" - YYYY: ");
    textcolor(INPUTCOLOR);
    fgets(tempString, sizeof(tempString), stdin);
    textcolor(DEFAULTCOLOR);
    tempBook.loaningData.returnDate.year = (int)strtol(tempString, &eptr, 10);
    if (tempBook.loaningData.returnDate.year > 9999)
        tempBook.loaningData.returnDate.year = 0;

    setupNewLine(3, &currentLine);
    printf(" - MM: ");
    textcolor(INPUTCOLOR);
    fgets(tempString, sizeof(tempString), stdin);
    textcolor(DEFAULTCOLOR);
    tempBook.loaningData.returnDate.month = (int)strtol(tempString, &eptr, 10);
    if (tempBook.loaningData.returnDate.month > 12)
        tempBook.loaningData.returnDate.month = 0;

    setupNewLine(3, &currentLine);
    printf(" - DD: ");
    textcolor(INPUTCOLOR);
    fgets(tempString, sizeof(tempString), stdin);
    textcolor(DEFAULTCOLOR);
    tempBook.loaningData.returnDate.day = (int)strtol(tempString, &eptr, 10);
    if (tempBook.loaningData.returnDate.day > 31)
        tempBook.loaningData.returnDate.day = 0;

    setupNewLine(3, &currentLine);
    textcolor(OKCOLOR);
    printf("Return date '%4d/%2d/%2d' added.\n", tempBook.loaningData.returnDate.year, tempBook.loaningData.returnDate.month, tempBook.loaningData.returnDate.day);
    textcolor(DEFAULTCOLOR);

    getch();
    system("cls");

    printBookData(tempBook);

    printf("Update this book? y \\ n \n");

    if (getch() == 'y')
    {
        current->bookData = tempBook;

        textcolor(OKCOLOR);
        printf("Book updated!\n");
        textcolor(DEFAULTCOLOR);
    }
    else
    {
        printf("Okay, nothing was done.\n");
    }
}

/// returns 1 if the book numbe is unique, 0 if not
int isBookNumberUnique(unsigned int bookNumber, bookNode_t **head)
{
    bookNode_t *current = *head;

    while (current != NULL)
    {
        if (current->bookData.bookNumber == bookNumber)
            return 0;

        current = current->next;
    }

    return 1;
}

/// gets all books from an author and appends them to a new list that gets returned
bookNode_t* getBooksWithAuthor(char author[40], bookNode_t **head)
{
    bookNode_t *current = *head;
    bookNode_t *booksFromAuthor = NULL;

    while (current != NULL)
    {
        if (hasAuthor(author, current->bookData.author))
        {
            appendElement(current->bookData, &booksFromAuthor);
        }

        current = current->next;
    }

    return booksFromAuthor;
}

/// returns 1 if a book has selected author
int hasAuthor(char author[], authors_t authors)
{
    if ((strcmp(authors.author, author) == 0) || (strcmp(authors.coAuthor, author) == 0))
        return 1;
    return 0;
}

/// removes a user selected book from the list
void removeBook(bookNode_t **head)
{
    char temp[100];
    char *eptr = NULL;
    int currentLine = 2;

    printf("------------------------------------Remove a book---------------------------------------\n");
    setupNewLine(3, &currentLine);
    printf("Book number of book: ");
    gotoxy(24, 2);
    textcolor(INPUTCOLOR);
    fgets(temp, sizeof(temp), stdin);
    textcolor(DEFAULTCOLOR);
    int bookNumber = (int)strtol(temp, &eptr, 10);

    int index = findIndexWithBookNumber(bookNumber, head);

    if (index == -1)
    {
        textcolor(ERRORCOLOR);
        gotoxy(1, 4);
        printf("ERROR: No element with bookNumber '%d' exists.\n", bookNumber);
        textcolor(DEFAULTCOLOR);
        return;
    }

    deleteElement(index, head);

    gotoxy(1, currentLine + 1);
    textcolor(OKCOLOR);
    printf("Book '%d' deleted.\n",  bookNumber);
    textcolor(DEFAULTCOLOR);
}

/// returns the index of a book in the lost
int findIndexWithBookNumber(unsigned int bookNumber, bookNode_t **head)
{
    bookNode_t *current = *head;
    int index = 0;

    while (current != NULL)
    {
        if (current->bookData.bookNumber != bookNumber)
        {
            current = current->next;
            index++;
        }
        else
            break;
    }

    if (current == NULL)
        return -1;

    return index;
}

/// gets all books with a keyboard and appends them to a new list that gets returned
bookNode_t* getBooksWithKeyword(char keyword[35], bookNode_t **head)
{
    bookNode_t *current = *head;
    bookNode_t *booksWithKeyword = NULL;

    while (current != NULL)
    {
        if (hasKeyword(keyword, current->bookData.keywords))
        {
            appendElement(current->bookData, &booksWithKeyword);
        }

        current = current->next;
    }

    return booksWithKeyword;
}

/// returns 1 if a book has given keyword
int hasKeyword(char keyword[], keywords_t keywords)
{
    if ((strcmp(keywords.keyword1, keyword) == 0) || (strcmp(keywords.keyword2, keyword) == 0) || (strcmp(keywords.keyword3, keyword) == 0))
        return 1;
    return 0;
}

/// prints all book_t elements of a bookNode_t list
void printBooks(bookNode_t **head)
{
    bookNode_t *current = *head;

    while (current != NULL)
    {
        printBookData(current->bookData);
        current = current->next;
    }
}

/// prints out a book_t element
void printBookData(book_t book)
{
    printf("-------------------------------- BOOK INFO -------------------------------------\n");
    printf("| Book Title: %-65s|\n", book.title);
    printf("| Author(s):                                                                   |\n");
    printf("| \t- %-69s|\n", book.author.author);
    printf("| \t- %-69s|\n", book.author.coAuthor);
    printf("| Released in: %-64d|\n", book.releaseYear);
    printf("| Published by: %-63s|\n", book.publisher);
    printf("|------------------------------ LIBRARY INFO ----------------------------------|\n");
    printf("| Book Number: %-64d|\n", book.bookNumber);
    printf("| Keywords:                                                                    |\n");
    printf("| \t- %-69s|\n", book.keywords.keyword1);
    printf("| \t- %-69s|\n", book.keywords.keyword2);
    printf("| \t- %-69s|\n", book.keywords.keyword3);
    printf("|------------------------------ LOANING INFO ----------------------------------|\n");
    printf("| ID: %-73s|\n", book.loaningData.id);
    printf("| Loaner: %34s %-34s|\n", book.loaningData.name.firstName, book.loaningData.name.familyName);
    printf("| Loaner Address: %-20s %-20s %-19d|\n", book.loaningData.homeAddress.streetWithHousenumber, book.loaningData.homeAddress.city, book.loaningData.homeAddress.ZIP);
    printf("| Borrow Type: %c                                                               |\n", book.borrowType);
    printf("| Return by: %4d/%2d/%-58d|\n", book.loaningData.returnDate.year, book.loaningData.returnDate.month, book.loaningData.returnDate.day);
    printf("--------------------------------------------------------------------------------\n\n\n\n\n\n");
}

/// returns the amount of books in the list
int bookCount(bookNode_t **head)
{
    bookNode_t *current = *head;
    int i = 0;

    while (current != NULL)
    {
        i++;
        current = current->next;
    }

    return i;
}

/// returns a bookNode_t list from a file
bookNode_t* importBookFile(char filename[])
{
    bookNode_t *importedBooks = NULL;
    FILE *fp;

    fp = fopen(filename, "rt");

    if (fp == NULL)
    {
        textcolor(ERRORCOLOR);
        printf("ERROR: Couldn't open %s!\n", filename);
        textcolor(DEFAULTCOLOR);
        exit(EXIT_FAILURE);
    }

    char currentLine[100];
    int i;

    for (i = 0; i < (getLineCount(filename) / 19); i++)
    {
        book_t tempBook;
        char *eptr = NULL;

        fgets(currentLine, sizeof(currentLine), fp);
        currentLine[strcspn(currentLine, "\n")] = 0;
        tempBook.bookNumber = (int)strtol(currentLine, &eptr, 10);

        fgets(currentLine, sizeof(currentLine), fp);
        currentLine[strcspn(currentLine, "\n")] = 0;
        tempBook.borrowType = currentLine[0];

        fgets(currentLine, sizeof(currentLine), fp);
        currentLine[strcspn(currentLine, "\n")] = 0;
        strcpy(tempBook.title, currentLine);

        fgets(currentLine, sizeof(currentLine), fp);
        currentLine[strcspn(currentLine, "\n")] = 0;
        strcpy(tempBook.author.author, currentLine);

        fgets(currentLine, sizeof(currentLine), fp);
        currentLine[strcspn(currentLine, "\n")] = 0;
        strcpy(tempBook.author.coAuthor, currentLine);

        fgets(currentLine, sizeof(currentLine), fp);
        currentLine[strcspn(currentLine, "\n")] = 0;
        tempBook.releaseYear = (int)strtol(currentLine, &eptr, 10);

        fgets(currentLine, sizeof(currentLine), fp);
        currentLine[strcspn(currentLine, "\n")] = 0;
        strcpy(tempBook.publisher, currentLine);

        fgets(currentLine, sizeof(currentLine), fp);
        currentLine[strcspn(currentLine, "\n")] = 0;
        strcpy(tempBook.keywords.keyword1, currentLine);

        fgets(currentLine, sizeof(currentLine), fp);
        currentLine[strcspn(currentLine, "\n")] = 0;
        strcpy(tempBook.keywords.keyword2, currentLine);

        fgets(currentLine, sizeof(currentLine), fp);
        currentLine[strcspn(currentLine, "\n")] = 0;
        strcpy(tempBook.keywords.keyword3, currentLine);

        fgets(currentLine, sizeof(currentLine), fp);
        currentLine[strcspn(currentLine, "\n")] = 0;
        strcpy(tempBook.loaningData.id, currentLine);

        fgets(currentLine, sizeof(currentLine), fp);
        currentLine[strcspn(currentLine, "\n")] = 0;
        strcpy(tempBook.loaningData.name.familyName, currentLine);

        fgets(currentLine, sizeof(currentLine), fp);
        currentLine[strcspn(currentLine, "\n")] = 0;
        strcpy(tempBook.loaningData.name.firstName, currentLine);

        fgets(currentLine, sizeof(currentLine), fp);
        currentLine[strcspn(currentLine, "\n")] = 0;
        strcpy(tempBook.loaningData.homeAddress.streetWithHousenumber, currentLine);

        fgets(currentLine, sizeof(currentLine), fp);
        currentLine[strcspn(currentLine, "\n")] = 0;
        tempBook.loaningData.homeAddress.ZIP = (int)strtol(currentLine, &eptr, 10);

        fgets(currentLine, sizeof(currentLine), fp);
        currentLine[strcspn(currentLine, "\n")] = 0;
        strcpy(tempBook.loaningData.homeAddress.city, currentLine);

        fgets(currentLine, sizeof(currentLine), fp);
        currentLine[strcspn(currentLine, "\n")] = 0;
        tempBook.loaningData.returnDate.day = (int)strtol(currentLine, &eptr, 10);

        fgets(currentLine, sizeof(currentLine), fp);
        currentLine[strcspn(currentLine, "\n")] = 0;
        tempBook.loaningData.returnDate.month = (int)strtol(currentLine, &eptr, 10);

        fgets(currentLine, sizeof(currentLine), fp);
        currentLine[strcspn(currentLine, "\n")] = 0;
        tempBook.loaningData.returnDate.year = (int)strtol(currentLine, &eptr, 10);

        appendElement(tempBook, &importedBooks);
    }

    fclose(fp);

    return importedBooks;
}

/// exports a bookNode_t list to a file
void exportBookFile(char filename[], bookNode_t **head)
{
    FILE *fp;
    bookNode_t *current = *head;

    fp = fopen(filename, "wt");

    if (fp == NULL)
    {
        textcolor(ERRORCOLOR);
        printf("ERROR: Couldn't open %s! Warning: Your book file is inaccessible. Changes might not be saved.\n", filename);
        textcolor(DEFAULTCOLOR);
        return;
    }

    while (current != NULL)
    {
        fprintf(fp, "%d\n", current->bookData.bookNumber);
        fprintf(fp, "%c\n", current->bookData.borrowType);
        fprintf(fp, "%s\n", current->bookData.title);
        fprintf(fp, "%s\n", current->bookData.author.author);
        fprintf(fp, "%s\n", current->bookData.author.coAuthor);
        fprintf(fp, "%d\n", current->bookData.releaseYear);
        fprintf(fp, "%s\n", current->bookData.publisher);
        fprintf(fp, "%s\n", current->bookData.keywords.keyword1);
        fprintf(fp, "%s\n", current->bookData.keywords.keyword2);
        fprintf(fp, "%s\n", current->bookData.keywords.keyword3);
        fprintf(fp, "%s\n", current->bookData.loaningData.id);
        fprintf(fp, "%s\n", current->bookData.loaningData.name.familyName);
        fprintf(fp, "%s\n", current->bookData.loaningData.name.firstName);
        fprintf(fp, "%s\n", current->bookData.loaningData.homeAddress.streetWithHousenumber);
        fprintf(fp, "%d\n", current->bookData.loaningData.homeAddress.ZIP);
        fprintf(fp, "%s\n", current->bookData.loaningData.homeAddress.city);
        fprintf(fp, "%d\n", current->bookData.loaningData.returnDate.day);
        fprintf(fp, "%d\n", current->bookData.loaningData.returnDate.month);
        fprintf(fp, "%d\n", current->bookData.loaningData.returnDate.year);

        current = current->next;
    }

    fclose(fp);
}

void pushElement(book_t data, bookNode_t **head)
{
    bookNode_t *newNode;

    if ((newNode = (bookNode_t *)malloc(sizeof(bookNode_t))) == NULL)
    {
        textcolor(ERRORCOLOR);
        printf("ERROR: Not enough memory available!\n");
        textcolor(DEFAULTCOLOR);
        exit(EXIT_FAILURE);
    }

    newNode->bookData = data;
    newNode->next = *head;
    *head = newNode;
}

void appendElement(book_t data, bookNode_t **head)
{
    bookNode_t *current = *head;

    ///if list is empty push new bookNode to front
    if (current == NULL)
    {
        pushElement(data, head);
        return;
    }

    ///Loops over each Node until it reaches the last one
    while (current->next != NULL)
    {
        current = current->next;
    }

    ///Creates new List Node
    if ((current->next = (bookNode_t *)malloc(sizeof(bookNode_t))) == NULL)
    {
        textcolor(ERRORCOLOR);
        printf("ERROR: Not enough memory available!\n");
        textcolor(DEFAULTCOLOR);
        exit(EXIT_FAILURE);
    }

    current->next->bookData = data;
    current->next->next = NULL;
}

void insertElement(unsigned int index, book_t data, bookNode_t **head)
{
    bookNode_t *current = *head;
    bookNode_t *temp;
    int i = 0;

    ///if list is empty push new node to front
    if (current == NULL || index == 0)
    {
        pushElement(data, head);
        return;
    }

    ///Loops over each Node until it reaches the last one
    while (current->next != NULL || i == index - 1)
    {
        if (i == index - 1)
            break;

        current = current->next;
        i++;
    }

    temp = current->next;

    ///Creates new List Node
    if ((current->next = (bookNode_t *)malloc(sizeof(bookNode_t))) == NULL)
    {
        textcolor(ERRORCOLOR);
        printf("ERROR: Not enough memory available!\n");
        textcolor(DEFAULTCOLOR);
        exit(EXIT_FAILURE);
    }

    current->next->bookData = data;
    current->next->next = temp;
}

void deleteFirstElement(bookNode_t **head)
{
    if (head == NULL)
        return;

    bookNode_t *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteElement(unsigned int index, bookNode_t **head)
{
    if (index == 0)
    {
        deleteFirstElement(head);
        return;
    }

    int i = 0;

    bookNode_t *current = *head;

    while (current != NULL && i < (index - 1))
    {
        current = current->next;
        i++;
    }

    bookNode_t *temp = current->next;

    current->next = (current->next)->next;

    free(temp);
}

int getLineCount(char filename[])
{
    int count = 0;
    char line[10000];

    FILE *fp;

    fp = fopen(filename, "rt");

    if (fp == NULL)
    {
        textcolor(ERRORCOLOR);
        printf("Error opening file: '%s'\n", filename);
        textcolor(DEFAULTCOLOR);
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
        count++;

    fclose(fp);

    return count;
}

/// sets up a new line for the "expanding box effect"
/// looks nice, could be made more modifiable (customizable line width or height) but it would require more effort to rewrite than is worth it
void setupNewLine(int x, int *y)
{
    printf("|                                                                                      |\n");
    gotoxy(1, *y + 1);
    printf("----------------------------------------------------------------------------------------\n");

    gotoxy(x, *y);
    (*y)++;
}
