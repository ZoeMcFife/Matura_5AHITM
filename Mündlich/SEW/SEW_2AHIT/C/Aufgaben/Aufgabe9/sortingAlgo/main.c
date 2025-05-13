#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/**********************************************************************************************************
*  Sortieralgorithmus: Bubblesort
*  Parameter: a .... zu sortierendes int-Feld
*             gr ... Groesse des Feldes (Anzahl der Elemente)
**********************************************************************************************************/
void bubbleSort(int a[], int gr)
{
	int sortiert,i,tmp;
	do {
		sortiert = 1;
		for (i=1; i<gr; i++)
		{
			if (a[i-1]>a[i])
			{
				tmp=a[i-1];
				a[i-1]=a[i];
				a[i]=tmp;
				sortiert=0;
			}
		}
	} while (!sortiert);
}

/**********************************************************************************************************
*  Sortieralgorithmus: selectionSort
*  Parameter: a .... zu sortierendes int-Feld
*             gr ... Groesse des Feldes (Anzahl der Elemente)
**********************************************************************************************************/
void selectionSort (int a[], int gr)
{
    int index, minIdx;
    int tmp;
    for (index=0; index<gr-1; index++)
    {
        minIdx = minimum(a,index,gr-1);

        //vertausche a[index] mit a[minIdx]
        tmp=a[index];
        a[index]=a[minIdx];

        a[minIdx]=tmp;
    }
}

/**********************************************************************************************************
*  Sortieralgorithmus: insertionSort
*  Parameter: a .... zu sortierendes int-Feld
*             gr ... Groesse des Feldes (Anzahl der Elemente)
**********************************************************************************************************/
void insertionSort (int a[], int gr)
{
    int j,i;
    int value;

    for (j=1;j<gr;j++)
    {
        value = a[j];

        for (i=j-1; a[i]>value && i>=0; i--)
        {
            a[i+1] = a[i];
        }

        a[i+1] = value;
    }
}

/**********************************************************************************************************
*  Sortieralgorithmus: quickSort
*  Parameter: a .... zu sortierendes int-Feld
*             l .... linkes Index
*             r .... rechtes Index
**********************************************************************************************************/
void quickSort (int a[], int l, int r)
{
    int i;

    if (l<r)
    {
        i = aufteilung (a, l, r);
        quickSort (a, l, i-1);
        quickSort (a, i+1, r);
    }
}

int aufteilung (int a[], int l, int r)
{
    int tmp,k;
    int pivot = a[r]; //gewähltes Pivotelements
    int i = l - 1;

    for (k = l; k <= r-1; k++)
    {
        if (a[k] <= pivot)
        {

            i++;
                //tausche a[i] mit a[k]
            tmp=a[i];

            a[i]=a[k];

            a[k]=tmp;

        }
    }

   // i++;

    //tausche a[i] mit a[k]
    tmp=a[i + 1];
    a[i + 1]=a[k];

    a[k]=tmp;
    return i+1;
}

/**********************************************************************************************************
*  Sortieralgorithmus: mergeSort
*  Parameter: a .... zu sortierendes int-Feld
*             l .... linkes Index
*             r .... rechtes Index
**********************************************************************************************************/

void mergeSort ( int a[], int l, int r )
{
    int m;

    if (l < r)
    {
        m = (l+r) / 2;

        mergeSort(a,l,m);

        mergeSort(a,m+1,r);

        merge(a,l,m,r);
     }
}

// einfache Variante
void merge(int a[], int l, int m, int r)
{

    int i, j, k;
    int gr=r+1;
    int *b; //Hilfsarray b
    if ((b=(int *)malloc(sizeof(int)*gr))==NULL) return;

 // beide Hälften von a in Hilfsarray b kopieren
    for (i=l; i<=r; i++)
        b[i]=a[i];


    i=l; j=m+1; k=l;

    // jeweils das nächstgrößte Element zurückkopieren
    while (i<=m && j<=r)
        if (b[i]<=b[j])
            a[k++]=b[i++];

        else
            a[k++]=b[j++];
    // Rest der vorderen Hälfte falls vorhanden zurückkopieren
    while (i<=m)
        a[k++]=b[i++];


    free(b);

}

/**********************************************************************************************************
*  minimum Wert eines Feldes zurückliefern
*  Parameter: a ........ zu initialisierendes  int-Feld
*             anfang ... index bei dem man anfangen zu suchen soll
*             ende ..... index bei dem man enden soll
**********************************************************************************************************/

int minimum (int a[],int anfang,int ende)
{
    int index;
    int minIdx = anfang;

    for (index=anfang+1; index<=ende; index++)
    {
        if (a[index] < a[minIdx])
            minIdx = index;
    }
    return minIdx;
}

