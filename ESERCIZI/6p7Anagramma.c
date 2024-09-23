/*
 6.7 Anagramma
 Date due stringhe inserite da tastiera, dire se esse sono l’anagramma l’una dell’altra.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXCHAR 100
#define ALPHABET_SIZE 26

void count_characters(char *str, int *count) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            count[tolower(str[i]) - 'a']++;
        }
    }
}

int are_anagrams(char *str1, char *str2) {
    int count1[ALPHABET_SIZE] = {0};
    int count2[ALPHABET_SIZE] = {0};

    count_characters(str1, count1);
    count_characters(str2, count2);

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (count1[i] != count2[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char frase1[MAXCHAR] = {0};
    char frase2[MAXCHAR] = {0};
    char c;
    int i = 0;

    printf("Inserisci la prima frase:\n");
    while ((c = getchar()) != '\n' && i < MAXCHAR - 1) {
        frase1[i++] = c;
    }
    frase1[i] = '\0';

    printf("Inserisci la seconda frase:\n");
    i = 0;
    while ((c = getchar()) != '\n' && i < MAXCHAR - 1) {
        frase2[i++] = c;
    }
    frase2[i] = '\0';

    if (are_anagrams(frase1, frase2)) {
        printf("Le due frasi sono anagrammi.\n");
    } else {
        printf("Le due frasi non sono anagrammi.\n");
    }

    return 0;
}
