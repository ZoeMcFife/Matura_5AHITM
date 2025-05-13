#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person
{
    char name[10];
    int catalogNumber;
};

void getPerson(struct Person *p)
{
    int nr;
    char name[10];

    scanf("number %d", &nr);
    gets(name);

    *p->catalogNumber = nr;
    strcpy(*p->name, name);
}

void printPerson(struct Person person)
{
  printf("%d, %s", person.catalogNumber, person.name);
}

int main(int argc, char *argv[])
{
    struct Person person1;
    person1.catalogNumber = 69;
    strcpy(person1.name, "ZoZo");

    getPerson(person1);
    printPerson(person1);

    return EXIT_SUCCESS;
}
