#include <stdlib.h>
#include <stdio.h>

#define Nome 256
#define tentativi 10
#define N 7

double getNum();

int main()
{
    FILE *ptrFile;
    char nomeFile[Nome];

    int primoNum, secondoNum;
    int array[N];
    int countN = 0;

    FILE *ptrRisultati;
    double valTastiera;
    int ultimovalore;

    int errore = 0;
    do
    {
        printf("Inserire il nome del file: ");
        scanf("%s", nomeFile);

        ptrFile = fopen(nomeFile, "r");

        if (ptrFile == NULL)
        {
            printf("Errore: Impssibile aprire il file!");
            errore++;
            if (errore > tentativi)
            {
                printf("Programma Terminato!");
                return -1;
            }
        }
    } while (ptrFile == NULL);

    while (fscanf(ptrFile, " %d %d", &primoNum, &secondoNum) != EOF)
    {
        int resto = primoNum % secondoNum;

        if (resto % 2 == 0)
            array[countN] = secondoNum;
        else
            array[countN] = 1;

        countN++;

        if (countN >= N)
            break;
    }

    fclose(ptrFile);
    ptrRisultati = fopen("se-appello-2023-06-v2-Risultati.txt", "w");

    valTastiera = getNum();
    ultimovalore = array[countN-1];

    for (int i = 0, ii = 1; i < countN; i++)
    {
        if ((valTastiera <= array[i] && array[i] <= ultimovalore) ||
            (ultimovalore <= array[i] && array[i] <= valTastiera))
        {
            printf("%d^ valore: %d;\n", ii, array[i]);
            ii++;
        }
        else
            array[i] = 0;

        fprintf(ptrRisultati, "Array[%d] = %d;\n", i, array[i]);
    }

    fclose(ptrRisultati);
    return 0;
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
            while (getchar() != '\n'); // Consuma i caratteri rimanenti nel buffer di input
        }
    } while (check != 1 || ch != '\n'); // Ripete finché l'input non è un numero valido

    printf("\n");

    return valore; // Restituisce il numero valido inserito dall'utente
}
