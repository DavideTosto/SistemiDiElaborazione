#include <stdio.h>

void main(){

    int N;
    double SerieArmonica = 1;

    printf("La ridotta n-esima della serie armonica\nInserisci N:");
    scanf("%d", &N );


    for (N; N > 0; N--)
    {
        SerieArmonica = SerieArmonica + (double)1/(N);
    }
    printf("Il risultato è: %4.4f", SerieArmonica);
}