#include <stdlib.h>
#include <stdio.h>

#define lnghtNome 256
#define N 5

int max(int a, int b, int c);
double getNum();

int main()
{
    FILE *ptrFile;
    char nomeFile[lnghtNome];
    int primoVal, secondoVal, terzoVal;

    int array[N];
    int countN = 0;

    FILE *ptrRisultati;
    int ultimoElemento;
    double valoreTastiera;

    do
    {
        printf("Inserisci il nome del File: ");
        scanf("%s", nomeFile);
        ptrFile = fopen(nomeFile, "r");
        if (ptrFile == NULL)
        {
            printf("Errore: impossibile aprire il file!");
        }
        
    } while (ptrFile == NULL);

    while (fscanf(ptrFile, "%d %d %d", &primoVal, &secondoVal, &terzoVal) != EOF)
    {
        int somma = primoVal + secondoVal + terzoVal;
        if (somma % 2 == 0)
        {
            array[countN] = max(primoVal, secondoVal, terzoVal);
            countN++;
        }
        else
        {
            array[countN] = somma;
            countN++;
        }

        if (countN >= N)
            break;
    }

    fclose(ptrFile);
    ptrRisultati = fopen("se-appello-2024-06_v2.txt", "w");

    ultimoElemento = array[countN - 1];
    printf("Inserisci un numero: ");
    valoreTastiera = getNum();

    for (int i = 0, ii = 1; i < countN; i++)
    {
        if ((ultimoElemento <= array[i] && array[i] <= valoreTastiera) ||
            (valoreTastiera <= array[i] && array[i] <= ultimoElemento))
        {
            printf("%d^ valore: %d\n", ii, array[i]);
            ii++;
            array[i] = +array[i] + 3;
        }

        if (array[i] > 5)
        {
            fprintf(ptrRisultati, "Array[%d] = %d\n", i, array[i]);
        }
    }

    fclose(ptrRisultati);
}

int max(int a, int b, int c)
{
    if (a >= b && a >= c)
        return a;
    if (b >= a && b >= c)
        return b;
    else
        return c;
}

// Funzione che legge un numero dall'utente, assicurandosi che sia valido
double getNum()
{
    double valore; // Variabile per memorizzare il numero inserito dall'utente
    int check;     // Variabile di controllo per verificare la validità dell'input
    char ch;       // Variabile per memorizzare i caratteri extra nel buffer di input

    // Chiede all'utente di inserire un numero
    printf("Inserisci un numero: ");

    // Ciclo per garantire che l'input sia un numero valido
    do
    {
        check = scanf("%lf", &valore); // Legge il numero e salva lo stato in 'check'
        ch = getchar();                // Legge il carattere successivo nel buffer
        if (check != 1 || ch != '\n')  // Controlla se l'input non è un numero o se ci sono altri caratteri
        {
            printf("Errore: Inserisci un numero -> ");
            while (getchar() != '\n')
                ; // Consuma i caratteri rimanenti nel buffer di input
        }
    } while (check != 1 || ch != '\n'); // Ripete finché l'input non è un numero valido

    printf("\n");

    return valore; // Restituisce il numero valido inserito dall'utente
}
