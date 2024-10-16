#include <stdio.h>
#include <stdlib.h>

#define NOME 256
#define TENTATIVI 10
#define N 8

int diversi(int a, int b, int c);
int coppie(int a, int b, int c);
void ordinaCrescente(double *ptrVett, int dim);
double getNum();

int main()
{
    FILE *ptrFile;
    char nomeFile[NOME];

    int primoVal, secondoVal, terzoVal;
    int array[N];
    int countN = 0;

    FILE *ptrRisultati;

    int err = 0;
    do
    {
        printf("Inserisci il nome del file: ");
        scanf("%s", nomeFile);

        ptrFile = fopen(nomeFile, "r");

        if (ptrFile == NULL)
        {
            printf("Errore: il file non può essere aperto.\n");
            err++;
            if (err > TENTATIVI)
                return -1;
        }
    } while (ptrFile == NULL);

    while (fscanf(ptrFile, "%d %d %d", &primoVal, &secondoVal, &terzoVal) != EOF)
    {
        int somma = primoVal + secondoVal + terzoVal;
        double vettore[3];
        vettore[0] = primoVal;
        vettore[1] = secondoVal;
        vettore[2] = terzoVal;
        ordinaCrescente(vettore, 3);

        if ((somma % 2 == 0) && diversi(primoVal, secondoVal, terzoVal))
        {
            array[countN] = vettore[1];
            countN++;
        }

        else if ((somma % 2 != 0) || coppie(primoVal, secondoVal, terzoVal))
        {
            array[countN] = abs(vettore[2] - vettore[0]);
            countN++;
        }

        if (countN >= N)
            break;
    }

    fclose(ptrFile);
    ptrRisultati = fopen("se-appello-2024-004-Risultati.txt", "w");

    double vettore[2];
    vettore[0] = getNum();
    vettore[1] = getNum();

    for (int i = 0, ii = 1, iii = 1; i < countN; i++)
    {
        if (vettore[0] <= array[i] && array[i] <= vettore[1])
        {
            printf("%d^ valore: %d;\n", ii, array[i]);
            ii++;
            array[i] = array[i] + 2;
        }
        if (array[i] > 10)
        {
            printf("%d^ valore: %d;\n", iii, array[i]);
            iii++;
        }
    }

    fclose(ptrRisultati);
    return 0;
}

int diversi(int a, int b, int c)
{
    if ((a != b) && (a != c) && (b != c))
        return 1;
    else
        return 0;
}

// Funzione per ordinare in modo crescente tramite metodo bubble sort
void ordinaCrescente(double *ptrVett, int dim)
{
    for (int i = 0; i < dim - 1; i++)
    {
        for (int j = 0; j < dim - i - 1; j++)
        {
            // Controlla se l'elemento corrente è maggiore di quello successivo
            if (ptrVett[j] > ptrVett[j + 1])
            {
                // Scambia gli elementi
                double temp = ptrVett[j];
                ptrVett[j] = ptrVett[j + 1];
                ptrVett[j + 1] = temp;
            }
        }
    }
}

int coppie(int a, int b, int c)
{
    if ((a == b) || (b == c) || (c == a))
        return 1;
    else
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
