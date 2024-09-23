#include <stdio.h>

#define N 5 // Dimensione dell'array

// Funzione per trovare il secondo massimo tra tre valori
int second_max(int a, int b, int c) {
    if ((a >= b && a <= c) || (a >= c && a <= b)) return a;
    if ((b >= a && b <= c) || (b >= c && b <= a)) return b;
    return c;
}

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100];
    int array[N], count = 0, i1, i2, i3;
    int inputValue, lastInserted;

    // Chiede il nome del file da tastiera
    printf("Inserisci il nome del file di input: ");
    scanf("%s", inputFileName);

    // Apre il file di input
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Errore nell'apertura del file.\n");
        return 1;
    }

    // Passo 1: Caricamento dei dati nell'array
    while (fscanf(inputFile, "%d %d %d", &i1, &i2, &i3) == 3 && count < N) {
        int sum = i1 + i2 + i3;
        if (sum % 2 == 0) {
            array[count] = second_max(i1, i2, i3); // Secondo massimo
        } else {
            array[count] = sum; // Somma
        }
        lastInserted = array[count]; // Aggiorna l'ultimo valore inserito
        count++;
    }
    fclose(inputFile);

    // Passo 2: Stampa dei valori non compresi nell'intervallo
    printf("Inserisci un valore da tastiera: ");
    scanf("%d", &inputValue);
    printf("Valori stampati: \n");
    for (int i = 0; i < count; i++) {
        if (!(array[i] >= lastInserted && array[i] <= inputValue)) {
            printf("%d\n", array[i]);
        }
    }

    // Passo 3: Incremento dei valori nell'intervallo
    for (int i = 0; i < count; i++) {
        if (array[i] >= lastInserted && array[i] <= inputValue) {
            array[i] += 2;
        }
    }

    // Passo 4: Salvataggio nel file "risultato.txt"
    outputFile = fopen("risultato.txt", "w");
    if (outputFile == NULL) {
        printf("Errore nell'apertura del file di output.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        if (array[i] > 5) {
            fprintf(outputFile, "%d\n", array[i]);
        }
    }
    fclose(outputFile);

    return 0;
}
