/*
Prova Programação 1 - Questão 2
Nome: Gabriel Tetzner Menegueti
Data: 10/02/2023
*/

#include <stdio.h>

int main(void) {
  FILE *arquivo;
  
  int tamanho = 200, numeros[200], vetor_matricula[10], posicao = 0;

  arquivo = fopen("matricula.dat", "r");

  for(int i = 0; i < tamanho; i++){
    fscanf(arquivo, "%d ", &numeros[i]);

  }

  fclose(arquivo);

  for(int i = 0; i < 64; i+=7){
    vetor_matricula[posicao] = numeros[i];
    posicao = posicao + 1;
  }
  
  printf("\n");
  printf("Meu vetor de 10 números, de acordo com minha matrícula que termina com o 5 digito é: \n");
  printf("\n");
  for(int i = 0; i < 10; i++){
      printf("%d ", vetor_matricula[i]);
  }
  
  printf("\n");
  printf("\n");

  int tamanho_for = 10;
  
  printf("Minha piramisoma é: \n");
  
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < (tamanho_for - 1); j++) {
      vetor_matricula[j] = vetor_matricula[j] + vetor_matricula[j+1];
      printf("%5d ", vetor_matricula[j]);
    }
    printf("\n");
    tamanho_for = tamanho_for - 1;
  }

  printf("\n");
 
  return 0;
}