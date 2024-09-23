#include <stdio.h>
#include <stdlib.h>

#define lnghtNome 256
#define N 7

void main()
{

    FILE *ptrFile;
    char nomefile[lnghtNome];

    FILE *ptrRisultati;

    // dichiarazione variabile per elaborazione
    int primo_valore, secondo_valore;
    int valIn;
    //
    int array[N];
    int countN = 0; // conta i valori inseriti nell' array

    do
    {
        printf("Inserisci il nome del file da caricare: ");
        scanf("%s", nomefile);

        // apertura file in modalità lettura
        ptrFile = fopen(nomefile, "r");
        if (ptrFile == NULL)
        {
            printf("\nERRORE: impossibile aprire il file\n");
        }
    } while (ptrFile == NULL);

    // scansione elementi nelle righe del documento
    while (fscanf(ptrFile, " %d %d ", &primo_valore, &secondo_valore))
    {
        printf("\n %d \n", primo_valore / secondo_valore );
        if (( primo_valore % secondo_valore) % 2 == 0)
        {
            array[countN] = secondo_valore;
            countN++;
        }
        else
        {
            array[countN] = 1;
            countN++;
        }
        if (countN >= N)
        {
            countN--;
            break;
        }
    }

    // chiusura file in lettura e apertura/creaz. file per scrittura risultati
    fclose(ptrFile);
    ptrRisultati = fopen("se-appello-2023-06-Risultati.txt", "w");
    printf("\nInserisci un valore: ");
    scanf("%d", &valIn);

    for (int i = 0; i <= countN; i++)
    {
        // se gli elementi dell array (x) sono copresi tra
        // valIn < x < array[countN] || il contrario
        if ((valIn <= array[i] && array[i] <= array[countN]) ||
            (array[countN] <= array[i] && array[i] <= valIn))
        {
            printf("%d, ", array[i] );
        }
        else
        {
            array[i] = 0;
        }
        fprintf(ptrRisultati, " %d\n", array[i]);
    }

    fclose(ptrRisultati);
}