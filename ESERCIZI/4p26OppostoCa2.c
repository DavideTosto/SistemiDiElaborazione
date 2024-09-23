/*Scrivere un programma in linguaggio C che riceva in ingresso un numero binario
rappresentato in complemento a 2 su N bit. Inizialmente l’utente inserisce il numero N di bit.
Quindi inserisce le cifre del numero binario un bit alla volta, partendo dal bit meno significativo.
Il programma calcola l’opposto del numero binario ricevuto in ingresso. Tale
numero sarà visualizzato partendo dalla cifra meno significativa.
Suggerimento. Per poter effettuare il calcolo del risultato, utilizzare il metodo secondo il
quale si considerano le cifre del numero binario in complemento a due a partire dalla meno
significativa alla più significativa (ossia da destra verso sinistra). Si ricopiano in uscita
tutti gli zeri fino al primo 1 compreso. Dopo si invertono i restanti bit*/

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int *array = NULL;
    int numero, contatore;
    char term_char;

    contatore = 0;
    while (1)
    {
        printf("Inserire il %d° bit: ", (contatore + 1));
        term_char = getchar();
        if (term_char == 'e')
        {
            break;
        }
        ungetc(term_char, stdin); // Rimette il carattere nello stream di input
        do
        {
            scanf("%d", &numero);
            if (numero != 0 && numero != 1)
            {
                printf("...errato inserimento, digitare 1 o 0 \n");
                printf("Inserire il %d° bit: ", (contatore + 1));
            }
        } while (numero != 0 && numero != 1);

        int *temp = (int *)realloc(array, (contatore + 1) * sizeof(int));
        if (temp == NULL)
        {
            // Gestione dell'errore: ad esempio, liberare la memoria e uscire

            printf("Errore di allocazione della memoria.\n");
            exit(EXIT_FAILURE);
            continue;
        }
        array = temp;
        array[contatore] = numero;
        contatore++;

        // Pulizia del buffer di input per evitare letture multiple
        while ((term_char = getchar()) != '\n' && term_char != EOF)
            ;
    }

    
    if (contatore % 2 != 0) //se il numero di bit è dispari aggiungo un bit
    {
        int *temp = (int *)realloc(array, (contatore + 1) * sizeof(int));
        temp[contatore] = 0;
        contatore++;
    }

    // aggiungo 4 bit all'array
    int *temp = (int *)realloc(array, (contatore + 4) * sizeof(int));
    contatore = contatore + 4;

    if (temp == NULL)
    {
        // Gestione dell'errore: ad esempio, liberare la memoria e uscire
        printf("Errore di allocazione della memoria.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        for (int i = 0; i <= contatore; i++)
        {
            temp[i + 4] = array[i];
        }
        for (int i = 0; i < contatore - 4; i++)
        {
            temp[i] = 0;
        }
        array = temp;

    }

    // Stampa dei numeri inseriti
    printf("Hai inserito i seguenti numeri:\n");
    for (int i = 0; i < contatore; i++)
    {
        printf("%d ", array[i]);
    }

    // inverte tutti i bit
    for (int i = 0; i < contatore; i++)
    {
        array[i] = !array[i];
    }


    // +1 al primo bit
    int ii = contatore - 1;
    do
    {
        if (array[ii] == 1)
        {
            array[ii] = 0;
        }
        else
        {
            array[ii] = 1;
            break;
        }
        ii--;
    } while (array[ii] == 1);
    array[ii] = 1;

    // Stampa valori complemento a 2
    printf("\nComplemento a due:\n");
    for (int i = 0; i < contatore; i++)
    {
        printf("%d ", array[i]);
    }

    free(temp);
    free(array);

}