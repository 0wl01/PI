#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1. Apresente uma defini ̧c ̃ao n ̃ao recursiva da fun ̧c ̃ao int length (LInt) que calcula o compri-
mento de uma lista ligada.
*/

typedef struct lligada {
            int valor;
        struct lligada *prox;
} *LInt;

int length (LInt l) {
    int len = 0;
    LInt atual = l;

    while (atual != NULL) {
        len++;
        atual = atual->prox;
    }
    return len;
}

/*
2. Apresente uma defini ̧c ̃ao n ̃ao recursiva da fun ̧c ̃ao void freeL (LInt) que liberta o espa ̧co
ocupado por uma lista.
*/

void freeL (LInt l) {
    LInt atual = l;
    LInt next;
    while (atual != NULL) {
        // Save next link
        next = atual->prox; 
        // Delete data
        free(atual);
        // Check next link, repeat
        atual = next;
    }
}

/*
3. Apresente uma defini ̧c ̃ao n ̃ao recursiva da fun ̧c ̃ao void imprimeL (LInt) que imprime no
ecran os elementos de uma lista (um por linha).
*/

void imprimeL (LInt l) {
    LInt atual = l;

    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->prox;
    }
}

/*
4. Apresente uma defini ̧c ̃ao n ̃ao recursiva da fun ̧c ̃ao LInt reverseL (LInt) que inverte uma
lista (sem criar uma nova lista).
*/

LInt reverseL (LInt l) {
    LInt atual = l;
    LInt prev = NULL;
    LInt next = NULL;

    while (atual != NULL) {
        next = atual->prox; // Save the next pointer
        atual->prox = prev; // Reverse the direction of current pointer
        prev = atual; // Former is now the current node
        atual = next; // We skip to the next node
    }
    return prev;
}

/*
5. Apresente uma defini ̧c ̃ao n ̃ao recursiva da fun ̧c ̃ao void insertOrd (LInt *, int) que insere
ordenadamente um elemento numa lista ordenada.
*/

void insertOrd (LInt *l, int x) {
    LInt atual = *l;
    LInt prev = NULL;

    while (atual != NULL && atual->valor < x) {
        prev = atual;
        atual = atual->prox;
    }

    LInt novo = malloc(sizeof(struct lligada));
    novo->valor = x;
    novo->prox = atual;

    if (prev == NULL) {
        *l = novo; // Se não havia anterior, o novo é o primeiro
    } else {
        // Onde é que o prev deve apontar agora para incluir o novo nó?
        prev->prox = novo; 
    }
}

/*
6. Apresente uma defini ̧c ̃ao n ̃ao recursiva da fun ̧c ̃ao int removeOneOrd (LInt *, int) que
remove um elemento de uma lista ordenada. Retorna 1 caso o elemento a remover n ̃ao exista,
0 no outro caso.
*/

int removeOneOrd (LInt *l, int x) {
    LInt atual = *l;
    LInt prev = NULL;

    while (atual != NULL && atual->valor != x) {
        prev = atual;
        atual = atual->prox;
    }

    if (atual == NULL) return 1;

    if (prev == NULL) {
        *l = atual->prox;
        free(atual);
        return 0;
    } else {
        prev->prox=atual->prox;
        free(atual);
        return 0;
    }
}

/*
7. Defina uma fun ̧c ̃ao void merge (LInt *r, LInt a, LInt b) que junta duas listas orde-
nadas (a e b) numa  ́unica lista ordenada (*r).
*/

void merge (LInt *r, LInt a, LInt b) {
    if (a == NULL) {
        *r = b;
        return;
    }
    if (b == NULL) {
        *r = a;
        return;
    }

    if (a->valor < b->valor) {
        *r = a;
        a = a->prox; // Avançamos na lista a
    } else {
        *r = b;
        b = b->prox; // Avançamos na lista b
    }

    LInt atual = *r;

    while (a != NULL && b != NULL) {
        if (a->valor < b->valor) {
            atual->prox = a;
            a = a->prox;
        } else {
            atual->prox = b;
            b = b->prox;
        }
        // Como fazemos o 'atual' passar a ser o nó que acabámos de ligar?
        atual = atual->prox; 
    }

    if (a == NULL) {
        atual->prox = b;
    } else {
        atual->prox = a;
    }
}

/*
8. Defina uma fun ̧c ̃ao void splitQS (LInt l, int x, LInt *mx, LInt *Mx) que, dada uma
lista ligada l e um inteiro x, parte a lista em duas (retornando os endere ̧cos dos primeiros
elementos da lista em *mx e *Mx): uma com os elementos de l menores do que x e a outra
com os restantes. Note que esta fun ̧c ̃ao n ̃ao dever ́a criar c ́opias dos elementos da lista.
*/

void splitQS (LInt l, int x, LInt *mx, LInt *Mx) {
    *mx = NULL;
    *Mx = NULL;

    LInt atual = l;
    LInt ult_m = NULL;
    LInt ult_M = NULL;

    while (atual != NULL) {
        if (atual->valor < x) {
            if (*mx == NULL) {
                *mx = atual;
            } else {
                ult_m->prox = atual;
            }
            ult_m = atual;
        } else {
            if (*Mx == NULL) {
                *Mx = atual;
            } else {
                ult_M->prox = atual;
            }
            ult_M = atual;
        }
        atual = atual->prox;
    }

    // O toque final: garantir que as listas terminam em NULL 🏁
    if (ult_m != NULL) ult_m->prox = NULL;
    if (ult_M != NULL) ult_M->prox = NULL;
}

// Auxiliar para criar nodo novo
LInt novoNo(int v, LInt proximo) {
    LInt n = malloc(sizeof(struct lligada));
    n->valor = v;
    n->prox = proximo;
    return n;
}

int main() {
    // 1. Criar as duas listas ordenadas
    LInt a = novoNo(10, novoNo(30, novoNo(50, NULL)));
    LInt b = novoNo(20, novoNo(40, NULL));
    
    LInt resultado = NULL;

    printf("Lista A:\n");
    imprimeL(a);
    
    printf("\nLista B:\n");
    imprimeL(b);

    // 2. Executar o Merge
    printf("\nA fazer o merge...\n");
    merge(&resultado, a, b);

    // 3. Mostrar o resultado final
    printf("\nLista Final (Merge):\n");
    imprimeL(resultado);

    // Nota: Como o merge não cria nós novos, basta limpar a lista 'resultado'
    freeL(resultado);

    return 0;
}