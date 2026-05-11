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

/*
9. Defina uma fun ̧c ̃ao LLig parteAmeio (LLig *l) que, parte uma lista n ̃ao vazia *l a meio.
Se x contiver os elementos 1,2,3,4,5, ap ́os a invoca ̧c ̃ao y=parteAmeio(&x) a lista y dever ́a
conter os elementos 1,2 e a lista x os restantes 3,4,5
*/

LInt parteAmeio (LInt *l) {
    int i, total = 0;

    LInt temp = *l;
    while (temp) {
        total++;
        temp = temp->prox;
    }

    int meio = total / 2;

    if (meio == 0) return NULL; // x <= 1 elemento, nao corta nada

    //Correr atual ate ao meio da lista
    LInt atual = *l;
    for (i = 0; i < meio - 1; i++) {
        atual = atual->prox;
    }

    //Agora atual esta a meio da lista e podemos cortar
    LInt y = *l; //y começa a 0
    *l = atual->prox; // x começa a meio
    atual->prox = NULL; //cortamos a cauda de y

    return y;
}

/*
10. Apresente uma defini ̧c ̃ao n ̃ao recursiva da fun ̧c ̃ao int removeAll (LInt *, int) que remove
todas as ocorrˆencias de um dado inteiro de uma lista, retornando o n ́umero de c ́elulas removi-
das.
*/

int removeAll (LInt *l, int n) {
    int counter = 0;
    LInt atual = *l;
    LInt prev = NULL;

    while (atual != NULL) {
        if (atual->valor == n) { // Se for para remover
            counter++;
            LInt temp = atual;
            
            if (prev == NULL) {
                // Caso seja o primeiro nó, movemos o início da lista
                *l = atual->prox;
                atual = *l;
            } else {
                // Caso contrário, o anterior "salta" o atual
                prev->prox = atual->prox;
                atual = prev->prox;
            }
            free(temp);
        } else {
            // Se não for para remover, apenas avançamos ambos
            prev = atual;
            atual = atual->prox;
        }
    }
    return counter;
}

/*
11. Apresente uma defini ̧c ̃ao da fun ̧c ̃ao int removeDups (LInt *) que remove os valores repeti-
dos de uma lista (deixando apenas a primeira ocorrˆencia).
*/

int removeDups (LInt *l) {
    LInt atual = *l;
    int removidos = 0;

    while (atual != NULL) {
        LInt insider_atual = atual->prox;
        LInt insider_anterior = atual;

        while (insider_atual != NULL) {
            if (insider_atual->valor == atual->valor ) {
                // duplicado encontrado
                removidos++;
                insider_anterior->prox = insider_atual->prox;
                LInt temp = insider_atual;
                insider_atual = insider_atual->prox;
                free (temp);
            } else {
                insider_anterior = insider_atual;
                insider_atual = insider_atual->prox;
            }
        }
        // Depois de percorrer a lista ligada por x vamos a procura de outro
        atual = atual->prox;
    }
    return removidos;
}

/*
12. Apresente uma defini ̧c ̃ao da fun ̧c ̃ao int removeMaiorL (LInt *) que remove (a primeira
ocorrˆencia) o maior elemento de uma lista n ̃ao vazia, retornando o valor desse elemento.
*/

int removeMaiorL (LInt *l) {
    LInt atual = *l;
    LInt anterior = NULL;
    LInt maior_node = atual;
    LInt pre_maior = NULL;
    int record = atual->valor;

    while (atual != NULL) {
        if (atual->valor > record) {
            record = atual->valor;
            maior_node = atual;
            pre_maior = anterior; // Guardamos exatamente quem vinha atrás do recorde!
        }
        // Avançamos ambos os ponteiros passo a passo
        anterior = atual;
        atual = atual->prox;
    }

    // Desligar o maior nó da corrente
    if (pre_maior == NULL) {
        // Se o pre_maior continuar a NULL, significa que o maior era logo o 1º elemento!
        *l = maior_node->prox;
    } else {
        // Caso contrário, o nó anterior "salta" o maior_node
        pre_maior->prox = maior_node->prox;
    }

    // Limpar a memória e devolver o valor
    free(maior_node);
    return record;
}

