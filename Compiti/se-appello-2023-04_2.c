#include <stdio.h>
#include <stdlib.h>

#define nome 256  // Definisce una costante per la lunghezza massima del nome del file
#define N 3       // Definisce la dimensione dell'array

// Funzione che restituisce il massimo tra due numeri interi
int max(int a, int b); 

// Funzione che legge un numero in virgola mobile dall'utente, con validazione
double getNum();

void main()
{
    FILE *ptrFile;          // Puntatore al file di input
    char nomeFile[nome];     // Buffer per memorizzare il nome del file

    int primoNum, secondoNum;  // Variabili per memorizzare i numeri letti dal file
    int array[N];              // Array che memorizza i risultati
    int countN = 0;            // Contatore per tenere traccia degli elementi inseriti nell'array

    FILE *ptrRisultati;        // Puntatore al file di output per i risultati
    double primoVal, secondoVal; // Valori limite inseriti dall'utente

    // Ciclo per assicurarsi che il file sia aperto correttamente
    do
    {
        printf("Inserisci il nome del file: ");
        scanf("%s", nomeFile);  // Legge il nome del file dall'utente

        ptrFile = fopen(nomeFile, "r");  // Apre il file in modalità lettura
        if (ptrFile == NULL)             // Verifica se il file è stato aperto correttamente
            printf("Errore: Impossibile aprire il file\n");

    } while (ptrFile == NULL);  // Continua a richiedere il nome del file finché non viene aperto correttamente

    // Ciclo che legge coppie di numeri dal file
    while (fscanf(ptrFile, "%d %d", &primoNum, &secondoNum) != EOF)
    {
        // Calcola il massimo tra i due numeri letti
        int maggiore = max(primoNum, secondoNum);

        // Condizione: se il prodotto dei due numeri è minore di 10, memorizza il maggiore nell'array
        if ((primoNum * secondoNum) < 10)
            array[countN] = maggiore;
        else  // Altrimenti, memorizza l'indice corrente
            array[countN] = countN;

        countN++;  // Incrementa il contatore dell'array
        if (countN >= N)  // Interrompe la lettura se l'array è pieno
            break;
    }
    countN--;  // Riduce il contatore per gestire correttamente l'indice

    fclose(ptrFile);  // Chiude il file di input

    // Apre il file di output per scrivere i risultati
    ptrRisultati = fopen("se-appello-2022-03-risultati.txt", "w");

    // Legge due numeri dall'utente utilizzando la funzione getNum()
    primoVal = getNum();
    secondoVal = getNum();

    // Ciclo per stampare e memorizzare i valori dell'array
    for (int i = 0, ii = 1; i <= countN; i++)
    {
        // Condizione per verificare se l'elemento dell'array è compreso tra primoVal e secondoVal
        if ((primoVal <= array[i] && array[i] <= secondoVal) ||
            (secondoVal <= array[i] && array[i] <= primoVal))
        {
            // Stampa l'elemento dell'array se soddisfa la condizione
            printf("%d° elemento: %d;\n", ii, array[i]);
            ii++;  // Incrementa il contatore per la stampa

            // Imposta l'elemento dell'array a 1
            array[i] = 1;
        }
        // Scrive l'elemento dell'array nel file di risultati
        fprintf(ptrRisultati, "Array[%d] = %d\n", i, array[i]);
    }

    fclose(ptrRisultati);  // Chiude il file di output
}

// Funzione che restituisce il massimo tra due numeri interi
int max(int a, int b)
{
    if (a > b)
        return a;  // Restituisce 'a' se è maggiore di 'b'
    else
        return b;  // Altrimenti restituisce 'b'
}

// Funzione che legge un numero dall'utente, assicurandosi che sia valido
double getNum()
{
    double valore;  // Variabile per memorizzare il numero inserito dall'utente
    int check;      // Variabile di controllo per verificare se l'input è valido
    char ch;        // Variabile per gestire i caratteri extra nell'input

    // Chiede all'utente di inserire un numero
    printf("Inserisci un numero: ");

    // Ciclo per garantire che l'input sia un numero valido
    do
    {
        check = scanf("%lf", &valore); // Legge il numero e salva lo stato in 'check'
        ch = getchar();                // Legge il carattere successivo
        if (check != 1 || ch != '\n')  // Controlla se l'input non è un numero o ci sono altri caratteri
        {
            printf("Errore: Inserisci un numero -> ");
            while (getchar() != '\n')
                ; // Consuma i caratteri rimanenti nel buffer di input
        }
    } while (check != 1 || ch != '\n'); // Ripete finché l'input non è un numero valido

    printf("\n");

    return valore; // Restituisce il numero valido
}
