/*
Si scriva un programma in linguaggio C per poter analizzare una sequenza di numeri.
Dati N numeri interi letti da tastiera si vogliono calcolare e stampare su schermo diversi
risultati:
• quanti sono i numeri positivi, nulli e negativi
• quanti sono i numeri pari e dispari
• se la sequenza dei numeri inseriti è crescente, decrescente oppure né crescente né
decrescente.
Suggerimento. Una sequenza è crescente se ogni numero è maggiore del precedente,
decrescente se ogni numero è minore del precedente, né crescente né decrescente in tutti
gli altri casi
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int *array = NULL;
    int numero =0;
    int contatore=0;
    char term_char, risposta;
    int positivi, negativi, pari, dispari;
    int flagMessaggio;

    do
    {
        contatore = 0;
        positivi = 0;
        negativi = 0;
        pari = 0;
        dispari = 0;
        flagMessaggio = 0;
        
        printf("Inserisci i numeri (inserisci 'q' per terminare):\n");
        while (1)
        {
            term_char = getchar(); // Legge il prossimo carattere
            if (term_char == 'q')
            {
                break; // Esce dal ciclo se il carattere è 'q'
            }
            ungetc(term_char, stdin); // Rimette il carattere nello stream di input
            scanf("%d", &numero);

            // Riallocazione della memoria per il nuovo numero
            array = (int *)realloc(array, (contatore + 1) * sizeof(int));
            array[contatore] = numero;
            contatore++;

            // Pulizia del buffer di input per evitare letture multiple
            while ((term_char = getchar()) != '\n' && term_char != EOF);
        }

        // Stampa dei numeri inseriti
        printf("Hai inserito i seguenti numeri:\n");
        for (int i = 0; i < contatore; i++)
        {
            printf("%d ", array[i]);
        }

        // Ciclo per interagire con gli elementi dell' array
        for (int i = 0; i < contatore; i++)
        {
            // conteggio positivi o negativi
            if (array[i] >= 0)
            {
                positivi++;
            }
            else
            {
                negativi++;
            }

            // conteggio pari o dispari
            if ((array[i] % 2) == 0)
            {
                pari++;
            }
            else
            {
                dispari++;
            }

            // ordine crescente o decrescente
            if (i == 0)
            {
                continue;
            }
            else if ((array[i - 1] > array[i]) && (i == 1))
            {
                flagMessaggio = 1;
            }
            else if ((array[i - 1] > array[i]) && (flagMessaggio == 1))
            {
                flagMessaggio = 1;
            }
            else if ((array[i - 1] < array[i]) && (i == 1))
            {
                flagMessaggio = 2;
            }
            else if ((array[i - 1] < array[i]) && (flagMessaggio == 2))
            {
                flagMessaggio = 2;
            }
            else
            {
                flagMessaggio = 0;
            }
        }

        printf("\nHai inserito in ordine ");
        if (flagMessaggio == 2)
            printf("crescente ");
        else if (flagMessaggio == 1)
            printf("decrescente ");
        else
            printf("casuale ");

        printf("%d numeri positivi e %d negativi di cui ", positivi, negativi);
        printf("%d di essi sono pari e %d dispari", pari, dispari);
        // Liberazione della memoria allocata
        free(array);

        do
        {
            printf("\nVuoi continuare? (y/n):\n ");
            scanf("%c", &risposta);
            // Pulizia del buffer di input per evitare letture multiple
            while ((term_char = getchar()) != '\n' && term_char != EOF);
        } while (risposta != 'n' && risposta != 'N' && risposta != 'y' && risposta != 'Y');

    } while(risposta == 'Y' || risposta == 'y');

    return 0;
}