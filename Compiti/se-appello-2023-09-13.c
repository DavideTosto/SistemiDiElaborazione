#include <stdio.h>
#include <stdlib.h>

#define N 5
#define lngthNF 100

void main()
{
    // Dichiarazione variabili apertura file da leggere
    FILE *ptrFile;
    char nomeFile[lngthNF];

    // Dichiarazione variabili file da scrivere
    FILE *ptrRisultati;

    // Dich. variabili per operazioni
    int array[N];
    int countN = 0;
    // countN tiene conto del numero degli elementi di array
    int a, b;
    int valIn;

    do
    {
        // richiesta nome file da aprire
        printf("Inserisci il nome del file: ");
        scanf("%s", &nomeFile);
        // apertura file
        ptrFile = fopen(nomeFile, "r");
        if (ptrFile == NULL)
        {
            printf("Errore: non è stato possibile aprire il file");
        }
    } while (ptrFile == NULL);

    // caricamento dei valori presenti nel file all' array
    // se il primo numero rilevato è dispari e divisibili per tre
    // allora salva la var b nell' array.
    while (fscanf(ptrFile, "%d %d", &a, &b) != EOF)
    {
        if ((a % 2 != 0) || (a % 3 == 0))
        {
            array[countN] = b;
            countN++;
            if (countN >= 5)
            {
                countN--;
                break;
            }
        }
    }
    
    // chisura file in lettura e apertura/creazione file risultati
    fclose(ptrFile);
    ptrRisultati = fopen("se-appello-2023-09-13-Risultato.txt", "w");

    // richiesta di un numero da tastiera
    printf("Inserisci un numero: ");
    scanf("%d", &valIn);

    // stampa dei valori dell array compresi tra il numero inserito da tastiera e il valore del primo elemanto dell' array
    //  valIn < x < array[0] || array[0] < x < valIn
    // se x[i] non fa parte dell' intervallo sostituisce il suo valore con 0
    for (int i = 0; i <= countN; i++)
    {
        if ((valIn <= array[i] && array[i] <= array[0]) ||
            (array[0] <= array[i] && array[i] <= valIn))
        {
            printf(" %d ,", array[i]);
        }
        else
        {
            // sostituz. elementi non compresi nell' intervallo
            array[i] = 0;
        }
        //salvataggio risultati
        fprintf(ptrRisultati," %d\n", array[i]);
    }

    // chiusura file risultati
    fclose(ptrRisultati);
}