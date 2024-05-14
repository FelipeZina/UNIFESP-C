#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    struct lista* ant;
    int numcasa;
    struct lista* prox;
} Tlista;

typedef Tlista *Plista;

Plista novo(int dado) {
    Plista novoNo = (Plista)malloc(sizeof(Tlista));
    novoNo->numcasa = dado;
    novoNo->prox = NULL;
    novoNo->ant = NULL;
    return novoNo;
}

void inserir(Plista* casas, int dado) {
    Plista novoNo = novo(dado);
    if (*casas == NULL) {
        *casas = novoNo;
    } else {
        Plista temp = *casas;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novoNo;
        novoNo->ant = temp;
    }
}

int calcularTempo(Plista casas, int* ordem, int m,int n) {
    int tempo = 0;
    Plista atual = casas;
    Plista ultimoVisitado = casas; 
    if (n == 1)
        return tempo;

    for (int i = 0; i < m; i++) {
     if (ordem[i] < atual->numcasa) {
            while (atual->numcasa != ordem[i]) {
                atual = atual->ant;
                tempo++;
            }
            ultimoVisitado = atual;
        } else if (ordem[i] > atual->numcasa) {
            while (atual->numcasa != ordem[i]) {
                atual = atual->prox;
                tempo++;
            }
            ultimoVisitado = atual;
        }
    }
    return tempo;
}


void liberar(Plista casas) {
    Plista atual = casas;
    while (atual != NULL) {
        Plista temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
 

    Plista casas = NULL;
    for (int i = 0; i < n; i++) {
        int casa;
        scanf("%d", &casa);
        inserir(&casas, casa);
    }

    int ordem[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &ordem[i]);
    }

    int tempo = calcularTempo(casas, ordem, m,n);
    printf("%d\n", tempo);

    liberar(casas);

    return 0;
}