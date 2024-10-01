#include <stdio.h>
#include <stdlib.h>

#define lngthNome 256
#define N 5

int max ( int a, int b);

void main ()
{
    FILE *ptrFile;
    char nomeFile[lngthNome];

    int array[N];
    int countN = 0;
    int primoValore, secValore;

    FILE *ptrRisultati;
    int a, b;

    do
    {
        printf("Inserisci il nome del file da carricare: ");
        scanf("%s", nomeFile);

        ptrFile = fopen(nomeFile, "r");
        if ( ptrFile == NULL )
        {
            printf("\nImpossibile aprire il file\n");
        }
    } while ( ptrFile == NULL );

    while ( fscanf(ptrFile, " %d %d ", &primoValore, &secValore) != EOF )
    {
        if ( (primoValore > secValore) && (primoValore%2 == 0) && (secValore%2 == 0) )
        {
            array[countN] = primoValore;
            countN++;
        }
        else
        {
            array[countN] = secValore;
            countN++;
        }

        if ( countN >= N)
        {
            countN--;
            break;
        }
    }

    fclose(ptrFile);
    ptrRisultati = fopen("se-appello-2023-03-risultati.txt", "w");

    printf("Inserisci il primo numero: ");
    scanf("%d", &a);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &b);

    for (int i = 0; i <= countN; i++)
    {
        // a < array[i] < b || il contrario
        if ( a<= array[i] && array[i]<b || b<= array[i] && array[i]<a )
        {
            printf(" %d,",array[i]);
            array[i]=0;
        }
        fprintf(ptrFile, "%d\n", array[i]);
    }
    
    fclose(ptrRisultati);
    
}


int max ( int a, int b)
{
    if ( a > b)
    {
        return a;
    }
    else
    {
        return 0;
    }
}