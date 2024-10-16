#include <stdio.h>
#include <stdlib.h>

#define N 5
#define Nome 256
#define tentativi 10

int min(int a, int b);
double getNum();

int main()
{

    FILE *ptrFile;
    char nomeFile[Nome];
    int primoVal, secondoVal;

    int array[N];
    int countN = 0;

    FILE* ptrRisultati;
    int primoElemento;
    double valoreInserito;

    int e = 0;
    do
    {
        printf("Inserisci il nome del file: ");
        scanf("%s", nomeFile);

        ptrFile = fopen(nomeFile, "r");

        if (ptrFile == NULL)
        {
            printf("Errore: Impossibile aprire il file.");
            if (e > tentativi)
                return -1;
        }
    } while (ptrFile == NULL);

    while (fscanf(ptrFile, "%d %d", &primoVal, &secondoVal) != EOF)
    {
        int minimo = min(primoVal, secondoVal);

        if (minimo % 2 == 0)
            array[countN] = minimo;
        else
        {
            if (primoVal == minimo)
                array[countN] = secondoVal * 2;
            else
                array[countN] = primoVal * 2;
        }

        countN++;

        if (countN >= N)
            break;
        
    }

    fclose(ptrFile);
    ptrRisultati = fopen("se-appello-2023-10-Risultati_v2.txt", "w");

    valoreInserito = getNum();
    primoElemento = array[0];

    for (int i = 0, ii=1; i <= countN; i++)
    {
        if ( (primoElemento<=array[i] && array[i]<=valoreInserito) ||
             (valoreInserito<=array[i] && array[i]<=primoElemento) )
        {
            printf("%d^ valore: %d;\n", ii, array[i]);
            ii++;
        }
        else
            array[i] = 0;
        
        fprintf(ptrRisultati, "Array[%d] = %d;\n", i, array[i]);
        
    }
    
    fclose(ptrRisultati);
    return 0;

}

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
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

    printf("\n");

    return valore; // Restituisce il numero valido inserito dall'utente
}
