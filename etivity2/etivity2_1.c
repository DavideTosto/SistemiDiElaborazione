#include <stdio.h>
#define DIM 20 // Definisce la dimensione massima del vettore


void scelta(char *a);
void stampaVettore(double *ptrVett, int dim);
void ordinaDecrescente(double *ptrVett, int dim, int i);
int ricercaValore(double *ptrVett, int dim, double val);
// int ricercaValoreRicorsione(double *ptrVett, int dim, double val, int i);

void main()
{
    // Introduzione al programma
    printf("Programma che, ricevuti in ingresso gli elementi di un vettore di dimensione");
    printf("\nspecificata dall utente e dimensione massima DIM = 20, implementa, sfruttando la ricorsione, l' ordinamento crescente ");
    printf("\n oppure ricerca un valore inserito da tastiera iterando tra gli elementi.");
    
    char riesecuzione, YoN; // Variabili per gestire l'input dell'utente
    int MSGcambioValori = 0; // flag per mostrare il messaggio di cambio valori
    int opzione; // Variabile per memorizzare l'opzione scelta dall'utente

    do
    {
        double vettore[DIM]; // Vettore di dimensione massima DIM
        int n; // Variabile per memorizzare il numero di elementi del vettore

        if (MSGcambioValori == 1)
        {
            // Chiede all'utente se vuole cambiare i valori del vettore
            printf("Vuoi cabiare i valori del'array? ");
            scelta(&YoN); // Funzione per scegliere Sì o No
        }
        
        // Se l'utente ha scelto di cambiare i valori o è il primo ciclo
        if (YoN || !MSGcambioValori)
        {
            // Input della dimensione del vettore
            do
            {
                printf("\n\nInserisci la dimensione del vettore (max %d): ", DIM);
                scanf("%d", &n);
            } while (n <= 0 || n > DIM); // Controllo che la dimensione sia valida

            // Input degli elementi del vettore
            printf("\nInserisci gli elementi del vettore:\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%lf", &vettore[i]); // Inserimento dei valori nel vettore
            }
        }

        // Stampa del vettore
        printf("Vettore: ");
        stampaVettore(vettore, n); // Funzione per stampare il vettore

        // Scelta dell'operazione da eseguire
        printf("Scegli l'operazione:\n");
        printf("1. Ordinamento decrescente\n");
        printf("2. Ricerca di un valore\n");
        printf("Operazione da eseguire n. -> ");
        scanf("%d", &opzione);

        switch (opzione)
        {
        case 1:
            // Ordinamento decrescente
            ordinaDecrescente(vettore, n, 0); // Funzione per ordinare il vettore
            printf("Vettore ordinato: ");
            stampaVettore(vettore, n); // Stampa il vettore ordinato
            break;

        case 2:
            // Ricerca di un valore
            int valore;
            printf("Inserisci il valore da cercare: ");
            scanf("%d", &valore); // Inserimento del valore da cercare
            ricercaValore(vettore, n, valore); // Funzione per cercare il valore
            break;

        default:
            printf("Scelta non valida"); // Messaggio in caso di opzione non valida
            break;
        }

        // Chiede all'utente se vuole continuare
        printf("\nVuoi continuare? ");
        scelta(&YoN); // Funzione per la scelta di continuare o meno
        MSGcambioValori = 1; // Attiva il messaggio per cambiare valori alla prossima iterazione
    } while (YoN); // Ciclo finché l'utente sceglie di continuare
}

// Funzione per la scelta dell'utente (Sì o No)
void scelta(char *a)
{
    do
    {
        printf("(Y/N) : ");
        scanf(" %c", a); // Legge il carattere inserito
    } while (*a != 'N' && *a != 'n' && *a != 'Y' && *a != 'y'); // Verifica se l'input è valido
    
    // Converte l'input in valori booleani
    if (*a == 'Y' || *a == 'y')
    {
        *a = 1; // Se la risposta è Sì
    }
    else
    {
        *a = 0; // Se la risposta è No
    }
}

// Funzione per stampare il vettore
void stampaVettore(double *ptrVett, int dim)
{
    printf("[ ");
    for (int i = 0; i < dim; i++)
    {
        printf("%lf ", ptrVett[i]); // Stampa ogni elemento del vettore
    }
    printf("]\n");
}

// Funzione per ordinare in modo decrescente tramite selezione ricorsiva
void ordinaDecrescente(double *ptrVett, int dim, int i)
{
    if (i >= dim - 1)
        return; // Caso base: se si è arrivati alla fine del vettore, termina la ricorsione
    
    int maxIndice = i; // Indice dell'elemento massimo
    for (int j = i + 1; j < dim; j++)
    {
        // Cerca il massimo tra gli elementi non ancora ordinati
        if (ptrVett[j] > ptrVett[maxIndice])
        {
            maxIndice = j;
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
    int flag = 1; // Flag per verificare se il valore è stato trovato
    for (int i = 0; i < dim; i++)
    {
        // Controlla se l'elemento corrente è uguale al valore cercato
        if (ptrVett[i] == val)
        {
            printf("Valore %lf trovato all'indice %d.\n", val, i); // Valore trovato
            flag = 0; // Aggiorna il flag
        }
    }
    if (flag)
        printf("Valore non trovato"); // Messaggio se il valore non è presente
    
}

/****** NON PIU' UTILIZZATE ******/
// Funzione per la ricerca di un valore nel vettore tramite ricorsione
/*
int ricercaValoreRicorsione(double *ptrVett, int dim, double val, int i)
{
    if (i >= dim)
    {
        printf("Valore %lf non trovato nel vettore.\n", val);
        return -1; // Caso base: valore non trovato
    }
    if (ptrVett[i] == val)
    {
        return i;
    } // Caso base: valore trovato
    return ricercaValoreRicorsione(ptrVett, dim, val, i + 1); // Ricorsione per cercare il valore
}
*/
