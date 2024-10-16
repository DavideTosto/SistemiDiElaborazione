#include <stdio.h>
#include <stdlib.h>

#define NOME 256
#define N 6
#define TENTATIVI 10

int max(int a, int b);
double getNum();
void ordina(double *Vett);

int main()
{
    FILE *ptrFile;
    char nomeFile[NOME];

    int primoVal, secondoVal;

    int array[N];
    int countN = 0;

    FILE *ptrRisultati;
    double valorInseriti[2];

    int err = 0;
    do
    {
        printf("Inserisci il nome del file: ");
        scanf("%s", nomeFile);

        ptrFile = fopen(nomeFile, "r");
        if (ptrFile == NULL)
        {
            printf("Errore: impossibile aprire il file\n");
            if (err > TENTATIVI)
                return -1;

            err++;
        }
    } while (ptrFile == NULL);

    while (fscanf(ptrFile, " %d %d", &primoVal, &secondoVal) != EOF)
    {
        int maggiore = max(primoVal, secondoVal);

        if ((maggiore % 2) != 0)
            array[countN] = maggiore;
        else
        {
            if (maggiore == primoVal)
                array[countN] = secondoVal / 2;
            else
                array[countN] = primoVal / 2;
        }
        countN++;

        if (countN >= N)
            break;
    }

    fclose(ptrFile);
    ptrRisultati = fopen("se-appello-2024-002-Risultati.txt", "w");

    valorInseriti[0] = getNum();
    valorInseriti[1] = array[countN - 1];
    ordina(valorInseriti);

    printf("\nStampa dei valori compresi (estremi inclusi)\n");
    for (int i = 0, ii = 1; i < countN; i++)
    {
        if ((valorInseriti[0] <= array[i] && array[i] <= valorInseriti[1]))
        {
            printf("%d^ valore: %d;\n", ii, array[i]);
            ii++;
        }
        else
            array[i] = -1;

        fprintf(ptrRisultati, "Array[%d] = %d;\n", i, array[i]);
    }

    fclose(ptrRisultati);
    return 0;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

void ordina(double *Vett)
{
    if (Vett[0] > Vett[1])
    {
        double temp = Vett[0];
        Vett[0] = Vett[1];
        Vett[1] = temp;
    }
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

    printf("\n"); // Stampa una nuova riga

    return valore; // Restituisce il numero valido inserito dall'utente
}