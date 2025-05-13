/*********************************************************************
              ____                      ,
  S          /---.'.__             ____//
  P               '--.\           /.---'
  I          _______  \\         //
  D        /.------.\  \|      .'/  ______
  E       //  ___  \ \ ||/|\  //  _/_----.\__
  R      |/  /.-.\  \ \:|< >|// _/.'..\   '--'
            //   \'. | \'.|.'/ /_/ /  \\
  G        //     \ \_\/" ' ~\-'.-'    \\
  A       //       '-._| :H: |'-.__     \\
  M      //           (/'==='\)'-._\     ||
  E      ||                        \\    \|
         ||                         \\    '
         |/                          \\
                                      ||
                                      ||
                                      \\
                                       '
**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define LINES 5                /* Bereich von 0 bis 9 */
#define DEPTH 8
#define DISTANCE 8

/*********************************************************************
  Funktionsprototypen
**********************************************************************/
void erzeugeZufallsfeld(int feld[DEPTH][LINES]);
void ausgabeFeld(int feld[DEPTH][LINES],int spider);
int check(int feld[DEPTH][LINES],int spider,int tipp);

void play(int *incorrectMoves);
void getPlayerName(char name[]);
void displayStats(int elapsedTime, int incorrectMoves);
void writeStatsToFile(char name[], int elapsedTime, int incorrectMoves);
void createFile();

/*********************************************************************
  Hauptprogramm
**********************************************************************/
int main(int argc, char *argv[])
{
    system("chcp 65001");
    system("cls");

    createFile();

    int startTimeTotal,endTimeTotal;
    int i, incorrectMoves = 0;
    int temp;
    char name[100];

	if (argc!=1)
	{
		fprintf(stderr,"Usage: %s\n",argv[0]);
		return EXIT_FAILURE;
	}

    startTimeTotal = (int)time(NULL);

    for (i = 0; i < 10; i++)
    {
        play(&temp);
        incorrectMoves += temp;

        printf("Press any key for next round\n");
        getch();

        system("cls");
    }

    endTimeTotal=(int)time(NULL);

    int elapsedTime = endTimeTotal - startTimeTotal;

    getPlayerName(name);
    displayStats(elapsedTime, incorrectMoves);
    writeStatsToFile(name, elapsedTime, incorrectMoves);

	return EXIT_SUCCESS;
}

//displays and lets user input

void play(int *incorrectMoves)
{
    int spielfeld[DEPTH][LINES]={0};
	int startpos,endpos;
	int starttime,endtime;

    int incorrect = 0;

    erzeugeZufallsfeld(spielfeld);
    startpos=rand()%(LINES-1)+1;  //Wo beginnt die Spielfigur? (Zahl von 1 bis Anz. der Linien)
    ausgabeFeld(spielfeld,startpos);

    printf("\nIhr Tipp: ");
    starttime=(int)time(NULL);	//Zeit laeuft ...
    do
    {
        while (!_kbhit())    //Solange noch keine Taste gedrueckt wurde, wird die verstrichene Zeit angezeigt
        {
            int z;
            Sleep(500);
            endtime=(int)time(NULL);
            printf("         (verbrauchte Zeit:%4d Sekunden)",(endtime-starttime));
            for (z=0;z<41;z++)  //Cursor 41 Zeichen zuruecksetzen
            printf("\b");
        }
        endpos=getch()-'0';
    } while ((endpos>LINES)||(endpos<1));  //Korrekte Eingabe?

    printf("%d\n\n",endpos);  //Tipp ausgeben

    if (check(spielfeld,startpos,endpos))  //ueberpruefe Tipp
    {
        printf("KORREKT\n");
    }
    else
    {
        printf("LEIDER NICHT KORREKT\n");
        incorrect++;
    }

    *incorrectMoves = incorrect;
}

//gets player name
void getPlayerName(char name[])
{
    printf("What's your name?\n");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
}

//displays player stats: elapsed Time and total of incorrect moves
void displayStats(int elapsedTime, int incorrectMoves)
{
    printf("Your stats:\nTime: %ds\nFailures: %d\n", elapsedTime, incorrectMoves);
}

//writes name, elapsed time, incorrect moves to highscore.txt
void writeStatsToFile(char name[], int elapsedTime, int incorrectMoves)
{
    FILE *fp;

    fp = fopen("highscore.txt", "at");

    fprintf(fp, "%s;%ds;%d\n", name, elapsedTime, incorrectMoves);

    fclose(fp);
}

//creates highscore.txt
void createFile()
{
    FILE *fp;

    if (access("highscore.txt", F_OK) == 0)
    {
        return;
    }
    else if (access("highscore.txt", F_OK) == -1)
    {
        fp = fopen("highscore.txt", "w");
        fclose(fp);
    }
}

