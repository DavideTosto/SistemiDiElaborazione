#include <stdio.h>
#include <stdlib.h>
#define DIM 20 // Definisce la dimensione massima del vettore

// Dichiarazione delle funzioni
void scelta(char *a);
void stampaVettore(double *ptrVett, int dim);
void ordinaDecrescente(double *ptrVett, int dim, int i);
void ordinaCrescente(double *ptrVett, int dim);
void salvaSuFile(double *ptrVett, int dim);
int ricercaValore(double *ptrVett, int dim, double val);
double getNum();

int main()
{
    // Introduzione al programma
    printf("************* Sistemi di Elaborazione: 'Seconda Etivity' - Studente: Davide Tosto - Matricola: IN08000226 *************");
    printf("\n\nProgramma che, ricevuti in ingresso gli elementi di un vettore di dimensione specificata dall'utente e dimensione");
    printf("\nmassima DIM = 20, implementa, sfruttando la ricorsione l'ordinamento decrescente, oppure ricerca un valore inserito");
    printf("\nda tastiera nel vettore iterando tra gli elementi.");

    char riesecuzione, YoN;  // Variabili per gestire l'input dell'utente
    int MSGcambioValori = 0; // Flag per mostrare il messaggio di cambio valori
    int opzione;             // Variabile per memorizzare l'opzione scelta dall'utente

    do
    {
        double vettore[DIM]; // Vettore di dimensione massima DIM
        int n;               // Variabile per memorizzare il numero di elementi del vettore

        if (MSGcambioValori == 1)
        {
            // Chiede all'utente se vuole cambiare i valori del vettore
            printf("Vuoi cambiare i valori dell'array? ");
            scelta(&YoN); // Funzione per scegliere Sì o No
        }

        // Se l'utente ha scelto di cambiare i valori o è il primo ciclo
        if (YoN || !MSGcambioValori)
        {
            // Input della dimensione del vettore
            do
            {
                printf("\n\nInserisci la dimensione del vettore (max %d): ", DIM);
                n = (int)getNum();                              // Chiede all'utente di inserire la dimensione
            } while (n <= 0 || n > DIM);                        // Controlla che la dimensione sia valida

            // Input degli elementi del vettore
            printf("\nInserisci gli elementi del vettore:\n");
            for (int i = 0; i < n; i++)
            {
                printf("Inserisci il %d^ numero: ", i + 1);
                vettore[i] = getNum();                          // Chiede all'utente di inserire ogni numero
            }
        }

        // Stampa del vettore
        printf("\nVettore: ");
        stampaVettore(vettore, n); // Funzione per stampare il vettore

        // Scelta dell'operazione da eseguire
        printf("\nScegli l'operazione:\n");
        printf("1. Ordinamento decrescente\n");
        printf("2. Ricerca di un valore\n");
        printf("3. Ordinamento crescente\n");
        printf("4. Salva il vettore su file\n");
        printf("Operazione da eseguire n. -> ");
        
        opzione = (int)getNum(); // Chiede all'utente di scegliere un'operazione
        printf("\n");
        
        switch (opzione)
        {
        case 1:
            // Ordinamento decrescente
            ordinaDecrescente(vettore, n, 0); // Funzione per ordinare il vettore a partire dalla posizione 0
            printf("Vettore ordinato: ");
            stampaVettore(vettore, n);        // Stampa il vettore ordinato
            break;

        case 2:
            // Ricerca di un valore
            double valore;
            printf("Inserisci il valore da cercare: ");
            valore = getNum();                         // Inserimento del valore da cercare
            ricercaValore(vettore, n, valore);         // Funzione per cercare il valore
            break;

        case 3:
            // Ordinamento crescente
            ordinaCrescente(vettore, n);    // Ordinamento crescente con bubble sort
            printf("Vettore ordinato: ");
            stampaVettore(vettore, n);      // Stampa il vettore ordinato
            break;

        case 4:
            // Salvataggio su file di testo
            salvaSuFile(vettore, n);
            break;

        default:
            printf("Scelta non valida\n"); // Messaggio in caso di opzione non valida
            break;
        }

        // Chiede all'utente se vuole continuare
        printf("\nVuoi continuare? ");
        scelta(&YoN);        // Funzione per la scelta di continuare o meno
        MSGcambioValori = 1; // Attiva il messaggio per cambiare valori alla prossima iterazione
    } while (YoN);           // Ciclo finché l'utente sceglie di continuare

    return 0; // Termina il programma
}

