#include <stdio.h>
#include <stdlib.h>

#define lngthNome 256
#define N 7


void main()
{
    FILE *ptrFile;
    char nomeFile[lngthNome];

    int primoValore, secondoValore;
    int array[N];
    int countN = 0; 

    FILE *ptrRisultati;
    int numeroIN;

    do
    {
        printf("Inserisci il nome del file da caricare: ");
        scanf("%s",nomeFile);

        ptrFile = fopen(nomeFile, "r");
        if ( ptrFile == NULL)
        {
            printf("\nErrore: impossibile aprire il file\n");
        }
    } while (ptrFile == NULL);

    while (fscanf(ptrFile, " %d %d", &primoValore, &secondoValore) != EOF)
    {
        if ( (primoValore%secondoValore)%2 == 0 )
        {
            array[countN] = primoValore;
            countN++;
        }
        else
        {
            array[countN] = secondoValore;
            countN++;
        }
        if ( countN >= N )
        {
            countN--;
            break;
        }
    }

    fclose(ptrFile);
    ptrRisultati = fopen("se-appello-2023-01-Risultati.txt", "w");

    printf("Inserisci un numero: ");
    scanf("%d", &numeroIN);

    for (int i = 0; i <= countN; i++)
    {
        // se il valore è compreso tra: numeroIN <= x <= 5 
        if ( (numeroIN<=array[i] && array[i]<= 5) || (5<=array[i] && array[i]<= numeroIN)  )
        {
            printf(" %d", array[i]);
            array[i] = 0;
        }
        fprintf(ptrRisultati, " %d, ", array[i]);
    }
    
    fclose(ptrRisultati);
    
}