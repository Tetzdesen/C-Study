#include <stdio.h>
#include <stdlib.h>

typedef struct{
   char nome[50];
   int idade;
   char sexo;
   float peso;
   float altura;
   
} Pessoa;

typedef struct no{
   Pessoa pessoa;
   struct no *proximo;
} No;

void lePessoa(Pessoa *pessoa){
  printf("Digite o nome da pessoa: ");
  scanf("%s", pessoa->nome);
  printf("Digite a idade da pessoa: ");
  scanf("%d", &(pessoa->idade));
  printf("Digite o sexo da pessoa: ");
  scanf(" %c", &(pessoa->sexo));
  printf("Digite o peso da pessoa: ");
  scanf("%f", &(pessoa->peso));
  printf("Digite a altura da pessoa: ");
  scanf("%f", &(pessoa->altura));
}


void imprimirPessoa(Pessoa pessoa){
    printf("Pessoa: \n Nome: %s \n Idade: %d \n Sexo: %c \n Peso: %.2f \n Altura: %.2f \n", pessoa.nome, pessoa.idade, pessoa.sexo, pessoa.peso, pessoa.altura);
}

// empilhar na pilha
No* push(No *topo){
  No *novo = malloc(sizeof(No));

  if(novo){
    lePessoa(&(novo->pessoa));
    novo->proximo = topo;
    return novo;
  } else{
    printf("Erro ao alocar a memória para o seu novo elemento da pilha no topo. ");
  }
  
  return NULL;
  
}

No* pop(No **topo){
  if(*topo != NULL){
    No *remover = *topo;
    *topo = remover->proximo;
    return remover;
  } else{
    printf("Impossível desempilhar, pois a pilha está vazia. ");
  }
  return NULL;
}


void imprimirPilha(No *topo){
  printf("\n--------PILHA---------------------\n");
  while(topo != NULL){
    imprimirPessoa(topo->pessoa);

    topo = topo->proximo;
  
  }
  printf("\n--------FIM DA PILHA---------------------\n");

}

int main(void) {
  No *topo = NULL, *remover;
  int opcao;
  do{
    printf("\nDigite as opções: \n\n 1 - Empilhar \n 2 - Desempilhar \n 3 - Imprimir \n 4 - Sair: \n\n Opção: ");
    scanf("%d", &opcao);
    printf("\n");
    switch(opcao){
      case 1:
   
        topo = push(topo);
        printf("%s ", (topo->pessoa).nome);
        printf("\n");
        printf("%d ", (topo->pessoa).idade);    
        printf("\n");
        break;
      case 2:
        remover = pop(&topo);
        if(remover != NULL){
          printf("Elemento removido. ");
        }else{
          printf("Sem nó a remover. ");
        }
        break;
      case 3:
        imprimirPilha(topo);
        break;
      default:
        if(opcao != 4){
          printf("Opção inválida. ");
        }
        break;
  }
   
  printf("\n");
  } while(opcao != 4);

  return 0;
}