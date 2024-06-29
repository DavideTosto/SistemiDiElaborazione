/*4.11 Conversione Binario-Decimale

Si scriva un programma in linguaggio C che converta un numero binario in un numero
decimale. Il numero binario è rappresentato su N bit, e il valore di N è inserito da tastiera.
L’utente inserisce le cifre del numero binario un bit alla volta, partendo dal bit
meno significativo (ossia dal bit di peso 20). Il programma visualizzerà il numero decimale corrispondente.
Suggerimento. Per calcolare le potenze di 2 utilizzare la funzione pow, includendo la libreria
math.h. Ad esempio per calcolare 2
5, si scriverà pow(2,5). In generale, data una base a, per
calcolare y = ab, si scrive y = pow(a,b) includendo la libreria math.h.*/

#include <stdio.h>
#include <math.h>

void main()
{
    int numBin, copiaNumBin;
    int potenzaMassima;
    int bit, conversione;
    char risposta;

    do
    {   
        numBin = 0, copiaNumBin = 0, potenzaMassima = 0, bit = 0, conversione = 0;

        printf("Inserisci un numero binario: ");
        scanf("%d", &numBin);

        copiaNumBin = numBin;
        while (copiaNumBin > 0)
        {
            copiaNumBin = copiaNumBin / 10;
            potenzaMassima++;

        } // conta il numero di cifre decimali
        potenzaMassima--;

        copiaNumBin = numBin;
        while (potenzaMassima >= 0)
        {
            bit = copiaNumBin / pow(10, potenzaMassima);
            conversione = conversione + bit * pow(2, potenzaMassima);

            copiaNumBin = (copiaNumBin - bit * pow(10, potenzaMassima));
            potenzaMassima--;
        }

        printf("Conversione = %d\n\n\n", conversione);
        
        do
        {
            printf("Vuoi continuare? (y/n):\n ");
            scanf("%c", &risposta);
        } while (risposta != 'n' && risposta != 'N' && risposta != 'y' && risposta != 'Y');

    } while (risposta == 'Y' || risposta == 'y');
}