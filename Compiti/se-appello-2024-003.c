#include <stdlib.h>
#include <stdio.h>

#define NOME 256
#define N 6
#define TENTATIVI 10

int max(int a, int b, int c);
double getNum();
void ordina(int* Vett);

int main()
{
    FILE *ptrFile;
    char nomeFile[NOME];

    int primoVal, secondoVal, terzoVal;
    int array[N];
    int countN = 0;

    FILE * ptrRisultati;
    double numero;
    double elementi[2];

    int err = 0;
    do
    {
        printf("Inserisci il nome del file: ");
        scanf("%s", nomeFile);

        ptrFile = fopen(nomeFile, "r");
        if (ptrFile == NULL)
        {
            printf("Errore: impossibile aprire il file");
            err++;
            if (err > TENTATIVI)
                return -1;
        }
    } while (ptrFile == NULL);

    while (fscanf(ptrFile, "%d %d %d", &primoVal, &secondoVal, &terzoVal) != EOF)
    {
        int somma = primoVal + secondoVal + terzoVal;

        if ((somma % 3) == 0)
        {
            array[countN] = max(primoVal, secondoVal, terzoVal);
            countN++;
        }
        else if ((somma % 2) != 0)
        {
            array[countN] = primoVal * secondoVal * terzoVal;
            countN++;
        }
        else
        {
            float numero = (float)somma/3 - (int)somma/3 ;

            if ( numero > 0)
                array[countN] = (int)somma/3 + 1;
            else
                array[countN] = (int)somma / 3;
            countN++;
        }

        

        if (countN >= N)
            break;      
    }

    fclose(ptrFile);
    ptrRisultati = fopen("se-appello-2024-003-Risultati.txt", "w");

    numero = getNum();
    elementi[0] = array[0];
    elementi[1] = array[countN-1];



    for (int i = 0, ii=1, iii=1; i < countN; i++)
    {
        if ( (array[i]%((int)numero) != 0) )
        {
            printf("%d^ valore: %d;\n", ii, array[i]);
            ii++;
        }
        if ( !(elementi[0]<=array[i] && array[i]<=elementi[1]) )
            array[i] = array[i]*2;
        
        if ( array[i] > 10 )
        {
           fprintf(ptrRisultati,"%d^ valore: %d;\n", iii, array[i]);
           iii++;
        }
    }
    
    fclose(ptrRisultati);
    return 0;

}

int max(int a, int b, int c)
{
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}


// Funzione che legge un numero dall'utente, assicurandosi che sia valido
double getNum()
{
    double valore; // Variabile per memorizzare il numero inserito dall'utente
    int check;     // Variabile di controllo per verificare la validità dell'input
    char ch;       // Variabile per memorizzare i caratteri extra nel buffer di input

    // Chiede all'utente di inserire un numero
    printf("Inserisci un numero: ");

    // Ciclo per garantire che l'input sia un numero valido
    do
    {
        check = scanf("%lf", &valore); // Legge il numero e salva lo stato in 'check'
        ch = getchar();                // Legge il carattere successivo nel buffer
        if (check != 1 || ch != '\n')  // Controlla se l'input non è un numero o se ci sono altri caratteri
        {
            printf("Errore: Inserisci un numero -> ");
            while (getchar() != '\n'); // Consuma i caratteri rimanenti nel buffer di input 
        }
    } while (check != 1 || ch != '\n'); // Ripete finché l'input non è un numero valido

    printf("\n"); // Stampa una nuova riga

    return valore; // Restituisce il numero valido inserito dall'utente
}

void ordina(int* Vett)
{
    int temp; // Variabile temporanea per lo scambio
    if ( Vett[0] > Vett[1] ) // Se il primo valore è maggiore del secondo
    {
        temp = Vett[0];     // Salva il primo valore in temp
        Vett[0] = Vett[1];  // Assegna il secondo valore al primo
        Vett[1] = temp;     // Assegna il valore di temp al secondo
    }
}