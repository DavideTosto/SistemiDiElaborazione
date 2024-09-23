#include <stdlib.h>
#include <stdio.h>
#define N 5

int max(int a, int b, int c);

void main()
{

    // dichiarazioni per la lettura e scrittura del file
    FILE *ptrFile;
    FILE *ptrRisultati;
    char nomeFile[100];

    /****** dichiarazioni variabili operazioni file ******/
    int array[N];
    int boolFlagarray = 1;
    // ho preferito dichiarare un int invece che dichiarare una boolean perchè
    // per evitare l'aggiunta di una nuova libreria è quindi evitare problemi di
    // compatibilità e per preservare lo spazio in memoria.
    int countN = 0;
    // tiene traccia del numero degli elementi nell' array
    int a, b, c;
    // variabili utili per le operazioni successive
    int inValTast;

    // apertura file
    do
    {
        printf("Scrivi il nome del file che vuoi caricare: ");
        scanf("%s", nomeFile);
        // Apertura file
        ptrFile = fopen(nomeFile, "r");
        if (ptrFile == NULL)
        {
            printf("Errore: il file non puo essere aperto\n");
        }
    } while (ptrFile == NULL);
    printf(" File aperto in modalità lettura\n");

    while (fscanf(ptrFile, "%d %d %d", &a, &b, &c) != EOF && boolFlagarray)
    {

        int localSomma;

        localSomma = a + b + c;

        if (localSomma % 2 == 0) // il numero è pari
        {
            array[countN] = max(a, b, c);
        }
        else // il numero è dispari
        {
            array[countN] = localSomma;
        }

        countN++;
        if (countN >= N)
        {
            boolFlagarray = 0;
            countN--;
        }
    }

    printf("Inserisci un numero: ");
    scanf("%d", &inValTast);
    printf("\n");

    for (int i = 0; i <= countN; i++)
    {
        // se il valore è compreso tra quello inserito e l' ultimo elemento invalast < x < array || il contrario
        if ((array[i] >= inValTast && array[i] <= array[countN]) ||
            (array[i] >= array[countN] && array[i] <= inValTast))
        {
            array[i] = array[i] + 3;
            printf("%d\n", array[i]);
        }
    }
    printf("\n\n");
    fclose(ptrFile);

    /* risultati */
    do
    {
        ptrRisultati = fopen("risultati.txt", "w");
        if (ptrRisultati == NULL)
        {
            printf("\n Non è stato possibile generare un nuovo file. \n");
        }
    } while (ptrRisultati == NULL);
    for (int i = 0; i <= countN; i++)
    {
        if (array[i] > 5)
        {
            fprintf(ptrRisultati, "\n%d", array[i]);
            printf("%d\n", array[i]);
        }
    }
    fclose(ptrRisultati);
}

int max(int a, int b, int c)
{
    if (a >= b && a >= c)
    {
        return a;
    }
    else if (b >= a && b >= c)
    {
        return b;
    }
    else
    {
        return c;
    }
}