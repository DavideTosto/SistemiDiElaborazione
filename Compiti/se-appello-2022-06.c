#include <stdlib.h>
#include <stdio.h>

// Definizione di costanti
#define lnght 256 // Lunghezza massima per il nome del file
#define N 10      // Numero massimo di elementi che possono essere inseriti nell'array

// Funzione che restituisce il massimo tra due numeri interi
int max(int a, int b);
double getNum();

void main()
{
    FILE *ptrFile;        // Puntatore al file da leggere
    char nomeFile[lnght]; // Array per contenere il nome del file

    int primoNum, secondoNum; // Variabili per memorizzare coppie di numeri lette dal file
    int array[N];             // Array per memorizzare i numeri elaborati
    int countN = 0;           // Contatore per il numero di elementi inseriti nell'array

    FILE *ptrRisultati;          // Puntatore al file di output per i risultati
    double primoVal, secondoVal; // Valori limite inseriti dall'utente per filtrare i numeri dell'array

    // Ciclo per chiedere all'utente di inserire il nome del file finché non viene aperto correttamente
    do
    {
        printf("Inserisci il nome del file: ");
        scanf("%s", nomeFile); // Legge il nome del file inserito dall'utente

        ptrFile = fopen(nomeFile, "r"); // Tenta di aprire il file in modalità di lettura

        if (ptrFile == NULL)
            printf("Errore: impossibile aprire il file\n"); // Messaggio di errore se il file non esiste

    } while (ptrFile == NULL); // Continua a chiedere il nome del file finché non viene aperto correttamente

    // Lettura di coppie di numeri interi dal file finché non si raggiunge la fine del file o l'array è pieno
    while (fscanf(ptrFile, " %d %d", &primoNum, &secondoNum) != EOF)
    {
        int massimo = max(primoNum, secondoNum); // Trova il massimo tra i due numeri

        // Se il massimo è pari, lo inserisce nell'array
        if (massimo % 2 == 0)
        {
            array[countN] = massimo;
        }
        // Se il massimo è dispari, inserisce l'altro numero nell'array
        else
        {
            if (primoNum == massimo)
                array[countN] = secondoNum;
            else
                array[countN] = primoNum;
        }

        countN++; // Incrementa il contatore degli elementi nell'array

        // Se l'array è pieno, esce dal ciclo
        if (countN >= N)
            break;
    }

    countN--; // Decrementa il contatore perché l'ultimo incremento è fuori dal ciclo

    // Chiude il file di input
    fclose(ptrFile);

    // Apre il file di output per scrivere i risultati
    ptrRisultati = fopen("se-appello-2022-06-risultati.txt", "w");

    // Richiede all'utente di inserire due valori per filtrare gli elementi dell'array
    printf("Inserisci il primo valore: ");
    primoVal = getNum();
    printf("Inserisci il secondo valore: ");
    secondoVal = getNum();

    // Stampa i valori dell'array e li filtra in base ai valori limite
    printf("Stampa valori array:\n");
    for (int i = 0, ii=1; i <= countN; i++)
    {

        // Verifica se l'elemento dell'array è compreso tra i due valori inseriti dall'utente
        if ((primoVal <= array[i] && array[i] <= secondoVal) ||
            (secondoVal <= array[i] && array[i] <= primoVal))
        {
            printf("%d° valore ", ii);
            printf("%d\n", array[i]); // Stampa l'elemento se soddisfa la condizione
            array[i] = -1;            // Imposta l'elemento a -1 se soddisfa la condizione
            ii++;
        }
        

        // Scrive l'elemento dell'array nel file di output
        fprintf(ptrRisultati, "%d\n", array[i]);
    }

    // Chiude il file di output
    fclose(ptrRisultati);
}

// Funzione che restituisce il massimo tra due numeri interi
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

double getNum()
{
    double valore;
    int check;
    char ch;

    do
    {
        check = scanf("%lf", &valore);
        ch = getchar();
        if (check != 1 || ch != '\n')
        {
            printf("Errore: Inserisci un numero -> ");
            while (getchar() != '\n');
        }
    }while(check != 1 || ch != '\n');

    printf("\n");

    return valore;
}
