/*Scrivere un programma in linguaggio C per la rappresentazione del triangolo di Floyd. Il
triangolo di Floyd è un triangolo rettangolo che contiene numeri naturali, definito riempiendo le righe del triangolo con numeri consecutivi e partendo da 1 nell’angolo in alto a
sinistra.
Si consideri ad esempio il caso N=5. Il triangolo di Floyd e’ il seguente:
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
Il programma riceve da tastiera un numero intero N. Il programma visualizza le prime
N righe del triangolo di Floyd.
Suggerimento. Si osserva che il numero di valori in ogni riga corrisponde all’indice della
riga: 1 valore sulla prima riga, 2 sulla seconda, 3 sulla terza
*/

#include <stdio.h>

void main()
{
    int N;
    int valore = 1, elementi = 1, numeroStampe;

    printf("Inserire il numero di righe da ottenere del triangolo di Floyd:\n N = ");
    scanf("%d", &N);

    for (N; N > 0; N--)
    {
        for (numeroStampe = elementi; numeroStampe > 0; numeroStampe--)
        {
            printf("%2d ", valore);
            valore++;
        }
        elementi++;
        printf("\n");
    }
}