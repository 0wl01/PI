#include <stdio.h>
#include <stdlib.h>

/*
1. Diga, justificando, qual o output de cada um dos seguintes excertos de c´odigo C.
*/

/*
(a)
int main () {

int x [15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

int *y, *z, i;
y = x; primeira posição no array?
z = x+3; quarta posição no array?

for (i=0; i<5; i++) {
    printf ("%d %d %d\n",
    x[i], *y, *z);
    y = y+1; z = z+2;
}

Output: 
1 1 4
2 2 6
3 3 8
4 4 10
5 5 12
*/

/*
(b)
int main () {
    int i, j, *a, *b;

    i=3; j=5;
    a = b = 42; // MÁ PRÁTICA a e b guardam endereço 42
    a = &i; b = &j; // a aponta para i = 3 e b aponta para j = 5
    i++; //i é incrementado logo i = 4 e por consequência a = 4
    j = i + *b; // j = 4 + 5 = 9  
    b = a; // b tem o mesmo endereço que a agora, a = b = i
    j = j + *b; // j = 9 + 4 = 13

    printf ("%d\n", j);
    
    return 0;
}

Output: 13
 */

 /*
 2. Defina uma funcao void swapM (int *x, int *y) que
troca o valor de duas variaveis. Por exemplo, o codigo ao
lado devera imprimir no ecran 5 3.

int x = 3, y = 5;
swapM (&x, &y);
printf ("%d %d\n", x, y);
 */

 void swapM(int *x, int *y) {
    int temp = *x;

    *x = *y;
    *y = temp;
 }

 /*
 3. Defina uma fun ̧c ̃ao void swap (int v[], int i, int j) que troca o valor das posi ̧c ̃oes i e
j do vector v.
 */

 int main() {
    int x = 3, y = 5;
    swapM(&x, &y);
    printf("%d %d\n", x, y);

    return 0;
 }