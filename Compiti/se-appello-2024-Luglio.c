#include <stdio.h>
#include <stdlib.h>

#define length_MAX 1024

int max(int a, int b, int c);
int* aggiungiElemento(int* array, int* contatore, int elemento);

void main()
{
    FILE *prtFile;
    int *array;
    char nomeFile[100];
    char line[length_MAX];
    int a, b, c, somma, elemento;
    int contatore = 1;                              // tiene conto dell'aumento delle celle di memoria
    array = (int* )malloc(contatore * sizeof(int));      // dichiarazione array dinamico

    if (array == NULL)
    {
        printf("Errore nell' allocazione della memoria \n");
        free(array); // Libera la memoria precedentemente allocata
    }

    // Chiede il nome del file da tastiera
    printf("Scrivi il nome del file da caricare: ");
    scanf("%s", nomeFile);

    // Apre il file in modalità lettura
    prtFile = fopen(nomeFile, "r+");

    // Controlla se il file esiste
    if (prtFile == NULL)
    {
        printf("Errore: il file non può essere aperto.\n");
    }

    while (fscanf(prtFile, "%d %d %d", &a, &b, &c) != EOF )
    {
        int i = 0;
        somma = a + b + c;

        if (somma % 2 == 0)
        {
            elemento = max(a, b, c);
        }
        else
        {
            elemento = somma;
        }

        array = aggiungiElemento(array, &contatore, elemento);
    }

    
    // Stampa gli elementi nell'array (opzionale)
    printf("\nElementi nel file elaborati:\n");
    for (int i = 0; i < contatore -1; i++) // Nota: contatore è incrementato una volta in più, quindi stampiamo fino a contatore-1
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Valore compreso tra quello dell' ultimo elemento inserito e un valore fornito da tastiera\n");
    int valtast, temp = 0;
    printf("Inserisci un valore: ");
    scanf("%d", &valtast);
    while (  temp <= contatore-2)
    {
        
        if ( (valtast<= array[temp] && array[temp]<=array[contatore-2]) || ( array[contatore-2]<= array[temp] && array[temp]<=valtast) )
        {
            printf("%d\n", array[temp]);
        }
            temp++;
    }
    
    // tastiera< x < array !! array < x < tastiera

    printf("4° punto\n");

    temp=0;
    while (  temp <= contatore-2)
    {
        
        if ( (valtast<= array[temp] && array[temp]<=array[contatore-2]) || ( array[contatore-2]<= array[temp] && array[temp]<=valtast) )
        {
            array[temp] = array[temp]+3;
            printf("%d\n ", array[temp]);
        }
        else { printf("%d\n", array[temp]); }
        temp++;
    }

    fseek(prtFile, 0, SEEK_END);
    fprintf(prtFile, "\nNuova riga\n");
    temp=0;
    while (  temp <= contatore-2)
    {
        
        if ( (valtast<= array[temp] && array[temp]<=array[contatore-2]) || ( array[contatore-2]<= array[temp] && array[temp]<=valtast) )
        {
            fprintf(prtFile, "\n%d", array[temp]);
        }
        temp++;
    }
    
    

    // Chiude il file
    fclose(prtFile);
    // Libera la memoria
    free(array);
}

int max(int a, int b, int c)
{
    if (a >= b && a >= c)
    {
        return a;
    }
    else if (b >= a && b >= c)
    {
        return b;
    }
    else
    {
        return c;
    }
}

int *aggiungiElemento(int *array, int* contatore, int elemento)
{
    int *temp = (int *)realloc(array, (*contatore+1) * sizeof(int));
    printf("Contatore %d \n", *contatore );
    if (temp == NULL)
    {
        printf("Errore nel ridimensionamento della memoria!\n");
        free(array); // Libera la memoria precedentemente allocata
        return NULL; // Indica il fallimento
    }
    array = temp;  // Aggiorna l'array solo se realloc ha successo

    array[*contatore - 1] = elemento;
    (*contatore)++;  // Incrementa la dimensione dell'array

    return array;  // Restituisce il puntatore aggiornato all'array
}