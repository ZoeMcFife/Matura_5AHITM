/*************************************************************
*                                                            *
*                         ConFunc.h                          *
*                                                            *
*   turbo c console functions                                *
*                                                            *
*   by Lukas Schrittwieser                                   *
*   modifyed by Thomas Zirkler								 *
*                                                            *
*                                                            *
*************************************************************/


#ifndef _CONFUNC_
#define _CONFUNC_

#include <windows.h>
#include <conio.h>

typedef enum COLORS  {RED, LIGHTRED, GREEN, LIGHTGREEN, BLUE, LIGHTBLUE, YELLOW, DARKORANGE, CYAN, LIGHTCYAN, MAGENTA, LIGHTMAGENTA, WHITE, GRAY, BLACK};
enum COLORS bgcolor=BLACK, tcolor=WHITE, bg, text;


void backcolor(enum COLORS color);		// umstellen der Hintergrundfarbe
void textcolor(enum COLORS color);		// umstellen der Textfarbe
void clrscr();							// löscht den ganzen Schirm
void gotoxy(int x, int y);				// setzt Cursor an Position x , y



void gotoxy(int x, int y)
{
	COORD  Point={x-1,y-1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Point);
}

void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO ConsoleScreen;
    DWORD  charsWritten, nLength;
    COORD  start = { 0, 0 };

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleScreen);
    nLength = ConsoleScreen.dwSize.X * ConsoleScreen.dwSize.Y;
    FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', nLength, start, &charsWritten);
    gotoxy(1, 1);
}


void textcolor(enum COLORS color)
{
	WORD wColor;

	switch(bgcolor)			// festlegen der Hintergrundfarbe
	{
	case RED:			wColor=BACKGROUND_RED;
						break;
	case LIGHTRED:		wColor=BACKGROUND_RED | BACKGROUND_INTENSITY; 
						break;
	case GREEN:			wColor=BACKGROUND_GREEN; 
						break;
	case LIGHTGREEN:	wColor=BACKGROUND_GREEN | BACKGROUND_INTENSITY; 
						break;
	case BLUE:			wColor=BACKGROUND_BLUE; 
						break;
	case LIGHTBLUE:		wColor=BACKGROUND_BLUE | BACKGROUND_INTENSITY; 
						break;
	case DARKORANGE:	wColor=BACKGROUND_RED | BACKGROUND_GREEN; 
						break;
	case YELLOW:		wColor=BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY; 
						break;	
	case CYAN:			wColor=BACKGROUND_GREEN | BACKGROUND_BLUE; 
						break;
	case LIGHTCYAN:		wColor=BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY; 
						break;
	case MAGENTA:		wColor=BACKGROUND_RED | BACKGROUND_BLUE; 
						break;
	case LIGHTMAGENTA:	wColor=BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY; 
						break;
	case WHITE:			wColor=BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY; 
						break;
	case GRAY:			wColor=BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE; 
						break;
	case BLACK:			wColor=0; 
						break;
	}
	
	
	switch(color)			// setzt zusätlich Textfarbe
	{
	case RED:			wColor=wColor | FOREGROUND_RED;
						break;
	case LIGHTRED:		wColor=wColor | FOREGROUND_RED | FOREGROUND_INTENSITY; 
						break;
	case GREEN:			wColor=wColor | FOREGROUND_GREEN; 
						break;
	case LIGHTGREEN:	wColor=wColor | FOREGROUND_GREEN | FOREGROUND_INTENSITY; 
						break;
	case BLUE:			wColor=wColor | FOREGROUND_BLUE; 
						break;
	case LIGHTBLUE:		wColor=wColor | FOREGROUND_BLUE | FOREGROUND_INTENSITY; 
						break;
	case DARKORANGE:	wColor=wColor | FOREGROUND_RED | FOREGROUND_GREEN; 
						break;
	case YELLOW:		wColor=wColor | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY; 
						break;	
	case CYAN:			wColor=wColor | FOREGROUND_GREEN | FOREGROUND_BLUE; 
						break;
	case LIGHTCYAN:		wColor=wColor | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY; 
						break;
	case MAGENTA:		wColor=wColor | FOREGROUND_RED | FOREGROUND_BLUE; 
						break;
	case LIGHTMAGENTA:	wColor=wColor | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY; 
						break;
	case WHITE:			wColor=wColor | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY; 
						break;
	case GRAY:			wColor=wColor | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE; 
						break;
	case BLACK:			;				// Schwarz = nix
						break;
	}


	tcolor = color;		// neue Farbe aufheben
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}


void backcolor(enum COLORS color)
{
	WORD wColor;

	switch(tcolor)			// setzt  Textfarbe
	{
	case RED:			wColor=FOREGROUND_RED;
						break;
	case LIGHTRED:		wColor=FOREGROUND_RED | FOREGROUND_INTENSITY; 
						break;
	case GREEN:			wColor=FOREGROUND_GREEN; 
						break;
	case LIGHTGREEN:	wColor=FOREGROUND_GREEN | FOREGROUND_INTENSITY; 
						break;
	case BLUE:			wColor=FOREGROUND_BLUE; 
						break;
	case LIGHTBLUE:		wColor=FOREGROUND_BLUE | FOREGROUND_INTENSITY; 
						break;
	case DARKORANGE:	wColor=FOREGROUND_RED | FOREGROUND_GREEN; 
						break;
	case YELLOW:		wColor=FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY; 
						break;	
	case CYAN:			wColor=FOREGROUND_GREEN | FOREGROUND_BLUE; 
						break;
	case LIGHTCYAN:		wColor=FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY; 
						break;
	case MAGENTA:		wColor=FOREGROUND_RED | FOREGROUND_BLUE; 
						break;
	case LIGHTMAGENTA:	wColor=FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY; 
						break;
	case WHITE:			wColor=FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY; 
						break;
	case GRAY:			wColor=FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE; 
						break;
	case BLACK:			wColor=0;				// Schwarz = 0
						break;
	}

	switch(color)			// setzt zusätzlich Hintergrundfarbe
	{
	case RED:			wColor=wColor | BACKGROUND_RED;
						break;
	case LIGHTRED:		wColor=wColor | BACKGROUND_RED | BACKGROUND_INTENSITY; 
						break;
	case GREEN:			wColor=wColor | BACKGROUND_GREEN; 
						break;
	case LIGHTGREEN:	wColor=wColor | BACKGROUND_GREEN | BACKGROUND_INTENSITY; 
						break;
	case BLUE:			wColor=wColor | BACKGROUND_BLUE; 
						break;
	case LIGHTBLUE:		wColor=wColor | BACKGROUND_BLUE | BACKGROUND_INTENSITY; 
						break;
	case DARKORANGE:	wColor=wColor | BACKGROUND_RED | BACKGROUND_GREEN; 
						break;
	case YELLOW:		wColor=wColor | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY; 
						break;	
	case CYAN:			wColor=wColor | BACKGROUND_GREEN | BACKGROUND_BLUE; 
						break;
	case LIGHTCYAN:		wColor=wColor | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY; 
						break;
	case MAGENTA:		wColor=wColor | BACKGROUND_RED | BACKGROUND_BLUE; 
						break;
	case LIGHTMAGENTA:	wColor=wColor | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY; 
						break;
	case WHITE:			wColor=wColor | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY; 
						break;
	case GRAY:			wColor=wColor | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE; 
						break;
	case BLACK:			wColor=wColor;  
						break;
	}

	bgcolor=color;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}



#endif