// Funzione per la scelta dell'utente (Sì o No)
void scelta(char *a)
{
    do
    {
        printf("(Y/N) : ");
        scanf(" %c", a);                                          // Legge il carattere inserito
    } while ((*a != 'N' && *a != 'n' && *a != 'Y' && *a != 'y')); // Verifica se l'input è valido

    if (*a == 'Y' || *a == 'y')
    {
        *a = 1; // Ritorna 1 se la risposta è Sì
    }
    else
    {
        *a = 0; // Ritorna 0 se la risposta è No
    }
}

// Funzione per stampare il vettore
void stampaVettore(double *ptrVett, int dim)
{
    printf("[ ");
    for (int i = 0; i < dim; i++)
    {
        printf("%.3lf ", ptrVett[i]); // Stampa ogni elemento del vettore
    }
    printf("]\n");
}

// Funzione per ordinare in modo decrescente tramite selezione ricorsiva
void ordinaDecrescente(double *ptrVett, int dim, int i)
{
    if (i >= dim - 1)
        return;                        // Caso base: se si è arrivati alla fine del vettore, termina la ricorsione

    int maxIndice = i;                 // Indice dell'elemento massimo
    for (int j = i + 1; j < dim; j++)
    {
        // Cerca il massimo tra gli elementi non ancora ordinati
        if (ptrVett[j] > ptrVett[maxIndice])
        {
            maxIndice = j;             // Aggiorna l'indice del massimo
        }
    }

    // Scambia l'elemento corrente con il massimo trovato
    if (maxIndice != i)
    {
        double temp = ptrVett[i];
        ptrVett[i] = ptrVett[maxIndice];
        ptrVett[maxIndice] = temp;
    }

    // Stampa il vettore dopo ogni passo dell'ordinamento
    printf("Passo ordinamento %d: ", i + 1);
    stampaVettore(ptrVett, dim);

    // Ricorsione per ordinare l'elemento successivo
    ordinaDecrescente(ptrVett, dim, i + 1);
}

// Funzione per la ricerca di un valore nel vettore
int ricercaValore(double *ptrVett, int dim, double val)
{
    int flag = 1;         // Flag per verificare se il valore è stato trovato
    for (int i = 0; i < dim; i++)
    {
        // Controlla se l'elemento corrente è uguale al valore cercato
        if (ptrVett[i] == val)
        {
            printf("Valore %.3lf trovato all'indice %d.\n", val, i); // Valore trovato
            flag = 0; // Aggiorna il flag
        }
    }
    if (flag)
        printf("Valore non trovato\n"); // Messaggio se il valore non è presente
}

// Funzione che legge un numero dall'utente, assicurandosi che sia valido
double getNum()
{
    double valore; // Variabile per memorizzare il numero inserito dall'utente
    int check;     // Variabile di controllo per verificare la validità dell'input
    char ch;       // Variabile per memorizzare i caratteri extra nel buffer di input

    // Ciclo per garantire che l'input sia un numero valido
    do
    {
        check = scanf("%lf", &valore); // Legge il numero e salva lo stato in 'check'
        ch = getchar();                // Legge il carattere successivo nel buffer
        if (check != 1 || ch != '\n')  // Controlla se l'input non è un numero o se ci sono altri caratteri
        {
            printf("Errore: Inserisci un numero -> ");
            while (getchar() != '\n');  // Consuma i caratteri rimanenti nel buffer di input
        }
    } while (check != 1 || ch != '\n'); // Continua finché l'input non è valido

    return valore; // Restituisce il valore valido
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
        // Stampa il vettore dopo ogni passo del Bubble Sort
        printf("Passo ordinamento %d: ", i + 1);
        stampaVettore(ptrVett, dim);
    }
}

// Funzione per salvare il vettore su un file di testo
void salvaSuFile(double *ptrVett, int dim)
{
    char YoN;
    FILE *file;

    do
    {
        file = fopen("Salvataggio.txt", "w"); // Apre il file in modalità scrittura

        if (file == NULL)
        {
            printf("Errore durante l'apertura del file.\n");
            printf("\nVuoi riprovare? ");
            scelta(&YoN);
        }
    } while (&YoN && (file == NULL));

    if (file == NULL)
    {
        printf("Impossibile salvare il vettore.");
        return;
    }

    // Scrive gli elementi del vettore nel file
    fprintf(file, "Vettore: [ ");
    for (int i = 0; i < dim; i++) {
        fprintf(file, "%.3lf ", ptrVett[i]); // Scrive ogni elemento nel file
    }
    fprintf(file, "]\n");

    fclose(file); // Chiude il file
    printf("Salvataggio effettuato con successo!\n"); // Messaggio di conferma
}