
/* 1.	Calcolare massimo, minimo, ed il valor medio di cinque valori. Stampare il risultato a video.
Provare ad implementare le seguenti varianti:
a)	i valori sono inseriti nel codice programma
b)	i valori sono inseriti da tastiera
c)	i valori sono inseriti da tastiera in un array di 5 elementi
d)	i valori sono ricavati da un file di testo
I.	il cui nome è noto
II.	il cui nome è inserito dall’utente da tastiera.
e)	salvare il risultato in un file
I.	il cui nome è noto
II.	il cui nome è inserito dall’utente da tastiera.

2.	Calcolare il massimo solo se il primo dei valori è pari o maggiore di 10, altrimenti calcolare il prodotto tra il minimo ed il valor medio. Stampare il risultato a video.

3.	Implementare il calcolo del massimo, del minimo, e del valore medio in funzioni separate.

4.	Richiedere all’utente quanti valori utilizzare per il programma (non necessariamente 5 come al punto 1.)
*/

#include <stdio.h>
#include <limits.h>

double calcola_massimo(double valori[], int n)
{
    double max = valori[0];
    for (int i = 1; i < n; i++)
    {
        if (valori[i] > max)
        {
            max = valori[i];
        }
    }
    return max;
}

double calcola_minimo(double valori[], int n)
{
    double min = valori[0];
    for (int i = 1; i < n; i++)
    {
        if (valori[i] < min)
        {
            min = valori[i];
        }
    }
    return min;
}

double calcola_valor_medio(double valori[], int n)
{
    double somma = 0.0;
    for (int i = 0; i < n; i++)
    {
        somma += valori[i];
    }
    return somma / n;
}

void salva_risultati_in_file(const char *filename, double massimo, double minimo, double valor_medio)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Errore nell'apertura del file %s\n", filename);
        return;
    }
    fprintf(file, "Massimo: %.2f\n", massimo);
    fprintf(file, "Minimo: %.2f\n", minimo);
    fprintf(file, "Valor Medio: %.2f\n", valor_medio);
    fclose(file);
}

void leggi_valori_da_file(const char *filename, double valori[], int n)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Errore nell'apertura del file %s\n", filename);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%lf", &valori[i]);
    }
    fclose(file);
 
}

void inserimento_valori_da_tastiera(double valori[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Inserisci il valore %d: ", i + 1);
        scanf("%lf", &valori[i]);
    }
}

int main()
{
    int n = 5;
    double valori[n];
    inserimento_valori_da_tastiera(valori, n);

    double massimo = calcola_massimo(valori, n);
    double minimo = calcola_minimo(valori, n);
    double valor_medio = calcola_valor_medio(valori, n);

    const char *filename = "risultati.txt";
    salva_risultati_in_file(filename, massimo, minimo, valor_medio);
  


  //// seconda parte
    const char *filename2 = "dati.txt";
    leggi_valori_da_file(filename2, valori, n);

    massimo = calcola_massimo(valori, n);
    minimo = calcola_minimo(valori, n);
    valor_medio = calcola_valor_medio(valori, n);

    printf("Massimo: %.2f\n", massimo);
    printf("Minimo: %.2f\n", minimo);
    printf("Valor Medio: %.2f\n", valor_medio);

    return 0;
}