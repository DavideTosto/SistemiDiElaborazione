/* 
Esercizio 2 
=========== 
 
Scrivere un programma in ANSI C che, dato un file di testo che contiene in ogni 
riga una coppia di numeri interi, esegua le seguenti operazioni: 
 
1. Carichi in un array i valori reali corrispondenti al rapporto fra i due  
   interi (se il secondo intero è non nullo) 
2. Stampi a video gli elementi dell'array maggiori di un valore fornito da  
   tastiera 
3. Sostituisca gli eventuali elementi dell'array pari ad 1 o -1 con il valore 0 
4. Salvi nel file "risultato.txt" gli elementi dell'array non nulli 
 
### Specifiche: 
 - La dimensione dell'array è N, con N pari a 10 - Il nome del file di ingresso deve essere inserito da input - Il numero di righe (cioè di coppie) nel file non è noto all'inizio 
 
Eventuali elementi nel file che soddisfano la condizione in "1." ma che non  
possono essere caricati nel vettore poichè pieno, non devono essere presi in  
considerazione.*/

#include <stdio.h>
#include <stdlib.h>

#define lnghtNome 256
#define N 10

void main()
{
   FILE *ptrFile;
   char nomeFile[lnghtNome];

   double a, b;
   double array[N];
   int countN = 0;

   double inval;

   FILE *ptrRisultati;

   do
   {
      printf("Inserisci il nome del file da aprire: ");
      scanf("%s", nomeFile);

      ptrFile = fopen(nomeFile, "r" );
      if ( ptrFile == NULL)
      {
         printf("\nErrore: impossibile aprire il file\n");
      }
   } while ( ptrFile == NULL);

   while (fscanf(ptrFile, "%lf %lf", &a,&b)!=EOF)
   {
      if ( b != 0)
      {
         array[countN] = (a/b);
         countN++;
      }
      if (countN >= N)
      {
         countN--;
         break;
      }
   }

   fclose(ptrFile);
   ptrRisultati = fopen("Risultati.txt", "w");
   printf("Inserisci un numero: ");
   scanf("%lf", &inval);

   for (int i = 0; i <= countN; i++)
   {
      if (array[i]>inval)
      {
         printf("%lf, ", array[i]);
      }
      if ((array[i]==1) ||(array[i]==-1))
      {
         array[i] = 0; 
      }
      fprintf(ptrRisultati, "%lf\n", array[i]);
   }
   
   
   
}