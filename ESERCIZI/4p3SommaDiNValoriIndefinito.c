/* Si scriva un programma in linguaggio C per calcolare la somma di un insieme di numeri
inseriti da tastiera. Il programma deve:
• leggere una sequenza di numeri
• fermarsi non appena viene inserito il numero 0
• visualizzare il valore corrispondente alla somma dei valori introdotti. */

#include <stdio.h>
#include <stdlib.h>

int getNum();

void main()
{
    int num;
    int somma = 0;

    printf("Inserisci un numero diverso da 0: ");
    scanf("%d", &num);
    while (num != 0)
    {
        somma = somma + num;
        if (num != 0)
        {
            printf("Somma parziale: %d\n", somma);
        }
        printf("Inserisci un altro numero diverso da 0: ");
        scanf("%d", &num);
        
    }
    printf("La somma dei numeri: %d\n", somma);

    /*
    int *ptrNum;
    int Somma = 0;

    ptrNum = getNum();

    while (*(ptrNum) = !0)
    {
        Somma = Somma + *(ptrNum);
        ptrNum++;
    }*/
}

/*
int getnum(){

    int* ptrNum;



    do{


    } while((*(ptrNum) = !0));

    return ptrNum;
} */