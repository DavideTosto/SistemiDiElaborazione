#include <stdio.h>
#define DIM 20

// Funzione per stampare il vettore
void stampaVettore(int arr[], int dim) {
    printf("[ ");
    for (int i = 0; i < dim; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// Funzione per ordinare in modo decrescente tramite selezione ricorsiva
void ordinaDecrescente(int arr[], int dim, int i) {
    if (i >= dim - 1) return;  // Caso base: fine del vettore
    int maxIndex = i;
    for (int j = i + 1; j < dim; j++) {
        if (arr[j] > arr[maxIndex]) {
            maxIndex = j;
        }
    }
    // Scambio
    if (maxIndex != i) {
        int temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
    
    // Stampa il vettore dopo ogni passo
    printf("Passo ordinamento %d: ", i + 1);
    stampaVettore(arr, dim);

    // Ricorsione per l'elemento successivo
    ordinaDecrescente(arr, dim, i + 1);
}

// Funzione per la ricerca di un valore nel vettore tramite ricorsione
int ricercaValore(int arr[], int dim, int val, int i) {
    if (i >= dim) return -1;  // Caso base: valore non trovato
    if (arr[i] == val) return i;  // Caso base: valore trovato
    return ricercaValore(arr, dim, val, i + 1);  // Ricorsione
}

int main() {
    int n, scelta, val;
    int arr[DIM];

    // Input della dimensione del vettore
    do {
        printf("Inserisci la dimensione del vettore (max %d): ", DIM);
        scanf("%d", &n);
    } while (n <= 0 || n > DIM);

    // Input degli elementi del vettore
    printf("Inserisci gli elementi del vettore:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Stampa iniziale del vettore
    printf("Vettore iniziale: ");
    stampaVettore(arr, n);

    // Scelta dell'operazione
    printf("Scegli l'operazione:\n");
    printf("1. Ordinamento decrescente\n");
    printf("2. Ricerca di un valore\n");
    scanf("%d", &scelta);

    if (scelta == 1) {
        // Ordinamento decrescente
        ordinaDecrescente(arr, n, 0);
        printf("Vettore ordinato: ");
        stampaVettore(arr, n);
    } else if (scelta == 2) {
        // Ricerca di un valore
        printf("Inserisci il valore da cercare: ");
        scanf("%d", &val);
        int risultato = ricercaValore(arr, n, val, 0);
        if (risultato == -1) {
            printf("Valore %d non trovato nel vettore.\n", val);
        } else {
            printf("Valore %d trovato all'indice %d.\n", val, risultato);
        }
    } else {
        printf("Scelta non valida.\n");
    }

    return 0;
}