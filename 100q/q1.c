#include <stdio.h>
#include <stdlib.h>

/*
1. Defina um programa que lˆe (usando a fun¸c˜ao scanf uma sequˆencia de n´umeros inteiros ter-
minada com o n´umero 0 e imprime no ecran o maior elemento da sequˆencia.
*/

int maiorNum() {
    int numero;
    int maior;

    printf("Introduza uma sequência de números a terminar em '0'\n");

    //Lê o primeiro numero
    scanf("%d" , &numero);

    //Se for igual a 0 a sequência está vazia
    if (numero == 0) {
        printf("A sequência está vazia\n");
        return 0;
    }
    
    maior = numero;

    //Caso contrário continuamos a ler até encontrarmos 0
    while (numero != 0) {
        if (numero > maior) {
            maior = numero;
        }
        scanf("%d", &numero);
    }
    printf("O maior elemento da sequência é: %d\n", maior);

    return 0;
}

/*
2. Defina um programa que lˆe (usando a fun¸c˜ao scanf uma sequˆencia de n´umeros inteiros ter-
minada com o n´umero 0 e imprime no ecran a m´edia da sequˆencia.
*/

int media() {
    int numero;
    int somatorio = 0;
    int elementos = 0;

    printf("Introduza uma sequência de números a terminar em '0'\n");

    scanf("%d" , &numero);

    //Lemos a sequência até atingir 0 e vamos incrementando os elementos e somando numero ao somatorio
    while (numero != 0) {
        somatorio += numero;
        elementos++;
        scanf("%d" , &numero); //lemos o próximo numero e atribuimos à var
    }

    //calculo e impressão da media

    if (elementos == 0) {
        printf("Nenhum número introduzido\n"); //não podemos dividir por 0 portanto precisamos de evitar o erro
    }
    else { 
        double resultado = (double)somatorio / elementos;
        printf("A média é %f\n" , resultado);
    }

    return 0;
}

/*
3. Defina um programa que lˆe (usando a fun¸c˜ao scanf uma sequˆencia 
de n´umeros inteiros terminada com o n´umero 0 e imprime no ecran o 
segundo maior elemento.
*/

int segMaior() {
    int numero, maior = -1, secmaior = -1;

    printf("Insira a sequência de números a terminar em '0':\n");
    //Lê o primeiro numero
    scanf("%d", &numero);
    maior = numero;

    if (numero == 0) {
        printf("Sequência vazia\n");
        return 0;
    }

    while (numero != 0) {
        scanf("%d", &numero);
        if (maior < numero) {
            secmaior = maior; //o antigo maior passa para baixo
            maior = numero; //o novo maior sobe ao torno
        }

        else if (numero > secmaior && numero != maior) {
            secmaior = numero;
        }
    }

    printf("O segundo maior número é: %d\n", secmaior);

    return 0;
}

/*
4. Defina uma fun¸c˜ao int bitsUm (unsigned int n) que calcula o 
n´umero de bits iguais a 1 usados na representa¸c˜ao bin´aria de 
um dado n´umero n
*/

int bitsUm (unsigned int n) {
    int contador = 0;

    while (n != 0) {
        if (n % 2 == 1 ) {
            contador++;
        }
    n /= 2;
    }
    return contador;

}

/*
5. Defina uma fun¸c˜ao int trailingZ (unsigned int n) que 
calcula o n´umero de bits a 0 no final da representa¸c˜ao 
bin´aria de um n´umero (i.e., o expoente da maior potˆencia 
de 2 que ´e divisor desse n´umero).
*/

int trailingZ (unsigned int n) {
    int i, contador = 0;

    for (i = n; i < n; i /= 2) {
        if (i % 2 == 0) contador++;
    }
    return contador;
}

/*
6. Defina uma funcao int qDig (unsigned int n) que calcula o numero de dıgitos necessarios
para escrever o inteiro n em base decimal. Por exemplo, qDig (440) deve retornar 3.
*/

int qDig (unsigned int n) {
    int digitos = 0;

    do {
        digitos++;
        n /= 10;
    } while (n > 0);

    return digitos;
}

/*
7. Apresente uma definicao da funcao pre-definida em C char *strcat (char s1[], char
s2[]) que concatena a string s2 a s1 (retornando o endereco da primeira).
*/

char *strcat (char s1[], char s2[]) {
    int i = 0, j = 0;
    //Avançamos até a posição de '\0' em s1
    while (s1[i] != '\0') i++;
    //Estando no final da primeira string começamos a avançar posições 
    while (s2[j] != '\0') {
        s1[i] = s2[j]; //copiando a sting2 à frente do fim da s1
        i++;
        j++;
    }

    //E fechamos a nova s1
    s1[i] = '\0';

    return s1;
}
/*
8. Apresente uma definicao da funcao pre-definida em C char *strcpy (char *dest, char
source[]) que copia a string source para dest retornando o valor desta  ́ultima.
*/

char *strcpy (char *dest, char source[]) {
    int i = 0;

    while (source[i] != '\0') {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';

    return dest;
}

/*
9. Apresente uma definicao da funcao pre-definida em C int strcmp (char s1[], char s2[])
que compara (lexicograficamente) duas strings. O resultado devera ser
•0 se as strings forem iguais
•<0 se s1 < s2
•>0 se s1 > s2
*/

int strcmp (char s1[], char s2[]) {
    int i = 0;


    while (s1[i] == s2[i] && s1[i] != '\0') i++;

    return s1[i] - s2[i];
}

/*
10. Apresente uma definicao da funcao pre-definida em C char *strstr (char s1[], char
s2[]) que determina a posicao onde a string s2 ocorre em s1. A funcao devera retornar
NULL caso s2 nao ocorra em s1.
*/

char *mystrstr(char s1[], char s2[]) {
    char *res = NULL;
    int i,p;
    
    if (s2[0] == '\0') return s1;
    
    for(i = 0; s1[i] != '\0' && res == NULL; i++) {
        for(p = 0; s2[p] != '\0' && s2[p] == s1[i+p];p++);
        if (s2[p] == '\0')
        res = s1 + i;
    }
    return res;
}

int main() {
    char s2[] = "ADORO \0";
    char s1[] = "CONA\0";
    
    // Chamamos a função (s1 será alterada diretamente)
    strcpy(s1, s2);

    // %s para imprimir a string completa
    printf("Resultado: %s\n", s1); 

    return 0;
}