/*
13. Apresente uma defini ̧c ̃ao n ̃ao recursiva da fun ̧c ̃ao void init (LInt *) que remove o  ́ultimo
elemento de uma lista n ̃ao vazia (libertando o correspondente espa ̧co).
*/

void removeUltimo (LInt *l) {
    if (*l == NULL) return; 

    LInt atual = *l;
    LInt anterior = NULL;

    // Paramos quando o *próximo* for NULL (estamos no último nó!)
    while (atual->prox != NULL) {
        anterior = atual;
        atual = atual->prox;
    }

    // Desligar a cauda
    if (anterior == NULL) {
        // Só havia 1 elemento na lista. A lista passa a vazia.
        *l = NULL;
    } else {
        // O penúltimo elemento passa a ser o novo último
        anterior->prox = NULL;
    }

    // 3. Libertar a memória do último nó
    free(atual);
}

/*
14. Apresente uma defini ̧c ̃ao n ̃ao recursiva da fun ̧c ̃ao void appendL (LInt *, int) que acres-
centa um elemento no fim da lista.
*/

void appendL (LInt *l, int x) {
    // Criar e alocar o novo nó
    LInt novo = malloc(sizeof(struct lligada));
    novo->valor = x;
    novo->prox = NULL;

    // Se a lista estiver vazia, o novo nó é a cabeça
    if (*l == NULL) {
        *l = novo;
    } else {
        // Caso contrário, percorrer até ao último
        LInt atual = *l;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

/*
15. Apresente uma defini ̧c ̃ao da fun ̧c ̃ao void concatL (LInt *a, LInt b) que acrescenta a lista
b `a lista *a
*/

void concatL (LInt *a, LInt b) {
    LInt cu = b;
    // se nao houver pixa o cu fode-se sozinho
    if (*a == NULL) {
        *a = cu;
    } else {
        LInt pixa = *a;

    // encontrar a ponta da pixa
    while (pixa->prox != NULL) {
        pixa = pixa->prox;
        }
    // e por no cu
    pixa->prox = cu;
    }
}

/*
16. Apresente uma defini ̧c ̃ao da fun ̧c ̃ao LInt cloneL (LInt) que cria uma nova lista ligada com
os elementos pela ordem em que aparecem na lista argumento.
*/

LInt cloneL (LInt l) {
    if (l == NULL) return NULL;

    // Criar o primeiro nó (a cabeça da nossa nova lista)
    LInt clone_head = malloc(sizeof(struct lligada));
    clone_head->valor = l->valor; // Copiamos apenas o NÚMERO!
    clone_head->prox = NULL;

    // Apontadores de trabalho
    LInt atual = l->prox;    // Vai percorrer o resto da original (a partir do 2º)
    LInt cauda = clone_head; // Fica na ponta do clone para irmos colando

    // 2. Percorrer o resto da lista original
    while (atual != NULL) {
        // Criar uma casa nova
        LInt novo = malloc(sizeof(struct lligada));
        novo->valor = atual->valor; // Copiar o número
        novo->prox = NULL;

        // Colar a casa nova na ponta da nossa lista clonada
        cauda->prox = novo;
        
        // A cauda avança para a nova ponta
        cauda = novo;

        // Avançar na lista original
        atual = atual->prox;
    }

    return clone_head;
}

/*
17. Apresente uma defini ̧c ̃ao n ̃ao recursiva da fun ̧c ̃ao LInt cloneRev (LInt) que cria uma nova
lista ligada com os elementos por ordem inversa.
Por exemplo, se a lista l tiver 5 elementos com os valores [1,2,3,4,5] por esta ordem, a
invoca ̧c ̃ao cloneRev(l) deve corresponder a uma nova lista com os elementos [5,4,3,2,1]
por esta ordem
*/

LInt cloneRev (LInt l) {
    LInt atual = l;
    LInt nova_cabeca = NULL; // A lista invertida começa vazia

    // Percorremos a lista original normalmente, do início para o fim
    while (atual != NULL) {
        LInt novo = malloc(sizeof(struct lligada));
        novo->valor = atual->valor;

        novo->prox = nova_cabeca;
        nova_cabeca = novo;

        atual = atual->prox;
    }

    return nova_cabeca;
}

/*
18. Defina uma fun ̧c ̃ao int maximo (LInt l) que calcula qual o maior valor armazenado numa
lista n ̃ao vazia.
*/

int maximo (LInt l) {
    LInt atual = l;
    int record = atual->valor;

    atual = atual->prox;

    while (atual != NULL) {
        if (atual->valor > record) {
            record = atual->valor;
        }

        atual = atual->prox;
    }
    return record;
}

/*
19. Apresente uma defini ̧c ̃ao iterativa da fun ̧c ̃ao int take (int n, LInt *l) que, dado um in-
teiro n e uma lista ligada de inteiros l, apaga de l todos os nodos para al ́em do n- ́esimo
(libertando o respectivo espa ̧co). Se a lista tiver n ou menos nodos, a fun ̧c ̃ao n ̃ao altera a
lista.
A fun ̧c ̃ao deve retornar o comprimento final da lista.
*/

int take (int n, LInt *l) {
    int cont = 0;
    LInt atual = *l;
    LInt anterior = NULL;

    // Percorrer até contar 'n' elementos ou a lista acabar
    while (atual != NULL && cont < n) {
        anterior = atual;
        atual = atual->prox;
        cont++;
    }

    // O TRAVÃO DE OURO: se a lista tem n ou menos nós, não se altera nada!
    if (atual == NULL) {
        return cont;
    }

    // Se chegámos aqui, é porque atual != NULL (a lista tem MAIS de n nós)
    if (anterior == NULL) {
        // Caso n <= 0: apagar a lista toda desde a cabeça
        while (atual != NULL) {
            LInt temp = atual;
            atual = atual->prox;
            free(temp);
        }
        *l = NULL;
    } else {
        // Caso normal: cortar a ligação no n-ésimo nó
        anterior->prox = NULL;

        // Limpar o resto do lixo que ficou para a frente
        while (atual != NULL) {
            LInt temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }

    return cont;
}

/*
20. Apresente uma defini ̧c ̃ao iterativa da fun ̧c ̃ao int drop (int n, LInt *l) que, dado um in-
teiro n e uma lista ligada de inteiros l, apaga de l os n primeiros elementos da lista (libertando
o respectivo espa ̧co). Se a lista tiver n ou menos nodos, a fun ̧c ̃ao liberta a totalidade da lista.
A fun ̧c ̃ao deve retornar o n ́umero de elementos removidos.
*/

int drop (int n, LInt *l) {
    int del = 0;
    LInt atual = *l;

    while (atual != NULL && del < n) {
        LInt temp = atual;
        atual = atual->prox;
        free (temp);
        del++;
    }

    *l = atual;

    return del;
}

// Auxiliar para criar nodo novo
LInt novoNo(int v, LInt proximo) {
    LInt n = malloc(sizeof(struct lligada));
    n->valor = v;
    n->prox = proximo;
    return n;
}

int main() {
    LInt lista = NULL;

    printf("--- Teste Questao 14 (Append) ---\n");
    appendL(&lista, 10);
    appendL(&lista, 50);
    appendL(&lista, 20);
    appendL(&lista, 30);
    imprimeL(lista); // Esperado: 10 -> 50 -> 20 -> 30 -> NULL

    printf("\n--- Teste Questao 12 (Remove Maior) ---\n");
    int maior = removeMaiorL(&lista);
    printf("Maior removido: %d\n", maior);
    imprimeL(lista); // Esperado: 10 -> 20 -> 30 -> NULL

    printf("\n--- Teste Questao 13 (Remove Ultimo) ---\n");
    removeUltimo(&lista);
    imprimeL(lista); // Esperado: 10 -> 20 -> NULL

    return 0;
}