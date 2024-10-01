/* Scrivere un programma in ANSI C che, dato un file di testo che contiene in ogni riga una coppia di  
numeri interi, svolga i seguenti passi: 
1. carichi in un array il maggiore (max) tra i due valori di ogni riga se tale valore max è pari, 
altrimenti l’altro valore (qualunque esso sia). 
2. stampi a video gli elementi dell'array con valore compreso tra quello del primo elemento 
inserito nell’array ed un valore fornito da tastiera (inclusi); 
3. sostituisca gli elementi dell'array il cui valore è compreso nell’intervallo definito al punto 
precedente, con il valore 0; 
4. salvi nel file “risultato.txt” gli elementi dell'array. 
Specifiche: - - - 
la dimensione dell'array è N, con N pari a 10; 
il nome del file di ingresso deve essere fornito da tastiera; 
il numero di righe (cioè di coppie) nel file non è noto all'inizio. Eventuali elementi nel file che 
non possono essere caricati nel vettore poiché pieno, non devono essere presi in considerazione 
nelle operazioni del passo “1.” */ 

#include <stdlib.h>
#include <stdio.h>

#define lnghtNome 256  // Lunghezza massima per il nome del file
#define N 10           // Dimensione massima dell'array

// Funzione per trovare il massimo tra due numeri
int max(int a, int b);

void main()
{
    FILE *ptrFile;               // Puntatore al file di input
    char nomeFile[lnghtNome];     // Stringa per il nome del file

    int primoNum, secondoNum;     // Variabili per memorizzare i numeri letti dal file
    int array[N];                 // Array di dimensione N per memorizzare i valori elaborati
    int countN = 0;               // Contatore per gli elementi caricati nell'array
    int massimo;                  // Variabile per memorizzare il valore massimo tra i due numeri letti

    FILE *ptrRisultati;           // Puntatore al file di output per i risultati
    int numero, primoElemento;    // Variabili per il numero inserito da tastiera e il primo elemento dell'array

    // Richiesta del nome del file finché non si riesce ad aprirlo correttamente
    do
    {
        printf("Inserisci il nome del file: ");
        scanf("%s", nomeFile);                    // Acquisisce il nome del file da tastiera
        ptrFile = fopen(nomeFile, "r");           // Tenta di aprire il file in modalità lettura
        if (ptrFile == NULL)
        {
            printf("Errore: il file non può essere aperto\n"); // Messaggio di errore se il file non esiste
        }

    } while (ptrFile == NULL);  // Continua a chiedere il nome del file finché non viene aperto correttamente

    // Lettura del file riga per riga, estraendo le coppie di numeri interi
    while (fscanf(ptrFile, " %d %d", &primoNum, &secondoNum) != EOF)
    {
        massimo = max(primoNum, secondoNum); // Calcola il massimo tra i due numeri
        if ((massimo % 2) == 0)              // Se il massimo è pari, lo inserisce nell'array
        {
            array[countN] = massimo;
            countN++;
        }
        else                                // Se il massimo è dispari, inserisce l'altro numero
        {
            if (massimo == primoNum)
            {
                array[countN] = secondoNum;  // Inserisce il secondo numero se il primo è il massimo dispari
                countN++;
            }
            else
            {
                array[countN] = primoNum;    // Inserisce il primo numero se il secondo è il massimo dispari
                countN++;
            } 
        }

        if (countN >= N)                    // Se l'array è pieno, interrompe il caricamento
        {
            countN--;
            break;
        }
    }

    // Se non sono stati riempiti tutti gli elementi dell'array, decrementa il contatore
    if (countN < N-1)
    {
        countN--;
    }

    fclose(ptrFile);  // Chiude il file di input

    // Apre il file di output per salvare i risultati
    ptrRisultati = fopen("se-appello-2022-09-Risultati.txt", "w");

    // Richiede un numero da tastiera per definire l'intervallo
    printf("\nInserisci un numero da tastiera: ");
    scanf("%d", &numero);
    primoElemento = array[0];  // Memorizza il primo elemento dell'array

    // Cicla attraverso l'array per stampare e sostituire i valori compresi nell'intervallo
    for (int i = 0; i <= countN; i++)
    {
        // Se il valore dell'array è compreso tra il primo elemento e il numero fornito da tastiera
        if ((primoElemento <= array[i] && array[i] <= numero)  ||
             (numero <= array[i] && array[i] <= primoElemento))
        {
            printf(" %d,", array[i]);  // Stampa il valore
            array[i] = 0;              // Sostituisce il valore con 0
        }

        // Scrive il valore (sostituito o no) nel file di output
        fprintf(ptrRisultati, "%d\n", array[i]);
    }
    fclose(ptrRisultati);  // Chiude il file di output

    char ch = 'N';
    do
    {
        printf("\nPremi Y per uscire: ");
        scanf(" %c",&ch);
    } while (ch != 'Y');
    
}

// Funzione per calcolare il massimo tra due numeri
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
