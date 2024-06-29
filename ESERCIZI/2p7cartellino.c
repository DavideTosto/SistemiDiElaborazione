/* Scrivere un programma che richieda all’utente il prezzo di un oggetto, e la percentuale
 di sconto ad esso applicata, e che stampi a video il cartellino con il prezzo (originale e
 scontato).
 Esempio:
 Inserisci i dati:
 Prezzo: 25
 Sconto: 10
 Cartellino:
 Prezzo: 25.00 euro
 Sconto applicato 10%
 Prezzo finale: 22.50 euro */

#include <stdio.h>

void main()
{
    char risposta;
    float prezzo, sconto, prezzoFinale;
    do
    {
        printf("Inserisci i dati:\nPrezzo: ");
        scanf("%f", &prezzo);
        printf("Sconto: ");
        scanf("%f", &sconto);

        prezzoFinale = prezzo - (prezzo)*sconto / 100;

        printf("\n\n");
        printf(" Cartellino:\nPrezzo: %2.2f euro\nSconto applicato %2.2f%%\nPrezzo finale: %2.2f euro\n\n\n\n\n\n", prezzo, sconto, prezzoFinale);

        do
        {
            printf("Vuoi continuare? (y/n):\n ");
            scanf("%c", &risposta);
        } while (risposta != 'n' && risposta != 'N' && risposta != 'y' && risposta != 'Y');

    } while (risposta == 'Y' || risposta == 'y');
}