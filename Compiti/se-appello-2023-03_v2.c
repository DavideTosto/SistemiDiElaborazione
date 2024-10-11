#include <stdio.h>
#include <stdlib.h>

#define NOME 256
#define N 5

double getNum();

int main()
{
    FILE *ptrFile;
    char nomeFile[NOME];

    int primoVal, secondoVal, e = 0;

    int array[N];
    int countN = 0;

    FILE *ptrRisultati;
    double tastUno, tastDue;

    e = 0;
    do
    {
        printf("Inserisci il nome del file da aprire: ");
        scanf("%s", nomeFile);

        ptrFile = fopen(nomeFile, "r");

        if (ptrFile == NULL)
        {
            printf("Errore: impossibile aprire il file\n");
            e++;
            if (e > 5)
                return -1;
        }

    } while (ptrFile == NULL);

    while (fscanf(ptrFile, "%d %d", &primoVal, &secondoVal) != EOF)
    {
        if ((primoVal > secondoVal) && (primoVal % 2 == 0) && (secondoVal % 2 == 0))
            array[countN] = primoVal;
        else
            array[countN] = secondoVal;

        countN++;

        if (countN >= N)
            break;
    }

    fclose(ptrFile);
    ptrRisultati = fopen("se-appello-2023-03_v2.txt", "w");

    tastUno = getNum();
    tastDue = getNum();

    for (int i = 0, ii = 1; i < countN; i++)
    {
        if ((tastUno <= array[i] && array[i] <= tastDue) ||
            (tastDue <= array[i] && array[i] <= tastUno))
        {
            printf("%d^ valore: %d;\n", ii, array[i]);
            ii++;
            array[i] = 0;
        }
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
            while (getchar() != '\n')
                ; // Consuma i caratteri rimanenti nel buffer di input
        }
    } while (check != 1 || ch != '\n'); // Ripete finché l'input non è un numero valido

    printf("\n");

    return valore; // Restituisce il numero valido inserito dall'utente
}
