#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arv.h"

void InsereResultNoArquivo(FILE* saida, float result);

int main (){

    //Declara variáveis necessárias
    char* string = (char*) malloc(100*sizeof(char));
    float result;
    Arv* arv;
    FILE *entrada, *saida;

    //abre o arquivo "saida.txt" apagando seu conteúdo (caso exista)
    saida = fopen("saida.txt", "w");

    //abre o arquivo "entrada.txt" pra leitura
    entrada = fopen("entrada.txt", "r");
    if (entrada==NULL) //verifica existencia do arquivo de entrada
        printf("ERRO AO ABRIR ARQUIVO DE ENTRADA\n"); 
    else
        printf("O arquivo de entrada foi aberto corretamente\n");
    fclose(saida); //fecha o arquivo "saida.txt"
    
    //abre novamente o arquivo "saida.txt", agora no modo "escrita ao final do existente"
    saida = fopen("saida.txt", "a");

    while (fscanf(entrada, "%s", string) != EOF){
        int ir = 0; //auxiliar para a função parsing

        result = 0.0; //zera resultado

        arv = CriaArv();
        arv = AlocaArv(arv);
        arv = Parsing(arv, string, &ir);

        result = Calculo(arv);

        InsereResultNoArquivo(saida, result);

        arv = DestroiArv(arv); 
    } 

    //Libera memória alocada
    free(string);

    //Fecha arquivos abertos
    fclose(entrada);
    fclose(saida);

    return 0;
}

void InsereResultNoArquivo(FILE* saida, float result){
    //Declara variáveis auxiliares, ambas vão receber o mesmo valor 
    int inteiro = result;
    float decimal = result;

    //Se fizermos a subtração e não houver casas decimais de resto é porque result é, na verdade, inteiro
    if (decimal - inteiro == 0.0)
        fprintf(saida, "%d\n", inteiro);
    else //result é um número "quebrado"
        fprintf(saida, "%.2f\n", decimal);

    return;
}