#include <stdlib.h>
#include <stdio.h>

#define lenghtNome 256
#define N 5

int min(int a, int b);

void main()
{
    FILE *prtFile;
    char nomeFile[lenghtNome];

    FILE *ptrRisultati;

    int a, b, valMin;
    int array[N];
    int countN = 0;

    int inTast;

    do
    {
        printf("Inserisci il nome del file: ");
        scanf("%s", nomeFile);
        // apertura file in modalità lettura
        prtFile = fopen(nomeFile, "r");
        if (prtFile == NULL)
        {
            printf("\nErrore: impossibile aprire il file\n");
        }
    } while (prtFile == NULL);

    while (fscanf(prtFile, " %d %d ", &a, &b) != EOF)
    {

        valMin = min(a, b);
        if ((valMin % 2) == 0)
        {
            array[countN] = valMin;
            countN++;
        }
        else
        {
            if (valMin == a)
            {
                array[countN] = b * 2;
                countN++;
            }
            else
            {
                array[countN] = a * 2;
                countN++;
            }
        }
        if (countN >= N)
        {
            countN--;
            break;
        }
    }

    fclose(prtFile);
    ptrRisultati = fopen("se-appello-2023-10-Risultati.txt", "w");

    printf("\nInserisci un valore: ");
    scanf("%d", &inTast);

    for (int i = 0; i <= countN; i++)
    {
        // array[0]<=x<=inTast || il contrario
        if ((array[0] <= array[i] && array[i] <= inTast) ||
            (inTast <= array[i] && array[i] <= array[0]))
        {
            printf(" %d,", array[i]);
        }
        else
        {
            array[i] = 0;
        }

        fprintf(ptrRisultati, " %d\n", array[i]);
    }

}

int min(int a, int b)
{
    if (a <= b)
    {
        return a;
    }
    else if (b < a)
    {
        return b;
    }
}