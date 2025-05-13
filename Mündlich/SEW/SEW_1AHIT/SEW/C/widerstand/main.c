#include <stdio.h>
#include <stdlib.h>

//Author:           Leonard Bunea
//Title:            Resistance Calculator
//Description:      Calculates Resistance of various circuit types
//Last Change:      2021/02/17

void serialResistance();
void parallelResistence();
void combindedResistence();
void userInputEnter();
void redrawMenu(char a, char b, char c, char d);

int main()
{
    char selectedMenu1 = '1', selectedMenu2 = '2', selectedMenu3 = '3', selected = '#', selectedMenu4 = '4';
    int currentSelection = 0;

    while(1)
    {
        //menu
        printf("-------------------------\n");
        printf("Resistance Calculator\n");
        printf("-------------------------\n");
        printf("[1] Serial Resistance   \n");
        printf("[2] Parallel Resistance \n");
        printf("[3] Combined Resistance\n");
        printf("[4] Exit \n");
        printf("-------------------------\n");

        scanf("%d", &currentSelection); //user selects a menu item

        //a switch to start functions.
        switch (currentSelection)
        {
        case 1:
            selectedMenu1 = selected;
            selectedMenu2 = '2';
            selectedMenu3 = '3';
            selectedMenu4 = '4';
            redrawMenu(selectedMenu1, selectedMenu2, selectedMenu3, selectedMenu4);
            serialResistance();
            break;
        case 2:
            selectedMenu2 = selected;
            selectedMenu1 = '1';
            selectedMenu3 = '3';
            selectedMenu4 = '4';
            redrawMenu(selectedMenu1, selectedMenu2, selectedMenu3, selectedMenu4);
            parallelResistence();
            break;
        case 3:
            selectedMenu3 = selected;
            selectedMenu2 = '2';
            selectedMenu1 = '1';
            selectedMenu4 = '4';
            redrawMenu(selectedMenu1, selectedMenu2, selectedMenu3, selectedMenu4);
            combindedResistence();
            break;
        case 4:
            selectedMenu4 = selected;
            selectedMenu2 = '2';
            selectedMenu3 = '3';
            selectedMenu1 = '1';
            redrawMenu(selectedMenu1, selectedMenu2, selectedMenu3, selectedMenu4);
            return EXIT_SUCCESS;
            break;
        default: //just clears the screen if invalid number was put in
            system("cls");
            break;
        }
    }
    return EXIT_SUCCESS;
}

void serialResistance()
{
    double resistance1, resistance2;

    printf("\n");
    printf("Serial Circuit: \n");
    printf("-------------------------\n");

    printf("\n");

    printf("    ┌────┐      ┌────┐\n");
    printf("────┤ R1 ├──────┤ R2 ├────\n");
    printf("    └────┘      └────┘ \n");


    printf("\n");

    printf("R1 (Ohm): ");
    scanf("%lf", &resistance1);
    fflush(stdin);
    printf("R2 (Ohm): ");
    scanf("%lf", &resistance2);

    printf("---------------------------\n");
    printf("Total Resistance: %.4lf Ohm \n", (resistance1 + resistance2));
    printf("---------------------------\n");
    printf("\n");
    userInputEnter();
    system("cls");
}


void parallelResistence()
{
    double resistance1, resistance2;

    printf("\n");
    printf("Parallel Circuit: \n");
    printf("-------------------------\n");

    printf("\n");
    printf("        ┌────┐          \n");
    printf("    ┌───┤ R1 ├───┐      \n");
    printf("    │   └────┘   │      \n");
    printf("────┤            ├──────\n");
    printf("    │   ┌────┐   │      \n");
    printf("    └───┤ R2 ├───┘      \n");
    printf("        └────┘          \n");
    printf("\n");

    printf("R1 (Ohm): ");
    scanf("%lf", &resistance1);
    fflush(stdin);
    printf("R2 (Ohm): ");
    scanf("%lf", &resistance2);

    printf("---------------------------\n");
    printf("Total Resistance: %.4lf Ohm\n", ((resistance1 * resistance2)/(resistance1 + resistance2)));
    printf("---------------------------\n");
    printf("\n");
    userInputEnter();
    system("cls");
}

void combindedResistence()
{
    double resistance1, resistance2, resistance3;

    printf("\n");
    printf("Combined Circuit: \n");
    printf("-------------------------\n");

    printf("\n");
    printf("        ┌────┐  ┌────┐       \n");
    printf("    ┌───┤ R1 ├──┤ R2 ├──┐      \n");
    printf("    │   └────┘  └────┘  │      \n");
    printf("────┤                   ├──────\n");
    printf("    │       ┌────┐      │      \n");
    printf("    └───────┤ R3 ├──────┘      \n");
    printf("            └────┘          \n");
    printf("\n");

    printf("R1 (Ohm): ");
    scanf("%lf", &resistance1);
    fflush(stdin);
    printf("R2 (Ohm): ");
    scanf("%lf", &resistance2);
    printf("R3 (Ohm): ");
    scanf("%lf", &resistance3);

    printf("---------------------------\n");
    printf("Total Resistance: %.4lf Ohm\n", (((resistance1 + resistance2) * resistance3)/((resistance1 + resistance2) + resistance3)));
    printf("---------------------------\n");
    printf("\n");
    userInputEnter();
    system("cls");
}

//continues if user inputs enter
void userInputEnter()
{
    printf("\nPress enter to continue . . . \n");
    char enter = 0; //makes program wait until user presses enter
    fflush(stdin);
    while (enter != '\r' && enter != '\n')
    {
        enter = getchar();
    }
}

//redraws the menu with the selected item
void redrawMenu(char a, char b, char c, char d)
{
    system("cls");
    printf("-------------------------\n");
    printf("Resistance Calculator\n");
    printf("-------------------------\n");
    printf("[%c] Serial Resistance   \n", a);
    printf("[%c] Parallel Resistance \n", b);
    printf("[%c] Combined Resistance\n", c);
    printf("[%c] Exit \n", d);
    printf("-------------------------\n");
}



