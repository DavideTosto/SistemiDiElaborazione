#include <stdio.h>
#define MAX_line_size 1024

int main()
{

    FILE *ptrFile;
    char nomeFile[100];
    char line[MAX_line_size];

    // Chiede il nome del file da tastiera
    printf("Inserisci il nome del file: ");
    scanf("%s", nomeFile);

    // Apre il file in modalità lettura
    ptrFile = fopen(nomeFile, "r");

    // Controlla se il file esiste
    if (ptrFile == NULL)
    {
        printf("Errore: il file non può essere aperto.\n");
        return 1;
    }

    // Legge e stampa ogni riga del file
    printf("Contenuto del file:\n");
    while (fgets(line, sizeof(line), ptrFile))
    {
        printf("%s", line);
    }

    printf("\n\n");
    rewind(ptrFile);

    int carattere;

    // Legge i caratteri dal file
    while ((carattere = fgetc(ptrFile)) != EOF)
    {
        if (carattere == 10)
        {
            printf("\n"); // Se trovi una nuova linea, la stampi
            break;        // Uscita dal ciclo dopo la nuova linea
        }
        else
        {
            printf("%c", carattere); // Stampa il carattere normale
        }
    }

    printf("\n\n");
    rewind(ptrFile);  // riporta il puntatore all' origine del file

    int a, b, c; //numeri interi sulla linea
    while ( fscanf(ptrFile,"%d %d %d", &a, &b, &c ) != EOF )
    {
        printf("%d %d %d\n", a, b, c);
    }

    // Chiude il file
    fclose(ptrFile);

    return 0;
}
