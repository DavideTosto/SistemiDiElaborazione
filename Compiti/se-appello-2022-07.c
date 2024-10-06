#include <stdlib.h>
#include <stdio.h>

#define N 10
#define lnghtNome 256

int max(int a, int b);

void main ()
{
    FILE* ptrFile;
    char nomeFile[lnghtNome];

    int primoNum, secondoNum;
    int array[N];
    int countN = 0;

    FILE* ptrRisultati;
    int ultimoElemento;
    double numero;
    
    do
    {
        printf("Inserisci il nome del file: ");
        scanf("%s", nomeFile);
        ptrFile = fopen(nomeFile, "r");
        if ( ptrFile == NULL)
        {
            printf("Errore: impossibile leggere il file");
        }
    } while (ptrFile == NULL);

    while ( fscanf(ptrFile, " %d %d", &primoNum, &secondoNum ) != EOF )
    {
        if ( (countN%2) == 0 )
            array[countN] = max(primoNum, secondoNum);
        else
        {
            if (max(primoNum, secondoNum) == primoNum)
                array[countN] = secondoNum;
            else
                array[countN] = primoNum;
        }

        countN++; //!!

        if (countN >= N)   
         break;
    }

    countN--;
    

    fclose(ptrFile);
    ptrRisultati = fopen("se-appello-2022-07-Risultati.txt", "w");

    printf("Inserisci un numero: ");
    scanf("%lf", &numero);
    ultimoElemento = array[countN]; //!!
    
    
    for (int i = 0; i <= countN; i++)
    {
        // ultimoElemento < x < numero
        if ( (ultimoElemento<=array[i] && array[i]<=numero) ||
             (numero<=array[i] && array[i]<=ultimoElemento) )
        {
            printf(" %d,", array[i]);
        }
        else
        {
            array[i] = 0;
        }
        
        fprintf(ptrRisultati, "%d\n", array[i]);
    }
    
    
}

int max(int a, int b)
{
    if ( a > b )
        return a;
    else
        return b;
}