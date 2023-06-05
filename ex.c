#include <stdio.h>

int main() {
  int mat[4][5];
  int somalinha[4] = {0};
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 5; j++) {
      printf("linha[%d]-coluna[%d]", i, j);
      scanf("%d", &mat[i][j]);
      somalinha[i] += mat[i][j];
    }
  }
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 5; j++) {
      printf("\t%d", mat[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < 4; i++) {
    printf("Soma da linha %d: %d\n", i, somalinha[i]);
  }
  return 0;
}