/**********************************************************************************************************
*  Feld mit Zufallswerten initialisieren
*  Parameter: a .... zu initialisierendes  int-Feld
*             gr ... Groesse des Feldes (Anzahl der Elemente)
**********************************************************************************************************/
void initRandom(int a[], int gr)
{
    int i;
    for(i=0;i<gr;i++)
    {
        a[i]=rand();
    }
}

/**********************************************************************************************************
*  Feld mit aufsteigenden Zahlen (von 1 bis gr) initialisieren
*  Parameter: a .... zu initialisierendes  int-Feld
*             gr ... Groesse des Feldes (Anzahl der Elemente)
**********************************************************************************************************/
void initAsc(int a[], int gr)
{
    int i;
    for(i=0;i<gr;i++)
    {
        a[i]=i+1;
    }
}


/**********************************************************************************************************
*  Feld mit absteigenden Zahlen (von gr bis 1) initialisieren
*  Parameter: a .... zu initialisierendes  int-Feld
*             gr ... Groesse des Feldes (Anzahl der Elemente)
**********************************************************************************************************/
void initDesc(int a[], int gr)
{
    int i;
    for(i=0;i<gr;i++)
    {
        a[i]=gr-i;
    }
}


/**********************************************************************************************************
*  Feld mit absteigenden Zahlen (von gr bis 1) initialisieren
*  Parameter: a .... zu initialisierendes  int-Feld
*             gr ... Groesse des Feldes (Anzahl der Elemente)
**********************************************************************************************************/
int* copyArray(int arr[], int arrLen)
{
    int *arrCopy = (int *)malloc(sizeof(int) * arrLen);

    int i;

    for (i = 0; i < arrLen; i++)
    {
        arrCopy[i] = arr[i];
    }

    return arrCopy;
}

/**********************************************************************************************************
*  Main:
*  Feld mit verschiedenen Groessen anlegen, initialisieren, sortieren und die jeweils die Laufzeit messen
**********************************************************************************************************/
int main(void)
{
	clock_t start;
	clock_t ende;

	int *feld;
	int i;
	int anzahl;
	float sortTime;

	srand(time(NULL));


    printf("+--------+-------------+-------------+-------------+-------------+-------------+\n");
	printf("|        | BubbleSort  |SelectionSort|InsertionSort|  QuickSort  |  MergeSort  |\n");
	printf("+--------+-------------+-------------+-------------+-------------+-------------+\n");
	printf("| Anzahl |    Dauer    |    Dauer    |    Dauer    |    Dauer    |    Dauer    |\n");
	printf("+--------+-------------+-------------+-------------+-------------+-------------+\n");
	for (anzahl=5;anzahl<100000;anzahl*=2)
	{
		//**************Feld anlegen***************
		if ((feld=(int *)malloc(sizeof(int)*anzahl))==NULL)
			break;

		printf("| %6d |",anzahl);

		//**************Werte initialisieren*******
		initRandom(feld,anzahl);
		//initAsc(feld,anzahl);
//		initDesc(feld,anzahl);

        //**************Array kopieren*************
        int *feldSelectionSort = copyArray(feld, anzahl);
        int *feldInsertionSort = copyArray(feld, anzahl);
        int *feldQuickSort = copyArray(feld, anzahl);
        int *feldMergeSort = copyArray(feld, anzahl);

		//**************Sortieren START************
        start=clock();
        bubbleSort(feld,anzahl);
        ende=clock();

        sortTime = (float)(ende-start) / CLOCKS_PER_SEC;
        printf(" %6.2f Sek  |", sortTime);


		start=clock();
        selectionSort(feldSelectionSort, anzahl);
		ende=clock();

        sortTime = (float)(ende-start) / CLOCKS_PER_SEC;
        printf(" %6.2f Sek  |", sortTime);


		start=clock();
        insertionSort(feldInsertionSort, anzahl);
		ende=clock();

        sortTime = (float)(ende-start) / CLOCKS_PER_SEC;
        printf(" %6.2f Sek  |", sortTime);


        start=clock();
        quickSort(feldQuickSort, 0, anzahl - 1);
		ende=clock();

        sortTime = (float)(ende-start) / CLOCKS_PER_SEC;
        printf(" %6.2f Sek  |", sortTime);


        start=clock();
        mergeSort(feldMergeSort, 0, anzahl - 1);
		ende=clock();

        sortTime = (float)(ende-start) / CLOCKS_PER_SEC;
        printf(" %6.2f Sek  |", sortTime);


		//**************Sortieren ENDE*************

        printf("\n");

		free(feld);
		free(feldSelectionSort);
		free(feldInsertionSort);
		free(feldQuickSort);
		free(feldMergeSort);
	}
	printf("+--------+-------------+-------------+-------------+-------------+-------------+\n");
	return 0;
}
