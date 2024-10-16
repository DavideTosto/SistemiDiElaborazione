#include <stdlib.h>  // Inclusione della libreria standard per l'allocazione della memoria e altre funzioni utili
#include <stdio.h>   // Inclusione della libreria standard di input/output

#define lnghtNome 256 // Definizione di una costante per la lunghezza massima del nome del file
#define N 5          // Definizione di una costante per la dimensione massima dell'array
#define TENTATIVI 10 // Definizione di una costante per il numero massimo di tentativi 

// Dichiarazione di funzioni
int max(int a, int b, int c);          // Funzione per trovare il valore massimo tra tre numeri
void ordina(double *Vett);              // Funzione per ordinare due valori
double getNum();                        // Funzione per leggere un numero dall'utente

int main()
{
    FILE *ptrFile;                     // Puntatore al file di input
    char nomeFile[lnghtNome];          // Array per memorizzare il nome del file
    int primoVal, secondoVal, terzoVal; // Variabili per memorizzare i valori letti dal file

    int array[N];                       // Array per memorizzare i risultati
    int countN = 0;                    // Contatore per il numero di elementi validi nell'array

    FILE *ptrRisultati;                // Puntatore al file di output per i risultati
    double valori[2];                  // Array per memorizzare due valori (il massimo e un valore inserito dall'utente)


    int err = 0;                       // Contatore per il numero di errori
    // Ciclo per ottenere un nome di file valido dall'utente
    do
    {
        printf("Inserisci il nome del File: "); // Richiesta del nome del file
        scanf("%s", nomeFile);                   // Lettura del nome del file
        ptrFile = fopen(nomeFile, "r");         // Tentativo di apertura del file in modalità lettura
        if (ptrFile == NULL)                     // Controllo se l'apertura del file è fallita
        {
            printf("Errore: impossibile aprire il file!"); // Messaggio di errore
            if ( err > TENTATIVI )               // se il numero di errore supera i tentativi massimi
                return -1;                       // termina il programma con un errore
        }

    } while (ptrFile == NULL); // Ripeti finché il file non è stato aperto correttamente

    // Lettura dei valori dal file finché non si raggiunge la fine del file
    while (fscanf(ptrFile, "%d %d %d", &primoVal, &secondoVal, &terzoVal) != EOF)
    {
        int somma = primoVal + secondoVal + terzoVal; // Calcolo della somma dei tre valori
        if (somma % 2 == 0) // Controllo se la somma è pari
        {
            array[countN] = max(primoVal, secondoVal, terzoVal); // Memorizza il massimo dei tre valori
            countN++; // Incrementa il contatore
        }
        else // Se la somma è dispari
        {
            array[countN] = somma; // Memorizza la somma nell'array
            countN++; // Incrementa il contatore
        }

        if (countN >= N) // Controllo per evitare di superare la dimensione massima dell'array
            break; // Esci dal ciclo se l'array è pieno
    }

    fclose(ptrFile); // Chiusura del file di input
    ptrRisultati = fopen("se-appello-2024-07-Risultati_v2.txt", "w"); // Apertura del file di output in modalità scrittura

    valori[0] = array[countN - 1]; // Assegna l'ultimo valore dell'array a valori[0]
    printf("Inserisci un numero: "); // Richiesta di un numero all'utente
    valori[1] = getNum(); // Lettura del numero dall'utente

    ordina(valori); // Chiamata alla funzione per ordinare i due valori

    // Stampa dei valori che soddisfano le condizioni stabilite
    for (int i = 0, ii = 1; i < countN; i++) // Ciclo attraverso gli elementi dell'array
    {
        // Controllo se il valore attuale è compreso tra i due valori inseriti
        if (valori[0] <= array[i] && array[i] <= valori[1]) 
        {
            printf("%d^ valore: %d\n", ii, array[i]); // Stampa il valore corrente
            ii++; // Incrementa il contatore per la stampa
            array[i] = array[i] + 3; // Incrementa il valore nell'array di 3
        }

        if (array[i] > 5) // Controllo se il valore è maggiore di 5
        {
            fprintf(ptrRisultati, "Array[%d] = %d\n", i, array[i]); // Scrive il valore nel file di output
        }
    }

    fclose(ptrRisultati); // Chiusura del file di output
}

// Funzione per trovare il massimo tra tre numeri
int max(int a, int b, int c)
{
    if (a >= b && a >= c) // Se 'a' è il massimo
        return a; // Restituisci 'a'
    if (b >= a && b >= c) // Se 'b' è il massimo
        return b; // Restituisci 'b'
    else
        return c; // Altrimenti, restituisci 'c'
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

// Funzione per ordinare due valori, mettendo il minore nella prima posizione dell'array
void ordina (double *Vett)
{
    double temp; // Variabile temporanea per lo scambio
    if ( Vett[0] > Vett[1] ) // Se il primo valore è maggiore del secondo
    {
        temp = Vett[0];     // Salva il primo valore in temp
        Vett[0] = Vett[1];  // Assegna il secondo valore al primo
        Vett[1] = temp;     // Assegna il valore di temp al secondo
    }
}