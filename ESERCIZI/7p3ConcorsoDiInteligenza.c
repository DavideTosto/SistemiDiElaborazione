/*
7.3 Concorso di intelligenza
 In un concorso di intelligenza, N giudici esprimono il loro giudizio su K candidati. Il
 giudizio è un valore numerico tra 0 e 5.
 Si scriva un programma in linguaggio C per determinare il candidato più intelligente,
 ed il giudice più severo.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GIUDICI 3
#define CONCORRENTI 12 // Esempio con numero diverso di concorrenti
#define VALUTAZIONEMAX 5.0

// Prototipi delle funzioni
void stampaMatrice(int dimX, int dimY, float *ptrSchr);
int candidatoPiuIntelligente(int dimX, int dimY, float *ptrVal);
int posizioneMassimo(int dimensione, float *vettore);
int giudicePiuSevero(int dimX, int dimY, float *ptrVal);
int posizioneMinimo(int dimensione, float *vettore);

int main() {
    float valutazioni[GIUDICI][CONCORRENTI] = {0};
    int candidato, giudice;
    srand(time(NULL));

    // Inizializzazione valori random
    for (size_t i = 0; i < GIUDICI; i++) {
        for (size_t j = 0; j < CONCORRENTI; j++) {
            valutazioni[i][j] = (float)rand() / RAND_MAX * VALUTAZIONEMAX;
        }
    }

    // Stampa della matrice di valutazioni
    printf("Matrice delle valutazioni:\n");
    stampaMatrice(GIUDICI, CONCORRENTI, (float *)valutazioni);

    // Determina il candidato più intelligente
    candidato = candidatoPiuIntelligente(GIUDICI, CONCORRENTI, (float *)valutazioni);
    printf("\nIl candidato più intelligente è il numero %d\n", candidato + 1);

    // Determina il giudice più severo
    giudice = giudicePiuSevero(GIUDICI, CONCORRENTI, (float *)valutazioni);
    printf("Il giudice più severo è il numero %d\n", giudice + 1);

    return 0;
}

// Funzione per stampare la matrice
void stampaMatrice(int dimX, int dimY, float *ptrSchr) {
    for (unsigned int i = 0; i < dimX; i++) {
        for (unsigned int j = 0; j < dimY; j++) {
            printf(" %.2f ", *(ptrSchr + i * dimY + j));
        }
        printf("\n");
    }
}

// Funzione per determinare il candidato più intelligente
int candidatoPiuIntelligente(int dimX, int dimY, float *ptrVal) {
    float risultati[dimX];
    float somma = 0;
    int massimo;

    // Calcola la somma delle valutazioni per ciascun candidato
    for (unsigned int i = 0; i < dimX; i++) {
        for (unsigned int j = 0; j < dimY; j++) {
            somma += *(ptrVal + i * dimY + j);
        }
        risultati[i] = somma;
        somma = 0;
    }

    // Trova l'indice del candidato con la somma massima
    massimo = posizioneMassimo(dimX, (float *)risultati);

    return massimo;
}

// Funzione ausiliaria per trovare l'indice dell'elemento massimo in un vettore
int posizioneMassimo(int dimensione, float *vettore) {
    int max_index = 0;

    // Itera attraverso il vettore per trovare l'indice dell'elemento massimo
    for (unsigned int i = 1; i < dimensione; i++) {
        if (vettore[i] > vettore[max_index]) {
            max_index = i;
        }
    }

    // Restituisci l'indice dell'elemento massimo
    return max_index;
}

// Funzione per determinare il giudice più severo
int giudicePiuSevero(int dimX, int dimY, float *ptrVal) {
    float risultati[dimY];
    float somma = 0;
    int minimo;

    // Calcola la somma delle valutazioni per ciascun giudice
    for (unsigned int i = 0; i < dimY; i++) {
        for (unsigned int j = 0; j < dimX; j++) {
            somma += *(ptrVal + j * dimY + i);
        }
        risultati[i] = somma;
        somma = 0;
    }

    // Trova l'indice del giudice con la somma minima
    minimo = posizioneMinimo(dimY, (float *)risultati);

    return minimo;
}

// Funzione ausiliaria per trovare l'indice dell'elemento minimo in un vettore
int posizioneMinimo(int dimensione, float *vettore) {
    int min_index = 0;

    // Itera attraverso il vettore per trovare l'indice dell'elemento minimo
    for (unsigned int i = 1; i < dimensione; i++) {
        if (vettore[i] < vettore[min_index]) {
            min_index = i;
        }
    }

    // Restituisci l'indice dell'elemento minimo
    return min_index;
}
