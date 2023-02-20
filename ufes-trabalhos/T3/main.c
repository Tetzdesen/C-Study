/* Trabalho 3 - Programação I

Integrantes do grupo: Gabriel Tetzner Menegueti, Kauã de Souza da Silva, Arthur
Marques Campos.

Data: 03/11/2022

Turma: SI 2022/2

*/

#include <stdio.h>

int main (void) {
  float u[3], v[3], escalar=0.0;
  int i;
  printf("Digite as três posições do vetor ~U: ");
  scanf("%f %f %f", &u[0], &u[1], &u[2]);
  printf("Digite as três posições do vetor ~V: ");
  scanf("%f %f %f", &v[0], &v[1], &v[2]);
  for (i = 0; i < 3; i++) {
    escalar = escalar + (v[i] * u[i]);
  }
  printf("O produto escalar entre os vetores ~U e ~V é: %.2f\n", escalar);
  return 0;
}