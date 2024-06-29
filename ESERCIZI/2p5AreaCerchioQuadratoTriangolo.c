/* Si scriva un programma in linguaggio C che, dato un numero reale D immesso da tastiera,
 calcoli e stampi:
 1. l’area del quadrato di lato D
 2. l’area del cerchio di diametro D
 3. l’area del triangolo equilatero di lato D */

#include <stdio.h>
#include <math.h>
#define PI 3.14159

 void main(){

    float lunghezza;
    double aeraquadrato, areacerchio, areatriangolo;
    char risposta;

    do
    {
    printf("Si scriva un programma in linguaggio C che, dato un numero reale D immesso da tastiera,\n calcoli e stampi: \n1. l’area del quadrato di lato D\n2. l’area del cerchio di diametro D\n3. l’area del triangolo equilatero di lato D: ");
    printf("Inserire lunghezza: ");
    scanf("%f", &lunghezza );
    printf(" metri\n");
    aeraquadrato = (double)lunghezza*lunghezza;
    areacerchio = (double) PI*(lunghezza/2)*(lunghezza/2);
    areatriangolo = (double)(sqrt(3) / 4) * lunghezza * lunghezza;

    printf("L'aera del quadrato è: %f\n",aeraquadrato);
    printf("L'aera del cerchio è: %f\n",areacerchio);
    printf("L'aera del triangolo è: %f\n",areatriangolo);
    
    do {
        printf("Vuoi continuare? (y/n): ");
        scanf("%c", &risposta);
    } while(risposta!='n' && risposta!='N' && risposta!='y' && risposta!='Y' );
    

    } while (risposta=='Y' || risposta=='y');

}