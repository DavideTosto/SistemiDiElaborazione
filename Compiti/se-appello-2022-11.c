#include <stdlib.h>
#include <stdio.h>

#define lnghtNome 256
#define N 5

void main (){
    FILE *ptrFile;
    char nomeFile[lnghtNome];

    int primoValore, secondoValore, differenza;

    int array[N];
    int countN = 0; 

    FILE *ptrRisultati; 
    int valoreTastiera, primoValoreArray;   

    do
    {
        printf("Inserisci il nome del file da caricare: ");
        scanf("%s", nomeFile);

        ptrFile = fopen(nomeFile, "r");
        if (ptrFile == NULL)
        {
            printf("Errore: il file non può essere aperto");
        }
    } while (ptrFile == NULL);

    while ( fscanf(ptrFile, "%d %d", &primoValore, &secondoValore) != EOF)
    {
        differenza = primoValore - secondoValore;
        array[countN] = differenza;
        countN++;

        if (countN >= N)
        {
            countN--;
            break;
        }
    }

    fclose(ptrFile);
    ptrRisultati = fopen("se-appello-2022-11-risultato.txt", "w");

    printf("Inserisci un numero: ");
    scanf("%d", &valoreTastiera);
    primoValoreArray = array[0];

    for (int i = 0; i <= countN; i++)
    {
        // array[0] <= x <= valoreTastiera
        if ( (primoValoreArray <= array[i] && array[i]<=valoreTastiera) ||
             (valoreTastiera <= array[i] && array[i]<=primoValoreArray ))
        {
            printf(" %d,", array[i]);
        }

        if ( array[i] < 0)
        {
            array[i] = 0; 
        }
    
         fprintf(ptrRisultati," %d\n", array[i]);
    }
    

}