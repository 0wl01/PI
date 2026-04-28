#include <stdio.h>
#include <stdlib.h>

/*
1. Defina uma funcao int contaVogais (char *s) que conta quantas vogais uma string tem.
*/

int contaVogais (char *s) {
    int i, vogais = 0;

    for (i = 0; s[i] != '\0'; i++) {
        // Verifica se o caractere atual é uma vogal
        if (s[i] == 'a' || s[i] == 'A' ||
            s[i] == 'e' || s[i] == 'E' ||
            s[i] == 'i' || s[i] == 'I' ||
            s[i] == 'o' || s[i] == 'O' ||
            s[i] == 'u' || s[i] == 'U') {
            
            vogais++;
        }
    }
    return vogais;
}
