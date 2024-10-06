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
    int array[N];             // Array per memorizzare le somme dei numeri pari
    int countN = 0;           // Contatore degli elementi nell'array

    FILE *ptrRisultati;
    double valore;

    // Ciclo per chiedere il nome del file finché non viene aperto correttamente
    do
    {
        printf("Inserisci il nome del file da caricare: ");
        scanf("%s", nomeFile); // Legge il nome del file inserito dall'utente

        ptrFile = fopen(nomeFile, "r"); // Apre il file in modalità lettura

        if (ptrFile == NULL) // Controlla se l'apertura del file è fallita
            printf("Errore: impossibile aprire il file\n");
    } while (ptrFile == NULL); // Ripete finché il file non viene aperto correttamente

    while (fscanf(ptrFile, "%d %d", &primoNum, &secondoNum) != EOF)
    {
        int somma = primoNum + secondoNum;
        if (somma >= 16)
        {
            array[countN] = somma;
            countN++;
        }

        if (countN >= N)
            break;
    }

    countN--;

    fclose(ptrFile);
    ptrRisultati = fopen("se-appello-2022-03-Risultato.txt", "w");
    valore = getNum();

    for (int i = 0, ii = 1, iii = 1; i <= countN; i++)
    {
        if ((20 < array[i] && array[i] < valore) ||
            (valore < array[i] && array[i] < 20))
        {
            printf("%d° valore: %d;\n", ii, array[i]);
            ii++;
        }
        if (array[i] % 2 == 0)
            array[i] = 0;

        if (array[i] != 0)
        {
            fprintf(ptrRisultati, "%d° valore: %d;\n", iii, array[i]);
            iii++;
        }
        
    }
    fclose(ptrRisultati);
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
            while (getchar() != '\n')
                ; // Consuma i caratteri rimanenti nel buffer di input
        }
    } while (check != 1 || ch != '\n'); // Ripete finché l'input non è un numero valido

    printf("\n");

    return valore; // Restituisce il numero valido
}
