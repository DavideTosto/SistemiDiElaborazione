#include <stdio.h>
#include <stdlib.h>

#define lngthNome 256
#define N 3

int max(int a, int b);

void main()
{
    FILE *ptrFile;
    char nomeFile[lngthNome];

    FILE *ptrRisultati;

    int valoreUno, valoreDue;

    int array[N];
    int countN = 0;    // conteggio dei valori presenti nell'array
    int countRiga = 0; // conteggio delle righe

    int primoValIn, secVanIn;

    do
    {
        printf("Inserisci il nome del file da aprire: ");
        scanf("%s", nomeFile);

        ptrFile = fopen(nomeFile, "r");
        if (ptrFile == NULL)
        {
            printf("\nErrore: impossibile aprire il file\n");
        }
    } while (ptrFile == NULL);

    while (fscanf(ptrFile, " %d %d ", &valoreUno, &valoreDue) != EOF)
    {

        if ((valoreUno * valoreDue) < 10)
        {
            array[countN] = max(valoreUno, valoreDue);
            countN++;
        }
        else
        {
            array[countN] = countRiga;
            countN++;
        }
        if (countN >= N)
        {
            countN--;
            break;
        }
        countRiga++;
    }

    fclose(ptrFile);
    ptrRisultati = fopen("se-appello-2023-04-Risultati.txt", "w");

    printf("Inserisci il primo valore da tastiera: ");
    scanf("%d", &primoValIn);

    printf("Inserisci il secondo valore da tastiera: ");
    scanf("%d", &secVanIn);

    printf("\nI valori dell' array compresi sono:\n");
    // stampare a video i valori dell' array (x) compresi tra i valori inseriti da tastiera:
    // valUno  <= x <= valDue
    for (int i = 0; i <= countN; i++)
    {
        
        if ((primoValIn <= array[i] && array[i] <= secVanIn) ||
            (secVanIn <= array[i] && array[i] <= primoValIn))
        {
            printf("%d, ", array[i]);
            array[i] = 1;
        }

        fprintf(ptrRisultati, "%d\n", array[i]);
    }
}

int max(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}