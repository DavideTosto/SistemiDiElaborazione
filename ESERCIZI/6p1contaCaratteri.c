/* Scrivere un programma in linguaggio C che legga una frase introdotta da tastiera. La
frase è terminata dall’introduzione del carattere di invio. La frase contiene sia caratteri
maiuscoli che caratteri minuscoli, e complessivamente al più 100 caratteri. Il programma
dovrà stampare su schermo le seguenti informazioni:
• per ognuna delle lettere dell’alfabeto, il numero di volte che la lettera compare nella
stringa
• il numero di consonanti presenti nella stringa
• il numero di vocali presenti nella stringa*/

#include <stdio.h>
#include <ctype.h>
#define MAXCHAR 101
#define LETTERALPHABET 26

int main()
{
    char frase[MAXCHAR];                // Array di caratteri per la frase, +1 per il carattere di terminazione '\0'
    int conteggio[LETTERALPHABET] = {0};        // Array per il conteggio delle lettere dell'alfabeto
    int vocali = 0, consonanti = 0;             // Contatori per vocali e consonanti
    char c;
    int i = 0;

    printf("Inserisci una frase (max 100 caratteri): ");
    while ((c = getchar()) != '\n' && i < 100)
    {   // Legge i caratteri fino all'invio o al limite di 100
        frase[i++] = c;
        if (isalpha(c))
        {                         // Controlla se il carattere è una lettera
            c = tolower(c);       // Converte il carattere in minuscolo
            conteggio[c - 'a']++; // Incrementa il conteggio per la lettera corrispondente
            // Controlla se è una vocale o una consonante
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                vocali++;
            }
            else
            {
                consonanti++;
            }
        }
    }
    frase[i] = '\0'; // Aggiunge il carattere di terminazione alla stringa

    // Stampa il conteggio per ogni lettera dell'alfabeto
    printf("\nFrequenza per ogni lettera dell'alfabeto:\n");
    for (i = 0; i < 26; i++)
    {
        if (conteggio[i] > 0)
        { // Stampa solo le lettere presenti nella frase
            printf("%c: %d\n", i + 'a', conteggio[i]);
        }
    }

    // Stampa il numero di vocali e consonanti
    printf("\nNumero di vocali: %d\n", vocali);
    printf("Numero di consonanti: %d\n", consonanti);

    return 0;
}
