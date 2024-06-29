/* Su una scacchiera 8x8 sono posizionati due pezzi: il Re bianco e la Regina nera.
 Si scriva un programma in linguaggio C che, acquisite le posizioni del Re e della Regina,
 determini se la Regina èinposizione tale da poter mangiare il Re. Leposizioni dei due pezzi
 sono identificate da mediante la riga e la colonna su cui si trovano, espresse come numeri
 interi tra 1 e 8. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 9
#define MIN 9

void stampaScacchiera(int *prtSchr, int *endSchr);
int *findQK(int *prtSchr, int *endSchr);

void main()
{
   int scacchiera[MAX][MIN] = {{0, 1, 2, 3, 4, 5, 6, 7, 8}, {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}};
   int *ptrK, *ptrQ;
   int xK, yK, xQ, yQ; // coordinate re "K" e regina "Q"
   int flagMessaggio;
   char risposta;

   do
   {

      printf("Stampa scacchiera:\n");
      stampaScacchiera(*(scacchiera), (&scacchiera[MAX - 1][MIN - 1] + 1));

      printf("Inserisci posizione Re:\nRiga = ");
      scanf("%d", &xK);
      printf("Colonna = ");
      scanf("%d", &yK);
      printf("Inserisci posizione Regina:\nRiga = ");
      scanf("%d", &xQ);
      printf("Colonna = ");
      scanf("%d", &yQ);

      scacchiera[xK][yK] = 9;
      scacchiera[xQ][yQ] = 8;

      // Controlla lo scacco sulle righe
      for (int i = 1; i < MAX; i++)
      {

         if (scacchiera[xQ][i] == 9)
            flagMessaggio = 1;
         scacchiera[xQ][i] = 1;
      }
      // controlla lo scacco sulle colonne
      for (int i = 1; i < MAX; i++)
      {
         if (scacchiera[i][yQ] == 9)
            flagMessaggio = 1;
         scacchiera[i][yQ] = 1;
      }

      int i, ii;
      // controlla lo scacco nel quarto e primo quadrante
      ii = yQ;
      for (i = xQ; i <= (MAX - 1) && ii <= (MAX - 1); i++)
      {
         if (scacchiera[i][ii] == 9)
         {
            flagMessaggio = 1;
         }
         scacchiera[i][ii] = 1;
         ii++;
      }
      // controlla lo scacco nel terzo quadrante
      ii = yQ;
      for (i = xQ; i <= (MAX - 1) && ii >= 0; i++)
      {
         if (scacchiera[i][ii] == 9)
         {
            flagMessaggio = 1;
         }
         scacchiera[i][ii] = 1;
         ii--;
      }
      // controlla scacco primo quadrante
      ii = yQ;
      for (i = xQ; i > 0 && ii <= (MAX - 1); i--)
      {
         if (scacchiera[i][ii] == 9)
         {
            flagMessaggio = 1;
         }
         scacchiera[i][ii] = 1;
         ii++;
      }
      // controlla scacco nel secondo quadrante
      ii = yQ;
      for (i = xQ; i > 0 && ii >= 0; i--)
      {
         if (scacchiera[i][ii] == 9)
         {
            flagMessaggio = 1;
         }
         scacchiera[i][ii] = 1;
         ii--;
      }

      if (flagMessaggio == 1)
      {
         printf("\nScacco matto!\n");
         flagMessaggio = 0;
      }

      scacchiera[xK][yK] = 9;
      scacchiera[xQ][yQ] = 8;
      printf("\n\n ");

      stampaScacchiera(*(scacchiera), (&scacchiera[MAX - 1][MIN - 1] + 1));

      printf("\n\n\n ");
      do
      {
         printf("Vuoi continuare? (y/n):\n ");
         scanf("%c", &risposta);
      } while (risposta != 'n' && risposta != 'N' && risposta != 'y' && risposta != 'Y');

   } while (risposta == 'Y' || risposta == 'y');
}

void stampaScacchiera(int *ptrSchr, int *endSchr)
{
   int ii = 0;
   /* (&scacchiera[MAX-1][MIN-1]+1) ultima posizione in memoria della matrice */
   for (ptrSchr; ptrSchr < endSchr; ptrSchr++)
   {
      ii++;
      printf(" %d ", *ptrSchr);
      if (ii >= 9) // per disegnare la scacchiera va a capo ogni 8 celle di memoria
      {
         printf("\n");
         ii = 0;
      }
   }
}

// ritorna la posizione in memoria della regina
// INUTILE PERCHE' GIA HO LA POSIZIONE
int *findQK(int *prtSchr, int *endSchr)
{
   int ii = 0, i = 0;

   /* (&scacchiera[MAX-1][MIN-1]+1) ultima posizione in memoria della matrice */
   for (prtSchr; prtSchr < endSchr; ++i, ++ii, prtSchr++)
   {
      if (*prtSchr == 2)
      {
         break; // regina trovata
      }
      if (ii >= 9) // per disegnare la scacchiera va a capo ogni 8 celle di memoria
      {
         ii = 0;
      }
   }

   int *array = malloc(2 * sizeof(int));
   array[0] = i;
   array[1] = ii;

   return array;
}

/*
 (&scacchiera[MAX-1][MIN-1]+1) ultima posizione in memoria della matrice
   for (i = *(scacchiera); i < (&scacchiera[MAX-1][MIN-1]+1); i++)
   {
      ii++;
      printf(" %d ", *i);
      if (ii >= 8) // per disegnare la scacchiera va a capo ogni 8 celle di memoria
      {
         printf("\n");
         ii = 0;
      }
   }
*/