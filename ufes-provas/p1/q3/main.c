/*
Prova Programação 1 - Questão 3
Nome: Gabriel Tetzner Menegueti
Data: 10/02/2023
*/

#include <math.h>
#include <stdio.h>

typedef struct _vt3 {
  float x;
  float y;
  float z;
} tVetorR3;

float calculaModuloR3(tVetorR3 v) {


  // Escreva aqui o código necessário para função calcular o módulo do
  // vetor v.

  float modulo = sqrt((pow((v.x), 2)) + (pow((v.y), 2)) + pow((v.z), 2));

  return modulo;
}

int main() {
  tVetorR3 vetor;
  float modulo;
  // Leitura dos valores do vetor
  printf("Digite as três coordenadas do vetor: ");
  scanf("%f %f %f", &vetor.x, &vetor.y, &vetor.z);
  // Calcular módulo
  modulo = calculaModuloR3(vetor);
  // Imprimir o módulo
  printf("O módulo do vetor (%f, %f, %f) é %f", vetor.x, vetor.y, vetor.z,
         modulo);

  return 0;
}