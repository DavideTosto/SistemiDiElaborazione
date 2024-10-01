/* Scrivere un programma in ANSI C che, dato un file di testo che contiene in ogni 
riga una coppia di numeri (un intero ed un numero reale), esegua le seguenti  
operazioni: 
 
1. Carichi in un array i valori reali presenti nelle righe del file in cui il 
   corrispondente valore intero è dispari 
2. Stampi a video gli elementi di indice dispari dell’array 
3. Calcoli e stampi a video la somma degli elementi positivi e la somma degli  
   elementi negativi dell’array 
4. Salvi nel file "risultato.txt" gli elementi dell’array inferiori ad un  
   valore soglia inserito da tastiera. 
 
### Specifiche:  
 - La dimensione dell’array è N, con N pari a 10  - Il nome del file di ingresso deve essere inserito da input - Il numero di righe (cioè di coppie) nel file non è noto all’inizio. 
 
Eventuali elementi nel file che soddisfano la condizione in "1." 
ma che non possono essere caricati nel vettore poiché pieno, non devono essere 
prese in considerazione. */

#include <stdio.h>
#include <stdlib.h>

#define lnght 256
#define N 10


void main()
{
    FILE *ptrFile;
    char nomeFile[lnght];

    int numint;
    double numReale;
    double array[N];
    int countN = 0;

    double sommapositivi=0, sommanegativi=0;
    double valoresoglia;

    FILE *ptrRisultati;

    do
    {
        printf("Inserisci il nome del file: ");
        scanf("%s", nomeFile);
        ptrFile = fopen(nomeFile, "r");
        if (ptrFile == NULL)
        {
            printf("Errore: impossibile aprire il file\n");
        }
    } while (ptrFile == NULL);

    while ( fscanf(ptrFile, " %d %lf ", &numint, &numReale) != EOF )
    {
        if ( ( (numint%2) != 0) )
        {
            array[countN] = numReale;
            countN++;
        }
        if ( countN >= N)
        {
            countN--;
            break;
        }
    }
    fclose(ptrFile);
    ptrRisultati = fopen("10Risultati.txt", "w");

    printf("Inserisci il valore di soglia: ");
    scanf("%lf", &valoresoglia);

    for (int i = 0; i <= countN; i++)
    {
        if ( i%2 != 0 )
        {
            printf(" %lf", array[i]);
        }
        if ( array[i] > 0 )
        {
            sommapositivi = sommapositivi + array[i];
        }
        else{
            sommanegativi = sommanegativi + array[i];
        }

        if ( array[i] < valoresoglia )
        {
            fprintf(ptrRisultati, " %lf, ", array[i]);
        }
    }

    printf("\nSomma positivi: %lf\n", sommapositivi);
    printf("\nSomma negativi: %lf\n", sommanegativi);
    
}