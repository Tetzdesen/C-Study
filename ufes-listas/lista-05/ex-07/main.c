#include <stdio.h>
/*
1.7. Crie um programa em linguagem C que leia o arquivo seqinteiros.dat, contendo uma sequência de 20
números inteiros, e escreva no arquivo razaofib.dat a divisão real de um número da sequência pelo
número anterior da sequência contida neste arquivo.
*/
int main(void){
    float vetor[20];
    float razao=0.0;
    FILE *arquivo = fopen("seqinteiros.dat", "r");
    FILE *arquivo2 = fopen("razaofib.dat", "w");
    for(int i = 0; i < 20; i++){
        fscanf(arquivo, "%f", &vetor[i]);
    }
    //  1 - 0
    // 3 - 2 

    // 
    for(int i = 1, j = 0; i < 20; i += 2, j += 2){
       razao = vetor[i] / vetor[j]; 
       fprintf(arquivo2, "%.8f ", razao);
 
    }

    printf("\n");
    fclose(arquivo);
    fclose(arquivo2);
    return 0;
}