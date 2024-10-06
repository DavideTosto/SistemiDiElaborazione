#include <stdio.h>  // Libreria standard per input/output
#include <stdlib.h> // Libreria standard per funzioni generiche (es. gestione della memoria)

// Definizione di costanti
#define lnght 256  // Lunghezza massima del nome del file
#define N 10       // Dimensione massima dell'array

// Prototipo della funzione per la lettura di un numero
double getNum();

void main()
{
    FILE *ptrFile;              // Puntatore al file da cui leggere
    char nomeFile[lnght];        // Buffer per memorizzare il nome del file

    int primoNum, secondoNum;    // Variabili per memorizzare i numeri letti dal file
    int array[N];                // Array per memorizzare le somme dei numeri pari
    int countN = 0;              // Contatore degli elementi nell'array
    double valore;               // Variabile per memorizzare il valore inserito dall'utente

    FILE *ptrRisultati;          // Puntatore per il file dei risultati

    // Ciclo per chiedere il nome del file finché non viene aperto correttamente
    do
    {
        printf("Inserisci il nome del file da caricare: ");
        scanf("%s", nomeFile);   // Legge il nome del file inserito dall'utente

        ptrFile = fopen(nomeFile, "r");  // Apre il file in modalità lettura

        if (ptrFile == NULL)     // Controlla se l'apertura del file è fallita
            printf("Errore: impossibile aprire il file\n");
    } while (ptrFile == NULL);   // Ripete finché il file non viene aperto correttamente

    // Ciclo per leggere coppie di numeri dal file fino alla fine del file (EOF)
    while (fscanf(ptrFile, " %d %d", &primoNum, &secondoNum) != EOF)
    {
        int somma = primoNum + secondoNum;  // Calcola la somma dei due numeri

        // Se la somma è pari, la memorizza nell'array
        if (somma % 2 == 0)
        {
            array[countN] = somma;  // Aggiunge la somma all'array
            countN++;               // Incrementa il contatore degli elementi
        }

        if (countN >= N)  // Se l'array è pieno, esce dal ciclo
            break;
    }
    countN--;  // Decrementa per avere l'ultimo indice corretto

    fclose(ptrFile);  // Chiude il file dopo la lettura

    // Apre il file per scrivere i risultati
    ptrRisultati = fopen("se-appello-2022-04-risultati.txt", "w");

    valore = getNum();  // Chiama la funzione per leggere un numero valido

    // Ciclo per elaborare e stampare i valori dell'array
    for (int i = 0, ii = 1; i <= countN; i++)
    {
        // Controlla se il valore corrente dell'array soddisfa le condizioni
        if ((16 < array[i] && array[i] < valore) ||
            (valore < array[i] && array[i] < 16))
        {
            printf("%d° valore %d\n", ii, array[i]);  // Stampa i valori validi
            ii++;  // Incrementa il contatore dei valori stampati
        }
        else
        {
            array[i] = -1;  // Se non soddisfa le condizioni, imposta l'elemento a -1
        }

        // Scrive i risultati nel file
        fprintf(ptrRisultati, "Array[%d] = %d\n", i, array[i]);
    }

    fclose(ptrRisultati);  // Chiude il file dei risultati
}

// Funzione che legge un numero dall'utente, assicurandosi che sia valido
double getNum()
{
    double valore;
    int check;
    char ch;

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
            while (getchar() != '\n') ; // Consuma i caratteri rimanenti nel buffer di input
        }
    } while (check != 1 || ch != '\n'); // Ripete finché l'input non è un numero valido

    printf("\n");

    return valore; // Restituisce il numero valido
}
