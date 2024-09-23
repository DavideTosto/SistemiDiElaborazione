#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Per la funzione isdigit() 

#define N 5
#define lngthNF 100
#define lnghtLn 1024

void main()
{
    // Dichiarazione variabili apertura file da leggere
    FILE *ptrFile;
    char nomeFile[lngthNF];

    // Dichiarazione variabili file da scrivere
    FILE *ptrRisultati;

    // Dich. variabili per operazioni
    int array[N];
    
    char ch;           
    int num = 0;
    int inNumber = 0;  // flag che indica se stiamo leggendo un numero
    int numeriTrovati; // numero di numeri trovati
    int countN = 0;    // countN tiene conto del numero degli elementi di array
    int a, b;          // coppia di numeri
    int valIn;

    do
    {
        // richiesta nome file da aprire
        printf("Inserisci il nome del file: ");
        scanf("%s", &nomeFile);
        // apertura file
        ptrFile = fopen(nomeFile, "r");
        if (ptrFile == NULL)
        {
            printf("Errore: non è stato possibile aprire il file");
        }
    } while (ptrFile == NULL);

    // caricamento dei valori presenti nel file all' array
    do
    {
        ch = fgetc(ptrFile);
        // controlla se il carattere è un numero
        if (isdigit(ch))
        {
            num = num * 10 + (ch - '0'); // costruisce il numero cifra per cifra
            inNumber = 1;                // Indica che stiamo leggendo un numero
        }
        else if (inNumber)              // Se troviamo un carattere non numerico dopo aver letto un numero
        {
            if (numeriTrovati == 0)     // e questo è il primo numero che troviamo
            {
                numeriTrovati = 1;      // imposta il questo stato in modo da rilevare il prossimo numero
                a = num;                // e salva il numero fin ora letto nella var. a
            }
            else if (numeriTrovati == 1) // se iterando si trova il secondo numero
            {
                b = num;                
                numeriTrovati = 2;      // si imposta un secondo stato per il codice relativo agli intervalli
            }
            num = 0;      // Resetta il numero per leggere il prossimo
            inNumber = 0; // Esce dalla modalità di lettura di un numero
        }

        if (ch == 10 && numeriTrovati == 1)  // se nella stessa riga non è presente un secondo numero si resettano gli stati
        {
            numeriTrovati = 0;
        }

        // caricamento dei valori presenti nel file all' array
        // se il primo numero rilevato è dispari e divisibili per tre
        // allora salva la var b nell' array.
        if ((numeriTrovati == 2) && ((a % 2 != 0) || (a % 3 == 0)))
        {
            numeriTrovati = 0;
            array[countN] = b;
            countN++;
            if (countN >= N)   // se è stato raggiunto il numero massimo degli elemnti richiesti nella traccia
            {
                countN--;
                break;         // termina le iterazioni
            }
        } // reset stati
        else if (numeriTrovati == 2)
        {
            numeriTrovati = 0;
        }
    } while (ch != EOF); // itera fino alla fine del file

    // chisura file in lettura e apertura/creazione file risultati
    fclose(ptrFile);
    ptrRisultati = fopen("se-appello-2023-09-13-Risultato2.txt", "w");

    // richiesta di un numero da tastiera
    printf("Inserisci un numero: ");
    scanf("%d", &valIn);

    // stampa dei valori dell array compresi tra il numero inserito da tastiera e il valore del primo elemanto dell' array
    //  valIn < x < array[0] || array[0] < x < valIn
    // se x[i] non fa parte dell' intervallo sostituisce il suo valore con 0
    for (int i = 0; i <= countN; i++)
    {
        if ((valIn <= array[i] && array[i] <= array[0]) ||
            (array[0] <= array[i] && array[i] <= valIn))
        {
            printf(" %d, ", array[i]);
        }
        else
        {
            // sostituz. elementi non compresi nell' intervallo
            array[i] = 0;
        }
        // salvataggio risultati
        fprintf(ptrRisultati, " %d\n", array[i]);
    }

    // chiusura file risultati
    fclose(ptrRisultati);
}