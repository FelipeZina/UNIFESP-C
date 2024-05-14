#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char letra;
    struct No* prox;
} No;

typedef struct pilha {
    No* topo;
} pilha;

void pilha_inicializada(pilha* p) {
    p->topo = NULL;
}

int vazia(pilha* p) {
    return p->topo == NULL;
}

void push(char letra, pilha* p) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    novo->letra = letra;
    novo->prox = p->topo;
    p->topo = novo;
}

char pop(pilha* p) {
    if (p->topo == NULL) {
        exit(1);
    }
    No* v = p->topo;
    char letra = v->letra;
    p->topo = v->prox;
    free(v);
    return letra;
}

void freep(pilha* p) {
    while (p->topo != NULL) {
        No* temp = p->topo;
        p->topo = p->topo->prox;
        free(temp);
    }
}

int main() {
    char nucleo[4106];
    int i;
    pilha p;
    int dobra = 0;
    pilha_inicializada(&p);

    fgets(nucleo, sizeof(nucleo), stdin);
    int tamanho = strlen(nucleo) ;

    for (i = 0; i < tamanho; i++) {
        if (vazia(&p)) {
            push(nucleo[i], &p);
        } else {
            if (nucleo[i] == p.topo->letra) {
                pop(&p);
                dobra++;
            } else {
                push(nucleo[i], &p);
            }
        }
    }
    int letras_restantes = tamanho - dobra;
    printf("%d\n", letras_restantes-1);


    freep(&p);
    return 0;
}