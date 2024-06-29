/* Su una scacchiera 8x8 sono posizionati due pezzi: il Re bianco e la Regina nera.
 Si scriva un programma in linguaggio C che, acquisite le posizioni del Re e della Regina,
 determini se la Regina èinposizione tale da poter mangiare il Re. Leposizioni dei due pezzi
 sono identificate da mediante la riga e la colonna su cui si trovano, espresse come numeri
 interi tra 1 e 8. */

#include <stdio.h>

int creaScacchiera(int dimX, int dimY);
//int stampaScacchiera(int dimx, int dimy, int *pReG);
void stampaScacchiera(int dimX, int dimY, int *ptrSchr);

void main()
{
    char risposta;
    int posReali[] = {0, 0, 0, 0};
    int ptrSch;

    do
    {
        ptrSch = creaScacchiera(8,8);
        stampaScacchiera(8,8, ptrSch);
        //stampaScacchiera(8, 8, posReali);

        printf("\n\nDove vuoi posizionare il Re? es: 1 1 \n");
        scanf("%d %d", &posReali[0], &posReali[1]); // posizione Re

        printf("Dove vuoi posizionare la Regina? es: 5 8 \n");
        scanf("%d %d", &posReali[2], &posReali[3]); // Posizione Regina

        //stampaScacchiera(8, 8, posReali);

        do
        {
            printf("\nVuoi continuare? (y/n): ");
            scanf("%c", &risposta);
            while (getchar() != '\n')
                ; // Consuma tutti i caratteri fino a '\n'
        } while (risposta != 'n' && risposta != 'N' && risposta != 'y' && risposta != 'Y');

    } while (risposta == 'Y' || risposta == 'y');
}
 

/*  int stampaScacchiera(int dimx, int dimy, int *pReG)
{
    int flagRe = 0, flagregina = 0, flagStampa = 1;
    printf(" Stampo la posizione Re e Regina: \n\n");
    printf("Re %d %d = %d %d ; \n\n Regina %d %d = %d %d \n\n", pReG, pReG + 1, *(pReG), *(pReG + 1), pReG + 2, pReG + 3, *(pReG + 2), *(pReG + 3));

    printf(" Stampo la scacchiera: \n\n");
    printf(" X ");
    for (int i = 0; i < dimx; i++)
    {
        printf(" %d ", i);
    }
    for (int i = 0; i < dimy; i++)
    {
        if (i == *(pReG + 1))
            flagRe = 1;
        else
            flagRe = 0;

        if (i == *(pReG + 3))
            flagregina = 1;
        else
            flagregina = 0;

        printf("\n %d ", i);
        for (int ii = 0; ii < dimx; ii++)
        {
            if (flagRe == 1 && ii == *(pReG))
            {
                printf(" K ");
                flagRe = 0;
                flagStampa = 0;
            }
            else if (flagregina == 1 && ii == *(pReG + 2)  )
            {
                printf(" Q ");
                flagregina = 0;
                flagStampa = 0;
            }
            else if (flagStampa != 0)
             { printf(" 0 "); }
             else
            {
                printf(" 0 ");
                flagStampa = 0;
            }
        }
    }
    return 0;
}*/

void stampaScacchiera(int dimX, int dimY, int *ptrSchr){

    for (unsigned int i = 0; i < dimX+dimY; i++)
    {
        printf(" %d ", *(ptrSchr) );
        *ptrSchr++;
    }
}


int creaScacchiera(int dimX, int dimY){
    int scacchiera[dimX][dimY];
    int prtSch;
    for (unsigned int i = 0; i < dimX; i++)
    {
        for (unsigned int ii = 0; ii < dimY; i++)
        {
            scacchiera[dimX][dimY] = 0;
        } 
        prtSch = scacchiera;
        return prtSch;
    }
    
}