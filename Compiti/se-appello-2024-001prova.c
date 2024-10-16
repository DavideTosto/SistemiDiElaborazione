#include <stdio.h>
#include <stdlib.h>

#define NOME 256
#define N 6
#define TENTATIVI 10

double min(double a, double b);
double max(double a, double b);
double getNum();

int main()
{
    FILE *ptrFile;
    char nomeFile[NOME];

    int primoVal, secondoVal;

    int array[N];
    int countN = 0;

    FILE *ptrRisuletati;

    int ultimoElemento;
    double valoreTastiera;


    int err = 0;
    do
    {
        printf("Inserisci il nome del file: ");
        scanf("%s", nomeFile);

        ptrFile = fopen(nomeFile, "r");

        if (ptrFile == NULL)
        {
            printf("Errore: impossibile aprire il file.\n");
            err++;
            if (err > TENTATIVI)
                return -1;
        }

    } while (ptrFile == NULL);

    while (fscanf(ptrFile, "%d %d", &primoVal, &secondoVal) != EOF)
    {
        int prodotto = primoVal * secondoVal;

        if (prodotto % 2 != 0)
            array[countN] = min(primoVal, secondoVal);
        else
            array[countN] = abs(primoVal - secondoVal);

        countN++;

        if (countN >= N)
            break;
    }

    fclose(ptrFile);
    ptrRisuletati = fopen("se-appello-2024-001-prova-risultati.txt", "w");

    ultimoElemento = array[countN - 1];
    valoreTastiera = getNum();

    

    for (int i = 0, ii = 1, o = 1, iii = 1; i < countN; i++)
    {
        if ( (min(ultimoElemento, valoreTastiera) < array[i] || array[i] > max(ultimoElemento, valoreTastiera)) )
        {
            printf("A %d^ valore: %d ;\n", ii, array[i]);
            ii++;
            array[i] = array[i] - 2;
        }

        if (array[i] < 10)
        {
            fprintf(ptrRisuletati, "%d^ valore: %d;\n", iii, array[i]);
            iii++;
        }
    }

    fclose(ptrRisuletati);
    return 0;
}

double min(double a, double b)
{
    if (a < b)
        return a;
    else
        return b;
}

double max(double a, double b)
{
    if (a > b)
        return a;
    else
        return b;
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
