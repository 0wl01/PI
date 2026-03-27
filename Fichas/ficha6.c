#include <stdhio.h>

typedef struct staticStack {
int sp;
int values [Max];
} STACK, *SStack;

// 1. Considere o seguinte tipo para representar stacks de n´umeros inteiros.

/*
a) void SinitStack (SStack s) que inicializa uma stack (passa a representar uma stack
vazia)
*/

void SinitStack (SStack s) {
    // (*s).sp = 0;
    s->sp = 0;
}

/*
(b) int SisEmpty (SStack s) que testa se uma stack e vazia
*/

int SisEmpty (SStack s) {
    return (s->sp == 0);
}

/*
(c) int Spush (SStack s, int x) que acrescenta x ao topo de s; a funcao deve retornar 0 se
a operacao for feita com sucesso (i.e., se a stack ainda nao estiver cheia) e 1 se a operacao
nao for poss ́ıvel (i.e., se a stack estiver cheia).
*/

int Spush (SStack s, int x) {
    if (s->sp == MAX) {
        return 1;
    }

    s->values[s->sp] = x;
    s->sp++;

    return 0;
}


/*
(d) int Spop (SStack s, int *x) que remove de uma stack o elemento que esta no topo. A
funcao devera colocar no endereco x o elemento removido. A funcao dever ́a retornar 0 se a
operacao for poss ́ıvel (i.e. a stack nao esta vazia) e 1 em caso de erro (stack vazia).
*/

int Spop (SStack s, int *x); {
    int popped;

    if (s->sp == 0) {
        return 1;
    }

    int popped = s->values[(s->sp) - 1];
    *x = popped;

    (s->sp)--;

    return 0;
}

/*
(e) int Stop (SStack s, int *x) que coloca no endereco x o elemento que esta no topo da
stack (sem modificar a stack). A funcao devera retornar 0 se a operacao for poss ́ıvel (i.e. a
stack nao esta vazia) e 1 em caso de erro (stack vazia).
*/


// Stora passou para ex 3

/*
3. Na representacao de stacks e queues sugeridas nas alıneas anteriores o array de valores tem
um tamanho fixo (definido pela constante MAX). Uma consequencia dessa definicao  ́e o facto
de as funcoes de insercao (push e enqueue) poderem nao ser executadas por se ter excedido a
capacidade da estruturas.
Uma definicao alternativa consiste em nao ter um array com tamanho fixo e sempre que seja
preciso mais espaco, realocar o array para um de tamanho superior (normalmente duplica-se o
tamanho do array).
Considere entao as seguintes definicoes alternativas e adapte as funcoes definidas atras para esta
nova representacao.
Use as funcoes malloc e free cujo tipo est ́a definido em stdlib.h
*/

typedef struct dinStack {
int size; // guarda o tamanho do array values
int sp;
int *values;
} *DStack;

typedef struct dinQueue {
int size; // guarda o tamanho do array values
int front;
int length;
int *values;
} *DQueue;

void DinitStack (DStack s, int n) {
    s->sp = 0;
    s->size = n;
    s->values = malloc(sizeof(int) * (n));
}

int dupStack (DStack s) {
    int new_size = s->size*2;

    int *temp = realloc(s-values, new_size * sizeof(int));

    if (temp == NULL) {
        return 1;
    }

    s->values = temp;
    s->size = new_size;

    return 0;
}

int Dpush (DStacks s, int x) {
    if (s->sp == s->size) {
        r = dupStack(s);
    }

    if (r == 0) {
        s->values[(s->sp)++] = x;
    }
    return r;
}

int Dpop (DStacks s) {
    
}

void main() {
    STACK s1;
    SinitStack(&s1);
}