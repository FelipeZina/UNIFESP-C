#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no* prox;
} Tno;

typedef Tno* Pno;

typedef struct fila {
    Pno ini;
    Pno fim;
} Tfila;

typedef Tfila* pfila;

Pno novoNo(int dado) {
    Pno temp = (Pno)malloc(sizeof(Tno));
    temp->dado = dado;
    temp->prox = NULL;
    return temp;
}

pfila criarFila() {
    pfila f = (pfila)malloc(sizeof(Tfila));
    f->ini = f->fim = NULL;
    return f;
}

void enfileirar(pfila f, int dado) {
    Pno temp = novoNo(dado);

    if (f->fim == NULL) {
        f->ini = f->fim = temp;
        return;
    }

    f->fim->prox = temp;
    f->fim = temp;
}

int desenfileirar(pfila f) {
    if (f->ini == NULL)
        return -1;

    Pno temp = f->ini;
    f->ini = f->ini->prox;

    if (f->ini == NULL)
        f->fim = NULL;

    int dado = temp->dado;
    free(temp);
    return dado;
}

int maiorPremiacao(int caixas[], int n) {
    pfila f = criarFila();
    int saldo = 100;
    int saldo_atual = 100;
    int premio_maximo = 100;

    for (int i = 0; i < n; i++) {
        enfileirar(f, caixas[i]);
    }

    while (f->ini != NULL) {
        int valor = desenfileirar(f);
        saldo_atual += valor;

        if (saldo_atual > premio_maximo) {
            premio_maximo = saldo_atual;
        }

        if (saldo_atual < saldo) {
            saldo = saldo_atual;
        }
    }

    free(f);

    return premio_maximo;
}

int main() {
    int C, i;
    scanf("%d", &C);
    int caixas[C];

    for (i = 0; i < C; i++) {
        scanf("%d", &caixas[i]);
    }

    printf("%d\n", maiorPremiacao(caixas, C));

    return 0;
}