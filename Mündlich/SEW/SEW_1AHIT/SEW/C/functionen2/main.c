#include <stdio.h>
#include <stdlib.h>

//Prototypen
double calcSerienWiderstand(double Widerstand1, double Widerstand2);
double calcParallelWiderstand(double Widerstand1, double Widerstand2);
void calcSerienParallelWiderstand(double Widerstand1, double Widerstand2, double *Rs, double *Rp);

int main()
{
    double R1=0.0, R2=0.0, Rsges=0.0, Rpges=0.0;



    printf("R1:  [OHM]\tR2: [OHM]\n");
    scanf("%lf%lf",&R1,&R2);



    /*/Rges=R1+R2;
    //Funktionsaufruf
    Rsges=calcSerienWiderstand(R1,R2);
    Rpges=calcParallelWiderstand(R1,R2);
    */

    calcSerienParallelWiderstand(R1, R2, &Rsges, &Rpges);
    printf("Gesamtserienwiderstand:  %.2lf\n",Rsges);
    printf("Gesamtparallelwiderstand:  %.2lf\n",Rpges);




    return EXIT_SUCCESS;
}
//Funktionsdefinitionen

void calcSerienParallelWiderstand(double Widerstand1, double Widerstand2, double *Rs, double *Rp)
{
    double RSerie = 0.0, RPara = 0.0;

    RSerie = Widerstand1 + Widerstand2;
    RPara = Widerstand1 * Widerstand2 / (Widerstand1 + Widerstand2);

    *Rs = RSerie;
    *Rp = RPara;
}
double calcSerienWiderstand(double Widerstand1, double Widerstand2){
    double Gesamtwiderstand=0.0;



    Gesamtwiderstand=Widerstand1+Widerstand2;



    return Gesamtwiderstand;
}

double calcParallelWiderstand(double Widerstand1, double Widerstand2){
    double Gesamtwiderstand=0.0;



    Gesamtwiderstand=Widerstand1*Widerstand2/calcSerienWiderstand(Widerstand1,Widerstand2);
    return Gesamtwiderstand;
}
