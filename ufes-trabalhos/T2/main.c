/* Trabalho 2 - Programação I

Integrantes do grupo: Gabriel Tetzner Menegueti, Kauã de Souza da Silva, Arthur
Marques Campos.

Data: 16/10/2022

Turma: SI 2022/2

*/

#include <stdio.h>

int main(void) {

  long int cpf;
  int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, D10, D11, r, R, L, M;
  printf("Digite seu cpf sem pontuação: ");
  scanf("%ld", &cpf);

  //posiçao dos dígitos do cpf
  d11 = cpf % 10;
  d10 = (cpf / 10) % 10;
  d9 = (cpf / 100) % 10;
  d8 = (cpf / 1000) % 10;
  d7 = (cpf / 10000) % 10;
  d6 = (cpf / 100000) % 10;
  d5 = (cpf / 1000000) % 10;
  d4 = (cpf / 10000000) % 10;
  d3 = (cpf / 100000000) % 10;
  d2 = (cpf / 1000000000) % 10;
  d1 = (cpf / 10000000000) % 10;

  // Calculo do L 
  L = (10 * d1) + (9 * d2) + (8 * d3) + (7 * d4) + (6 * d5) + (5 * d6) +
      (4 * d7) + (3 * d8) + (2 * d9);

  // Calculo do r 
  r = L % 11;

  // se todos os dígitos forem iguais
  if (d1 == d2 && d2 == d3 && d3 == d4 && d4 == d5 && d5 == d6 && d6 == d7 &&
      d7 == d8 && d8 == d9 && d9 == d10 && d10 == d11) {
    printf("O CPF %d%d%d.%d%d%d.%d%d%d-%d%d é inválido.\n", d1, d2, d3, d4,
           d5, d6, d7, d8, d9, d10, d11);
  } else {
    
    // atribuição de r
    if (r == 0 || r == 1) {
      D10 = 0;
    } else {
      D10 = 11 - r;
    }

    //Cálculo do M
    M = (10 * d2) + (9 * d3) + (8 * d4) + (7 * d5) + (6 * d6) + (5 * d7) +
        (4 * d8) + (3 * d9) + (2 * D10);

    //Cálculo do R
    R = M % 11;


    // se R é igual a 0 ou 1, atribuição de R
    if (R == 0 || R == 1) {
      D11 = 0;
    } else {
      D11 = 11 - R;
    }

    // Verificando se d10 == D10 e d11 == D11
    if ((d10 == D10) && (d11 == D11)) {
      printf("O CPF %d%d%d.%d%d%d.%d%d%d-%d%d é válido.\n", d1, d2, d3, d4, d5,
             d6, d7, d8, d9, d10, d11);
    } else {
      printf("O CPF %d%d%d.%d%d%d.%d%d%d-%d%d é inválido.\n", d1, d2, d3, d4,
             d5, d6, d7, d8, d9, d10, d11);
    }
  }

  return 0;
}