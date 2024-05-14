#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int B, F;
    long int D;
    int Doou;
} Convid;

double verificarTotal(Convid **convidados, int tam, double total) {
    for (int i = 0; i < tam; i++) {
        if (convidados[i]->D > total) {
            total = convidados[i]->D;
        }
    }
    return total;
}

int main(void) {
    int tam, i = 0, j = 0;
    double total = 0;
    Convid **convidados;

    scanf("%d", &tam);
    convidados = (Convid **) malloc(sizeof(Convid *) * tam);

    for (i = 0; i < tam; i++) {
        convidados[i] = (Convid *) malloc(sizeof(Convid));
        scanf("%d %d %ld", &convidados[i]->B, &convidados[i]->F, &convidados[i]->D);

        if (convidados[i]->B < 1 || convidados[i]->B > pow(10.0, 9.0) ||
            convidados[i]->F < 1 || convidados[i]->F > pow(10.0, 9.0) ||
            convidados[i]->D < 1 || convidados[i]->D > pow(10.0, 9.0)) {
            return 1;
        }
    }

    int **comb = (int **) malloc(tam * sizeof(int *));
    for (i = 0; i < tam; i++) {
        comb[i] = (int *) malloc(tam * sizeof(int));
    }

    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            comb[i][j] = 0; 
        }
    }

    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            if (i != j && convidados[i]->Doou == 0) {
                if (convidados[i]->F > convidados[j]->F && convidados[i]->B > convidados[j]->B ||
                  convidados[i]->F == convidados[j]->F && convidados[i]->B == convidados[j]->B) {
          
                    comb[i][j] = convidados[i]->D;
                    convidados[i]->Doou++;
                }
                if (convidados[i]->F < convidados[j]->F && convidados[i]->B < convidados[j]->B
                    && convidados[i]->Doou == 0) {
                    comb[i][j] = convidados[i]->D;
                    convidados[i]->Doou++;
                    convidados[j]->Doou++;
                }
            }
        }
    }

    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            total += comb[i][j];
        }
    }

    total = verificarTotal(convidados, tam, total);

    printf("%.0lf\n", total);

    for (i = 0; i < tam; i++) {
        free(comb[i]);
        free(convidados[i]);
    }
    free(comb);
    free(convidados);

    return 0;
}