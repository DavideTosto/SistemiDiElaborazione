#include <stdio.h>  // Libreria standard per input/output
#include <stdlib.h> // Libreria standard per funzioni generiche (es. gestione della memoria)

// Definizione di costanti
#define lnght 256 // Lunghezza massima del nome del file
#define N 10      // Dimensione massima dell'array

// Prototipo della funzione per la lettura di un numero
double getNum();

void main()
{
    FILE *ptrFile;        // Puntatore al file da cui leggere
    char nomeFile[lnght]; // Buffer per memorizzare il nome del file

    int primoNum, secondoNum; // Variabili per memorizzare i numeri letti dal file
    int array[N];             // Array per memorizzare le differenze tra i numeri letti
    int countN = 0;           // Contatore degli elementi nell'array

    FILE *ptrRisultati;       // Puntatore per il file di output
    double primoValore, secondoValore; // Variabili per memorizzare i valori forniti da tastiera

    // Ciclo per chiedere il nome del file finché non viene aperto correttamente
    do
    {
        printf("Inserisci il nome del file da caricare: ");
        scanf("%s", nomeFile); // Legge il nome del file inserito dall'utente

        ptrFile = fopen(nomeFile, "r"); // Apre il file in modalità lettura

        if (ptrFile == NULL) // Controlla se l'apertura del file è fallita
            printf("Errore: impossibile aprire il file\n");
    } while (ptrFile == NULL); // Ripete finché il file non viene aperto correttamente

    // Legge coppie di numeri dal file finché non raggiunge la fine (EOF) o l'array è pieno
    while (fscanf(ptrFile, "%d %d", &primoNum, &secondoNum) != EOF)
    {
        int differenza = primoNum - secondoNum; // Calcola la differenza tra i due numeri
        array[countN] = differenza;             // Memorizza la differenza nell'array
        countN++;                               // Incrementa il contatore degli elementi

        // Se l'array è pieno, interrompe il ciclo
        if (countN >= N)
            break;
    }

    

    fclose(ptrFile); // Chiude il file di input

    // Apre il file di output "se-appello-2021-12-Risultato.txt" in modalità scrittura
    ptrRisultati = fopen("se-appello-2021-12-Risultato.txt", "w");

    // Richiede due valori all'utente utilizzando la funzione getNum
    primoValore = getNum();
    secondoValore = getNum();

    // Cicla attraverso l'array di differenze per stampare e modificare gli elementi
    for (int i = 0, ii = 1, iii = 1; i < countN; i++)
    {
        // Stampa i valori dell'array compresi tra primoValore e secondoValore
        if ( (primoValore < array[i] && array[i] < secondoValore) ||
             (secondoValore < array[i] && array[i] < primoValore) )
        {
            printf("%d° valore: %d\n", ii, array[i]); // Stampa a video l'elemento selezionato
            ii++; // Incrementa il contatore per la stampa
        }

        // Sostituisce con 0 gli elementi dell'array uguali a primoValore o secondoValore
        if ( (array[i] == primoValore) || ( array[i] == secondoValore ) )
        {
            array[i] = 0; // Sostituzione del valore con 0
        }

        // Salva nel file di output solo gli elementi diversi da 0
        if ( array[i] != 0 )
        {
            fprintf(ptrRisultati, "%d° valore: %d\n", iii, array[i]); // Scrive l'elemento nel file
            iii++; // Incrementa il contatore per la scrittura
        }
    }

    fclose(ptrRisultati); // Chiude il file di output
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
