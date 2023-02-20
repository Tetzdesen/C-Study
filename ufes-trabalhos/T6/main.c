/* Trabalho 6 - Programação I

Integrantes do grupo: Gabriel Tetzner Menegueti, Kauã de Souza da Silva, Arthur
Marques Campos.

Data: 29/01/2023

Turma: SI 2022/2

*/

/******************************************************************************************
 O grupo devera escrever um programa em C, utilizando a estrutura fornecida, que
peca ao usuario para digitar a quantidade de pacientes (nPacientes) que ele
deseja registrar. Apos receber a quantidade, o programa deve alocar um vetor de
TPessoa com o tamanho nPacientes. Apos alocar o vetor, o programa devera ler e
armazenar no vetor os dados de nPacientes pacientes. Para cada paciente
registrado, o programa deve calcular e registrar o IMC correspondente. Ao final
o programa deve imprimir os dados registrados de todos os pacientes.
******************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
// Tipo tPessoa definido como uma estrutura
typedef struct _pessoa {
  char nome[30];
  int idade;
  char sexo;
  float altura;
  float peso;
  float imc;
} tPessoa;


void lePaciente(tPessoa *registro) {
  // Ler e armazenar todos os dados de um paciente
  printf("\nDigite o nome: ");
  scanf(" %[^\n]s", registro->nome);
  printf("Digite a idade: ");
  scanf("%d", &(registro->idade));
  printf("Digite o sexo (M / F): ");
  scanf(" %c", &(registro->sexo));
  printf("Digite a altura: ");
  scanf("%f", &(registro->altura));
  printf("Digite a peso: ");
  scanf("%f", &(registro->peso));
  registro->imc = 0;
  printf("\n");
  fflush(stdin);
}

void imprimePaciente(tPessoa registro) {
  // Imprimir todos os dados de um paciente
  printf("+--------------------------------------+-------+\n");
  printf("| Nome: %30s |  IMC  |\n", registro.nome);
  printf("| Idade: %3d            Sexo: %c        |       |\n", registro.idade,
         registro.sexo);
  printf("| Altura: %4.2f          Peso: %5.1f    |  %4.1f |\n",
         registro.altura, registro.peso, registro.imc);
  printf("+--------------------------------------+-------+\n");
}

// função para calcular o IMC de uma pessoa.
float calculaIMC(tPessoa registro) {
  float massa = registro.peso;
  float altura = registro.altura;
  float imc = massa / (altura * altura);
  return imc;
}

int main(void) {

  int nPacientes = 0;
  tPessoa *vetorPacientes;

  printf("Digite a quantidade de pacientes que você deseja registrar: ");
  scanf("%d", &nPacientes);

  vetorPacientes = (tPessoa *)malloc(nPacientes * sizeof(tPessoa));

  for (int i = 0; i < nPacientes; i++) {
    lePaciente(&vetorPacientes[i]);
    vetorPacientes[i].imc = calculaIMC(vetorPacientes[i]);
  }

  printf("Seus pacientes são: \n");
  for (int i = 0; i < nPacientes; i++) {
    imprimePaciente(vetorPacientes[i]);
  }

  return 0;
}