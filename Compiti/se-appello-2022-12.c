#include <stdlib.h>
#include <stdio.h>

#define lnghtNome 256 // Definisce la lunghezza massima per il nome del file
#define N 5           // Definisce la dimensione massima dell'array

void main()
{
    FILE *ptrFile;  // Puntatore per gestire il file da cui leggere
    char nomeFile[lnghtNome]; // Array per contenere il nome del file

    int valoreUno, valoreDue, prodotto; // Variabili per memorizzare i due numeri letti e il loro prodotto
    int array[N];       // Array per memorizzare i valori elaborati
    int countN = 0;     // Contatore per i valori inseriti nell'array

    FILE *ptrRisultati; // Puntatore per gestire il file di output
    double valoreDaTastiera; // Variabile per memorizzare un valore inserito da tastiera

    // Ciclo do-while per richiedere all'utente il nome di un file finché non viene aperto correttamente
    do
    {
        printf("Inserisci il nome del file: ");
        scanf("%s", nomeFile); // Legge il nome del file inserito dall'utente

        ptrFile = fopen(nomeFile, "r"); // Prova ad aprire il file in modalità lettura
        if (ptrFile == NULL) // Se il file non può essere aperto, stampa un messaggio di errore
        {
            printf("Errore: il file non può essere aperto");
        }
    } while (ptrFile == NULL); // Continua a richiedere il nome finché il file non è aperto correttamente

    // Ciclo per leggere coppie di numeri interi dal file
    while (fscanf(ptrFile, " %d %d ", &valoreUno, &valoreDue) != EOF) // Legge due numeri interi dal file
    {
        prodotto = valoreUno * valoreDue; // Calcola il prodotto dei due numeri

        // Se il prodotto è pari, lo inserisce nell'array
        if ((prodotto % 2) == 0)
        {
            array[countN] = prodotto; // Inserisce il prodotto nell'array
            countN++; // Incrementa il contatore
        }
        else // Se il prodotto è dispari, inserisce la somma dei due numeri nell'array
        {
            array[countN] = valoreUno + valoreDue; // Inserisce la somma nell'array
            countN++; // Incrementa il contatore
        }

        // Se l'array raggiunge la dimensione massima, esce dal ciclo
        if (countN >= N)
        {
            countN--; // Decrementa per evitare di superare i limiti dell'array
            break;    // Esce dal ciclo
        }
    }

    fclose(ptrFile); // Chiude il file di input

    // Apre un file per scrivere i risultati
    ptrRisultati = fopen("se-appello-2022-12-Risultati.txt", "w");

    // Richiede un valore da tastiera
    printf("\nInserisci un valore da tastiera: ");
    scanf("%lf", &valoreDaTastiera); // Legge un valore double da tastiera

    // Ciclo per elaborare e stampare i valori contenuti nell'array
    for (int i = 0; i <= countN; i++)
    {
        // Controlla se il valore dell'array è compreso tra 20 e il valore inserito da tastiera, o viceversa
        if ((20 <= array[i] && array[i] <= valoreDaTastiera) ||
            (valoreDaTastiera <= array[i] && array[i] <= 20))
        {
            printf(" %d,", array[i]); // Stampa il valore se soddisfa la condizione
            array[i] = -1;            // Imposta il valore dell'array a -1
        }

        // Scrive il valore (modificato o meno) nel file di risultati
        fprintf(ptrRisultati, "%d\n", array[i]);
    }

    fclose(ptrRisultati); // Chiude il file di output
}
