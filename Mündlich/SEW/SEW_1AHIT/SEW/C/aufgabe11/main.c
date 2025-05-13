#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "conioex.h"

//Title:        encryptor
//Author:       Leonard Bunea
//Description:  a text encryptor
//Last Change:  2021/02/23

char encryptCaesar(char plainChar, int key);
char encryptAtbash(char plainChar);
void encryptRot13(char plainChar, char *cipherChar);
void makeNewLine(long xpos, long ypos, long *newYpos, long *newXpos);


int main()
{
    char plain = 0;

    char rot13Cipher;
    int keyCaeser = 6;

    long currentXPosPlain = 1, currentYPosPlain = 2;
    long currentYPosCaeser = 15, currentXPosCaeser = 1;
    long currentYPosAtBash = 25, currentXPosAtBash = 1;
    long currentYPosRot13 = 35, currentXPosRot13 = 1;

    //titles
    gotoxy(1, currentXPosPlain - 1);
    printf("PLAIN TEXT:");

    gotoxy(1, currentYPosCaeser - 1);
    printf("ENCRYPTED WITH CAESER:");

    gotoxy(1, currentYPosAtBash - 1);
    printf("ENCRYPTED WITH ATBASH:");

    gotoxy(1, currentYPosRot13 - 1);
    printf("ENCRYPTED WITH ROT13:");

    while (plain != 27)
    {
        textcolor(YELLOW);
        gotoxy(currentXPosPlain, currentYPosPlain);
        currentXPosPlain++;

        plain = getche();

        //Caeser Cipher
        textcolor(GREEN);
        gotoxy(currentXPosCaeser, currentYPosCaeser);
        printf("%c", encryptCaesar(plain, keyCaeser));
        currentXPosCaeser++;

        //AtBash Cipher
        gotoxy(currentXPosAtBash, currentYPosAtBash);
        printf("%c", encryptAtbash(plain));
        currentXPosAtBash++;

        //Rot13 Cipher
        gotoxy(currentXPosRot13, currentYPosRot13);
        encryptRot13(plain, &rot13Cipher);
        printf("%c", rot13Cipher);
        currentXPosRot13++;

        //Functions for making new lines when necessary
        makeNewLine(currentXPosPlain, currentYPosPlain, &currentYPosPlain, &currentXPosPlain);
        makeNewLine(currentXPosCaeser, currentYPosCaeser, &currentYPosCaeser, &currentXPosCaeser);
        makeNewLine(currentXPosAtBash, currentYPosAtBash, &currentYPosAtBash, &currentXPosAtBash);
        makeNewLine(currentXPosRot13, currentYPosRot13, &currentYPosRot13, &currentXPosRot13);
    }

    return EXIT_SUCCESS;
}

char encryptCaesar(char plainChar, int key)
{
    char cipher = ' ';

    if (plainChar == ' ')
    {
        cipher = ' ';
    }
    else if (plainChar + key > 'Z')
    {
        plainChar = plainChar + key - 26;
        cipher = plainChar;
    }
    else
    {
        cipher = plainChar + key;
    }
    return cipher;
}

char encryptAtbash(char plainChar)
{
    char cipher = ' ';

    if (plainChar + 25 == 'Z')
    {
        cipher = 'Z';
    }
    else if (plainChar + 25 > 'Z')
    {
        cipher = plainChar + ('Z' - (plainChar + (plainChar - 'A')));
    }
    return cipher;
}

void encryptRot13(char plainChar,char *cipherChar)
{
    *cipherChar = encryptCaesar(plainChar, 13);
}

void makeNewLine(long xpos, long ypos, long *newYpos, long *newXpos)
{
    //150 works better when in fullscreen, but I'm limiting it to 100 to make it work in small window.
    if (xpos > 100)
    {
        xpos = 1;
        ypos++;

        *newYpos = ypos;
        *newXpos = xpos;
    }
}
