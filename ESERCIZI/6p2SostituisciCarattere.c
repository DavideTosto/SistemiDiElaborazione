/*
 Scrivere un programma in linguaggio C che legga una frase introdotta da tastiera. La frase
 è terminata dall’introduzione del carattere di invio e contiene complessivamente al più 100
 caratteri. Il programma deve svolgere le seguenti operazioni:
 • visualizzare la frase inserita
 • costruire una nuova frase in cui tutte le occorrenze del carattere ’.’ sono sostituite
 con il carattere di ritorno di linea ’\n’. Il programma deve memorizzare la nuova
 frase in una opportuna variabile
 • visualizzare la nuova frase.
*/

#include <stdio.h>
#include <ctype.h>
#define MAXCHAR 101
#define LETTERAPHABET 26

int main (){
    char frase[MAXCHAR] = {0};          //inizializzate a 0 per evitare comportamenti indesiderati
    char fraseCopiata[MAXCHAR] = {0};   //inizializzati a 0 per evitare comportamenti indesiderati
    char c;
    int i = 0;

    printf("\nInserisci una frase\n");
    while ( (c = getchar()) != '\n' && i < 100)
    {
        frase[i] = c;
        fraseCopiata[i] = (c == '.') ? '\n' : c;
        // condition ? value_if_true : value_if_false;
        i++;
    }

    // terminare le stringhe con il carattere nullo
    frase[i] = '\0';
    fraseCopiata[i] = '\0';

    printf("\nLa frase inserita è: \"%s\"\n\n", frase);
    printf("\nLa frase copiata è: \"%s\"\n", fraseCopiata);
    
}