#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "conioex.h"

//Title:        encryptor
//Author:       Leonard Bunea
//Description:  a simple text encryptor
//Last Change:  2021/02/09

int main()
{
    char plain = 0;
    long currentXPosPlain = 1, currentXPosCipher = 1;
    long currentYPosCipher = 11, currentYPosPlain = 2;

    //titles
    gotoxy(1, 1);
    printf("PLAIN TEXT:");

    gotoxy(1, 10);
    printf("ENCRYPTED TEXT:");

    while (plain != 27)
    {
        textcolor(YELLOW);
        gotoxy(currentXPosPlain, currentYPosPlain);
        currentXPosPlain++;

        plain = getche();

        gotoxy(currentXPosCipher, currentYPosCipher);
        textcolor(GREEN);

        //possible cases of input
        if (plain == ' ')
        {
            printf("00");
        }
        else if (isupper(plain)) //ist plain ein großbuchstabe
        {
            printf("%02d", plain - 64);
        }

        currentXPosCipher+=2;

        //makes a new line
        if (currentXPosCipher > 100)
        {
            currentYPosCipher++;
            currentXPosCipher = 1;
        }

        if (currentXPosPlain > 100)
        {
            currentYPosPlain++;
            currentXPosPlain = 1;
        }
    }

    return EXIT_SUCCESS;
}