/*********************************************************************
  Zweck: erzeugeZufallsfeld() initialisert das Spielfeld mit zufaelligen
         Verbindungen zwischen den Linien
  Parameter:    feld ..... Spielfeld mit den Werten
                           0...keine Verbindung
                           1...Verbindung nach links
                           2...Verbindung nach rechts
  Rueckgabewert:keiner
**********************************************************************/
void erzeugeZufallsfeld(int feld[DEPTH][LINES])
{
	int z,s;
	int sp;

	//Feld zuruecksetzen
	for (z=0;z<DEPTH;z++)
		for (s=0;s<LINES;s++)
			feld[z][s]=0;   //0..keine Verbindung

	srand((int)time(NULL));

	for (z=1;z<DEPTH-1;z++)  //1. und letzte Zeile bleiben leer
	{
		sp=rand()%(LINES-1);
		if (sp<(LINES-1))
		{
			feld[z][sp]=2;   //2..Verbindung nach rechts
			feld[z][sp+1]=1; //1..Verbindung nach links
		}
	}
}

/*********************************************************************
  Zweck: ausgabeFeld() liefert die Ausgabe des Spielfeldes
  Parameter:    feld ..... Spielfeld mit den Werten 0,1,2
                spider ... Startposition
  Rueckgabewert:keiner
**********************************************************************/
void ausgabeFeld(int feld[DEPTH][LINES],int spider)
{
	int z,s;
	int n;

	int zeilegametext=0;

	char gametext[11][80]={
           "-----------------------------------------------------------------------+"      ,
           "                                                             \\  \\  \\ .\"|"  ,
           "          S P I D E R - G A M E                               \\  \\ .\"-.|"   ,
           "                                                               \\ .\"-._ |"    ,
           "                                                                \"-._  \"|"    ,
           "                                                                    \"\"-|"    ,
           "                                                                       |"      ,
           "                                                                       |"      ,
           "                                                                     ^.-.^"    ,
           "                                                                    '^\\+/^'"  ,
           "                                                                    '/'\"'\\'" };


	//Ausgabe des Feldes mit Linien
	for (z=-6;z<DEPTH;z++) //gametext beginnt 6 Zeilen vor dem Spielfeld
	{
		if (zeilegametext<11)
		{
			printf("%s",gametext[zeilegametext]);
			for(n=0;n<(int)strlen(gametext[zeilegametext]);n++)
				printf("\b");
			zeilegametext++;
		}

		if (z==-2)
		{
			//Am Anfang wird die Startposition ausgegeben
			for (n=0;n<DISTANCE;n++)  //Einruecken am Beginn der Zeile
				printf(" ");
			for (s=0;s<LINES;s++)
			{
				if (s==spider-1)
					printf("╳");
				else
					printf(" ");
				for (n=1;n<=DISTANCE;n++)
					printf(" ");
			}
		}

		if (z>=0)
		{
			for (n=0;n<DISTANCE;n++)  //Einruecken am Beginn der Zeile
				printf(" ");

			for (s=0;s<LINES;s++)
			{
				switch (feld[z][s])
				{
					case 1:  printf("┫"); break;
					case 2:  printf("┣"); break;
					default: printf("┃"); break;
				}

				for (n=0;n<DISTANCE;n++)
				{
					if (feld[z][s]==2) //Verbindung nach rechts
						printf("━");
					else
						printf(" ");
				}
			}
		}
		printf("\n");
	}
	printf("\n");

	//Am Ende werden Nummern ausgegeben

	for (n=0;n<DISTANCE;n++)  //Einruecken am Beginn der Zeile
		printf(" ");
	for (s=0;s<LINES;s++)
	{
		printf("%-2d",s+1);
		for (n=1;n<DISTANCE;n++)
			printf(" ");
	}
	printf("\n\n");
}




/*********************************************************************
  Zweck: check() ueberprueft, ob der richtige Ausgang getippt wurde
  Parameter:    feld ..... Spielfeld mit den Werten 0,1,2
                spider ... Startposition
                tipp ..... Endposition
  Rueckgabewert:0 ........ falscher Tipp
                1 ........ korrekter Tipp
**********************************************************************/
int check(int feld[DEPTH][LINES],int spider,int tipp)
{
	int z,s;

	s=spider;

	for (z=0;z<DEPTH;z++)
	{
		if(feld[z][s-1]==1)       //Verbindung nach links --> Spalte nach links wechseln
			s--;
		else if(feld[z][s-1]==2)  //Verbindung nach rechts --> Spalte nach rechts wechseln
			s++;
	}

	if (s==tipp)
		return 1;  //TIPP OK
	else
		return 0;  //FALSCHER TIPP
}
