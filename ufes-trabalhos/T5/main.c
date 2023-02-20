/* Trabalho 5 - Programação I

Integrantes do grupo: Gabriel Tetzner Menegueti, Kauã de Souza da Silva, Arthur
Marques Campos.

Data: 17/12/2022

Turma: SI 2022/2

*/

#include <stdio.h>

#include <string.h>

int main(void) {
  char mensagem[61];
  char chave[12] = "EARTE2020/1";
  int codigo[60];
  int opcao = 0;
  int tamanho = 0;
  int i;

  do {
    printf("\n");
    printf("Por favor, digite o número de uma das opções a seguir: \n 1 - Codificar mensagem \n 2 - Decodificar mensagem \n 3 - Sair \n");
    printf("Qual é a sua opção? ");
    scanf("%d", &opcao);
    switch (opcao) {
      case 1:
  
        printf("\n");
        printf("Digite sua mensagem (até 60 caracteres e sem espaços): ");
        scanf("%s", mensagem);
        tamanho = strlen(mensagem);
  
        for (i = 0; i < tamanho; i++) {
          codigo[i] = mensagem[i] ^ chave[i % 11];
        }
  
        printf("\n");
  
        printf("O tamanho da sua mensagem é: %d\n", tamanho);
  
        printf("Sua mensagem codificada é: ");
        for (i = 0; i < tamanho; i++) {
          printf("%d ", codigo[i]);
        }
        printf("\n");
        break;
  
      case 2:
        printf("\n");
  
        printf("Digite o tamanho da mensagem a ser decodificada (até 60): ");
        scanf("%d", &tamanho);
  
        printf("Digite a mensagem a ser decodificada (máximo de %d caracteres): ",
               tamanho);
  
        for (i = 0; i < tamanho; i++) {
          scanf("%d", &codigo[i]);
        }
  
        for (i = 0; i < tamanho; i++) {
          mensagem[i] = codigo[i] ^ chave[i % 11];
        }
        printf("\n");
        printf("O tamanho da sua mensagem é: %d\n", tamanho);
        printf("Sua mensagem decodificada é: ");
        for (i = 0; i < tamanho; i++) {
          printf("%c", mensagem[i]);
        }
        printf("\n");
        break;
    
      case 3:
        break;
  
      default:
        printf("\n");
        printf("Digite um valor que está entre as opções fornecidas. \n");
    }
  } while (opcao != 3);

  return 0;
}