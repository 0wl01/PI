#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} *ABin;

/*
28. Apresente uma defini ̧c ̃ao da fun ̧c ̃ao int altura (ABin) que calcula a altura de uma  ́arvore
bin ́aria.
*/

int altura (ABin l) {
    int e, d;

    // Caso base: se chegámos ao vazio, a altura aqui é 0
    if (l == NULL) return 0;

    // 1. Delegar: ir até ao fundo saber a altura de cada lado
    e = altura(l->esq);
    d = altura(l->dir);

    // 2. Contar na subida: somamos 1 (nó atual) ao lado que for maior
    if (e > d) {
        return 1 + e;
    } else {
        return 1 + d;
    }
}

/*
29. Defina uma fun ̧c ̃ao ABin cloneAB (ABin) que cria uma c ́opia de uma  ́arvore.
*/

ABin cloneAB (ABin a) {
    if (a == NULL) return NULL;

    ABin novo = malloc(sizeof(struct nodo));
    novo->valor = a->valor;

    novo->esq = cloneAB(a->esq);
    novo->dir = cloneAB(a->dir);

    return novo;
}

/*
30. Defina uma fun ̧c ̃ao void mirror (ABin *) que inverte uma  ́arvore (sem criar uma nova
 ́arvore).
*/

void mirror (ABin *a) {
    if (*a == NULL) return;

    ABin temp = (*a)->esq;
    (*a)->esq = (*a)->dir;
    (*a)->dir = temp;

    mirror(&((*a)->esq));
    mirror(&((*a)->dir));
}

/*
31. Defina a fun ̧c ̃ao void inorder (ABin , LInt *) que cria uma lista ligada de inteiros a partir
de uma travessia inorder de uma  ́arvore bin ́aria
*/

typedef struct lligada {
            int valor;
        struct lligada *prox;
} *LInt;

void inorder (ABin a, LInt *l) {
    // Caso base: se a árvore é vazia, não fazemos nada
    if (a == NULL) return;

    // 1. Visitar primeiro a DIREITA (os maiores)
    inorder(a->dir, l);

    // 2. Processar a RAIZ: Criar um nó novo e inseri-lo à CABEÇA da lista
    LInt novo = malloc(sizeof(struct lligada));
    novo->valor = a->valor;
    novo->prox = *l;
    *l = novo; // A lista passa a começar neste novo nó

    // 3. Visitar a ESQUERDA (os menores, que vão ficar à frente na lista)
    inorder(a->esq, l);
}

/*
32. Defina a fun ̧c ̃ao void preorder (ABin , LInt *) que cria uma lista ligada de inteiros a
partir de uma travessia preorder de uma  ́arvore bin ́aria.
*/

void preorder (ABin a, LInt *l) {
    // Caso base: se a árvore é vazia, não fazemos nada
    if (a == NULL) return;

    // 1. Visitar primeiro a DIREITA (o último elemento do preorder normal)
    preorder(a->dir, l);

    // 2. Visitar a ESQUERDA do nó atual
    preorder(a->esq, l);

    // 3. Processar a RAIZ por último: Inserir à CABEÇA da lista
    LInt novo = malloc(sizeof(struct lligada));
    novo->valor = a->valor;
    novo->prox = *l;
    *l = novo;
}

/*
33. Defina a fun ̧c ̃ao void posorder (ABin , LInt *) que cria uma lista ligada de inteiros a
partir de uma travessia posorder de uma  ́arvore bin ́aria.
*/

void posorder (ABin a, LInt *l) {
    if (a == NULL) return;

    LInt novo = malloc(sizeof(struct lligada));
    novo->valor = a->valor;
    novo->prox = *l;
    *l = novo;
    
    posorder(a->dir, l);
    
    posorder(a->esq, l);
}

/*
34. Apresente uma defini ̧c ̃ao da fun ̧c ̃ao int depth (ABin a, int x) que calcula o n ́ıvel (menor)
a que um elemento est ́a numa  ́arvore bin ́aria (-1 caso n ̃ao exista).
*/

int depth (ABin a, int x) {
    if (a == NULL) return -1;

    if (a->valor == x) return 1;

    // Procurar o elemento em ambos os lados
    int e = depth(a->esq, x);
    int d = depth(a->dir, x);

    // Analisar os retornos para devolver o menor nível válido
    if (e == -1 && d == -1) return -1; // Não existe em nenhum dos lados
    if (e == -1) return 1 + d;         // Só existe à direita
    if (d == -1) return 1 + e;         // Só existe à esquerda

    // Se existe em ambos os lados, escolhemos o nível mais raso (menor)
    if (e < d) {
        return 1 + e;
    } else {
        return 1 + d;
    }
}

/*
35. Defina uma fun ̧c ̃ao int freeAB (ABin a) que liberta o espa ̧co ocupado por uma  ́arvore
bin ́aria, retornando o n ́umero de nodos libertados.
*/

int freeAB (ABin a) {

    if (a == NULL) return 0;

    int e = freeAB(a->esq);
    int d = freeAB(a->dir);

    free(a);
    return 1 + e + d;
}

/*
36. Defina uma fun ̧c ̃ao int pruneAB (ABin *a, int l) que remove (libertando o espa ̧co respec-
tivo) todos os elementos da  ́arvore *a que est ̃ao a uma profundidade superior a l, retornando
o n ́umero de elementos removidos.
Assuma que a profundidade da ra ́ız da  ́arvore  ́e 1, e por isso a invoca ̧c ̃ao pruneAB(&a,0)
corresponde a remover todos os elementos da  ́arvore a.
*/

int pruneAB (ABin *a, int l) {
    
}