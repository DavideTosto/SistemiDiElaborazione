#include <stdio.h>
#define DIM 20

void scelta(char *a);
void stampaVettore(double *ptrVett, int dim);
void ordinaDecrescente(double *ptrVett, int dim, int i);
int ricercaValore(double *ptrVett, int dim, double val);
// int ricercaValoreRicorsione(double *ptrVett, int dim, double val, int i);

void main()
{
    printf("Programma che, ricevuti in ingresso gli elementi di un vettore di dimensione");
    printf("\nspecificata dall utente e dimensione massima DIM = 20, implementa, sfruttando la ricorsione, l' ordinamento crescente ");
    printf("\n oppure ricerca un valore inserito da tastiera iterando tra gli elementi.");
    char riesecuzione, YoN;
    int MSGcambioValori = 0; // flag messaggio
    int opzione;

    do
    {
        double vettore[DIM];
        int n; // n umero elementi vettore

        if (MSGcambioValori == 1)
        {
            printf("Vuoi cabiare i valori del'array? ");
            scelta(&YoN);
        }
        if (YoN || !MSGcambioValori)
        {
            // Input della dimensione del vettore
            do
            {
                printf("\n\nInserisci la dimensione del vettore (max %d): ", DIM);
                scanf("%d", &n);
            } while (n <= 0 || n > DIM);

            // Input degli elementi del vettore
            printf("\nInserisci gli elementi del vettore:\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%lf", &vettore[i]);
            }
        }

        // Stampa del vettore
        printf("Vettore: ");
        stampaVettore(vettore, n);

        // Scelta dell'operazione
        printf("Scegli l'operazione:\n");
        printf("1. Ordinamento decrescente\n");
        printf("2. Ricerca di un valore\n");
        printf("Operazione da eseguire n. -> ");
        scanf("%d", &opzione);

        switch (opzione)
        {
        case 1:
            // Ordinamento decrescente
            ordinaDecrescente(vettore, n, 0);
            printf("Vettore ordinato: ");
            stampaVettore(vettore, n);
            break;

        case 2:
            // Ricerca di un valore
            int valore;
            printf("Inserisci il valore da cercare: ");
            scanf("%d", &valore);
            ricercaValore(vettore, n, valore);
            break;

        default:
            printf("Scelta non valida");
            break;
        }

        printf("\nVuoi continuare? ");
        scelta(&YoN);
        MSGcambioValori = 1;
    } while (YoN);
}

void scelta(char *a)
{
    do
    {
        printf("(Y/N) : ");
        scanf(" %c", a);
    } while (*a != 'N' && *a != 'n' &&
             *a != 'Y' && *a != 'y');
    if (*a == 'Y' || *a == 'y')
    {
        *a = 1;
    }
    else
    {
        *a = 0;
    }
}

void stampaVettore(double *ptrVett, int dim)
{
    printf("[ ");
    for (int i = 0; i < dim; i++)
    {
        printf("%lf ", ptrVett[i]);
    }
    printf("]\n");
}

// Funzione per ordinare in modo decrescente tramite selezione ricorsiva
void ordinaDecrescente(double *ptrVett, int dim, int i)
{
    if (i >= dim - 1)
        return; // Caso base: fine del vettore
    int maxIndice = i;
    for (int j = i + 1; j < dim; j++)
    {
        if (ptrVett[j] > ptrVett[maxIndice])
        {
            maxIndice = j;
        }
    }
    // Scambio
    if (maxIndice != i)
    {
        double temp = ptrVett[i];
        ptrVett[i] = ptrVett[maxIndice];
        ptrVett[maxIndice] = temp;
    }

    // Stampa il vettore dopo ogni passo
    printf("Passo ordinamento %d: ", i + 1);
    stampaVettore(ptrVett, dim);

    // Ricorsione per l'elemento successivo
    ordinaDecrescente(ptrVett, dim, i + 1);
}


// Funzione per la ricerca di un valore 
int ricercaValore(double *ptrVett, int dim, double val)
{
    int flag = 1;
    for (int i = 0; i < dim; i++)
    {
        if ( ptrVett[i] == val )
        {
            printf("Valore %lf trovato all'indice %d.\n", val, i);
            flag = 0;
        }
    }
    if (flag)
        printf("Valore non trovato");
    
}

/****** NON PIU' UTILIZZATE ******/
/* Funzione per la ricerca di un valore nel vettore tramite ricorsione
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
    return ricercaValoreRicorsione(ptrVett, dim, val, i + 1); // Ricorsione
}*/