/* Trabalho 4 - Programação I

Integrantes do grupo: Gabriel Tetzner Menegueti, Kauã de Souza da Silva, Arthur
Marques Campos.

Data: 25/11/2022

Turma: SI 2022/2

*/
#include <stdio.h>

int main(void) {
  float matrizA[3][3], matrizB[3][3];
  float matrizC[3][3] = {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
  int i, j, k;

  // Lendo 9 números da matriz A.
  printf("Digite os 9 números reais da sua matriz: ");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      scanf("%f", &matrizA[i][j]);
    }
  }

  // Lendo 9 números da matriz B.
  printf("Digite outros 9 números reais da sua outra matriz: ");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      scanf("%f", &matrizB[i][j]);
    }
  }

  // Fazendo o calculo do produto e armazenando na matriz C.
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++) {
        matrizC[i][j] += (matrizA[i][k] * matrizB[k][j]);
      }
    }
  }

  printf("\nO produto das matrizes é: \n\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%.2f  ", matrizC[i][j]);
    }
    printf("\n");
  }

  return 0;
}