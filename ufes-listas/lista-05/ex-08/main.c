#include <stdio.h>
/*
1.8. Crie um programa em linguagem C que leia o arquivo clientes.dat, contendo 5 linhas onde cada linha
contém 2 números reais. Considerando que o primeiro número de cada linha representa o peso de uma
pessoa e o segundo número representa a altura desta mesma pessoa, escreva no arquivo imc.dat o peso,
a altura e o IMC de cada uma das 5 pessoas. Para calcular o IMC utilize a fórmula a seguir:

IMC =
massa
altura · altura
*/
int main(void){
    float dados[10];
    float peso=0.0;
    float altura=0.0;
    float imc=0.0;
    float razao=0.0;
    FILE *arquivo = fopen("clientes.dat", "r");
  
    FILE *arquivo2 = fopen("imc.dat", "w");
    
    for(int i = 0; i < 10; i++){
        if(i >= 2){
           if(i % 2 == 0){
            fscanf(arquivo, "%f", &dados[i]);
           }
        } else{
            fscanf(arquivo, "%f", &dados[i]);
        }
     

      
      
    }

   
    for(int i = 0; i < 20; i ++){
        if((i % 2) == 0){
           peso = dados[i];
        } else {
           altura = dados[i];
        }
       imc = peso / (altura * altura); 
       fprintf(arquivo2, "Peso: %f | Altura: %f | IMC: %f \n", peso, altura, imc);
 
    }

    printf("\n");
    fclose(arquivo);
    fclose(arquivo2);
    return 0;
}