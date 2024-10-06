#include <stdio.h>
#include <stdlib.h>

// Definizione di costanti
#define lnght 256 // Lunghezza massima per il nome del file
#define N 10      // Numero massimo di elementi che possono essere inseriti nell'array

 // Funzione che restituisce il massimo tra due numeri interi
int max(int a, int b);    
// Funzione che garantisce che l'input sia un numero valido
double getNum();           

void main()
{
    FILE* ptrFile;                // Puntatore al file da cui leggere
    char nomeFile[lnght];         // Array per memorizzare il nome del file
    int primoNum, secondoNum;     // Variabili per memorizzare coppie di numeri letti dal file
    int array[N];                 // Array per memorizzare i numeri elaborati
    int countN = 0;               // Contatore per il numero di elementi inseriti nell'array

    FILE* ptrRisultati;           // Puntatore al file di output per i risultati
    double valore;                // Variabile per memorizzare il numero inserito dall'utente

    // Ciclo per chiedere all'utente di inserire il nome del file finché non viene aperto correttamente
    do
    {
        printf("Inserisci il nome del file: ");
        scanf("%s", nomeFile);  // Legge il nome del file inserito dall'utente

        // Apre il file in modalità lettura
        ptrFile = fopen(nomeFile, "r");
        if (ptrFile == NULL)
            printf("Errore: impossibile leggere il file\n");  // Messaggio di errore se il file non viene aperto

    } while (ptrFile == NULL);  // Continua a chiedere il nome finché il file non viene aperto correttamente

    // Ciclo per leggere coppie di numeri interi dal file
    while (fscanf(ptrFile, " %d %d", &primoNum, &secondoNum) != EOF)
    {
        // Inserisce il massimo tra i due numeri letti nell'array
        array[countN] = max(primoNum, secondoNum);
        countN++;  // Incrementa il contatore

        // Se l'array è pieno, esce dal ciclo
        if (countN >= N)
            break;
    }

    countN--;  // Decrementa il contatore per evitare un sovraincremento

    // Chiude il file di input
    fclose(ptrFile);

    // Apre il file di output per scrivere i risultati
    ptrRisultati = fopen("se-appello-2022-05-Risultati.txt", "w");

    // Chiede all'utente di inserire un numero e lo salva in 'valore'
    printf("Inserisci un numero: ");
    valore = getNum();

    // Ciclo per processare l'array e stampare i valori compresi tra 4 e il numero inserito
    for (int i = 0, ii = 1; i <= countN; i++)
    {
        // Controlla se l'elemento dell'array è compreso tra 4 e il numero inserito dall'utente
        if ((4 <= array[i] && array[i] <= valore) ||
            (valore <= array[i] && array[i] <= 4))
        {
            // Stampa l'elemento se soddisfa la condizione
            printf("%d° valore: %d\n", ii, array[i]);
            array[i] = -1;  // Imposta l'elemento dell'array a -1 dopo la stampa
            ii++;  // Incrementa il contatore dei valori stampati
        }

        // Scrive l'elemento dell'array nel file di output
        fprintf(ptrRisultati, "Array[%d] = %d\n", i, array[i]);
    }

    // Chiude il file di output
    fclose(ptrRisultati);
}

// Funzione che restituisce il massimo tra due numeri interi
int max(int a, int b)
{
    if (a > b)
        return a;  // Se 'a' è maggiore, restituisce 'a'
    else
        return b;  // Altrimenti restituisce 'b'
}

// Funzione che legge un numero dall'utente, assicurandosi che sia valido
double getNum()
{
    double valore;
    int check;
    char ch;

    // Ciclo per garantire che l'input sia un numero valido
    do
    {
        check = scanf("%lf", &valore);  // Legge il numero e salva lo stato in 'check'
        ch = getchar();  // Legge il carattere successivo
        if (check != 1 || ch != '\n')   // Controlla se l'input non è un numero o ci sono altri caratteri
        {
            printf("Errore: Inserisci un numero -> ");
            while (getchar() != '\n');  // Consuma i caratteri rimanenti nel buffer di input
        }
    } while (check != 1 || ch != '\n');  // Ripete finché l'input non è un numero valido

    printf("\n");

    return valore;  // Restituisce il numero valido
}
