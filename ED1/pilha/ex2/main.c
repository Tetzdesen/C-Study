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

typedef struct{
  No *topo;
  int tam;
}Pilha;

void criar_Pilha(Pilha *p){
  p->topo = NULL;
  p->tam = 0;
}
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
void push(Pilha *p){
  No *novo = malloc(sizeof(No));

  if(novo){
    lePessoa(&(novo->pessoa));
    novo->proximo = p->topo;
    p->topo = novo;
    p->tam = p->tam + 1;
  } else{
    printf("Erro ao alocar a memória para o seu novo elemento da pilha no topo. ");
  }
  
}

No* pop(Pilha *p){
  if(p->topo){
    No *remover = p->topo;
    p->topo = remover->proximo;
    p->tam = p->tam - 1;
    return remover;
  } else{
    printf("Impossível desempilhar, pois a pilha está vazia. ");
  }
  return NULL;
}


void imprimirPilha(Pilha *p){
  No *aux = p->topo;
  printf("\n--------PILHA---------------------\n");
  while(aux){
    imprimirPessoa(aux->pessoa);

    aux = aux->proximo;
  
  }
  printf("\n--------FIM DA PILHA---------------------\n");

}

int main(void) {
  No *topo = NULL, *remover;
  Pilha p;
  int opcao;
  criar_Pilha(&p);
  do{
    printf("\nDigite as opções: \n\n 1 - Empilhar \n 2 - Desempilhar \n 3 - Imprimir \n 4 - Sair: \n\n Opção: ");
    scanf("%d", &opcao);
    printf("\n");
    switch(opcao){
      case 1:
        push(&p);
        break;
      case 2:
        remover = pop(&p);
        if(remover != NULL){
          printf("Elemento removido. ");
          free(remover);
        }else{
          printf("Sem nó a remover. ");
        }
        break;
      case 3:
        imprimirPilha(&p);
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