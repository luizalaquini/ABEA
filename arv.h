#ifndef ARVORE_H_
#define ARVORE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore Arv;

/*CRIA UMA ÁRVORE BINÁRIA DE EXPRESSÕES ARITMÉTICAS (ABEA) NULA;
 *inputs: -
 *outputs: ponteiro para árvore 
 *pré-condição: -
 *pós-condição: Arvore de retorno existe e é nula
*/
Arv* CriaArv (void);

/*ALOCA ESPAÇO DA ÁRVORE;
 *inputs: ponteiro pra árvore a ser alocada
 *outputs: ponteiro pra árvore (após ser alocada)
 *pré-condição: árvore deve existir
 *pós-condição: árvore antes nula agora possui espaço alocado
*/
Arv* AlocaArv (Arv* a);

/*IMPRIME ÁRVORE
 *inputs: arvore a ser imprimida
 *outputs: -
 *pré-condição: Árvore deve existir
 *pós-condição: -
*/
void ImprimeArv (Arv *a);

/*LIBERA MEMÓRIA OCUPADA PELA ÁRVORE
 *inputs: Árvore a ser liberada
 *outputs: Árvore nula
 *pré-condição: Árvore deve existir
 *pós-condição: Árvore é nula
*/
Arv* DestroiArv (Arv* a);

/*ANALISA SE O CARACTERE É NÚMERO
 *inputs: caracter a ser analisado
 *outputs: Verdadeiro caso seja número e falso caso contrário
 *pré-condição: caractere deve existir 
 *pós-condição: -
*/
int EhNumero (char x);

/*ANALISA SE O CARACTERE É OPERADOR
 *inputs: caracter a ser analisado
 *outputs: Verdadeiro caso seja operador e falso caso contrário
 *pré-condição: caractere deve existir 
 *pós-condição: -
*/
int EhOperador (char x);

/*FAZ O PARSING* DA EXPRESSÃO ARITMÉTICA PASSADA COMO PARÂMETRO
 *inputs: Árvore a ser preenchida, expressão e posição de início para análise da expressão;
 *outputs: Árvore;
 *pré-condição: os inputs devem existir
 *pós-condição: Árvore de Expressões Aritméticas preenchida
OBS: *Parsing = processo de interpretar uma string contendo uma expressão e a transformar em árvore binária
*/
Arv* Parsing (Arv* a, char* string, int* pos);

/*FAZ O CÁLCULO DA EXPRESSÃO ARITMÉTICA A PARTIR DA ESTRUTURA DA ÁRVORE
 *inputs: Árvore de expressão
 *outputs: valor calculado
 *pré-condição: Árvore deve existir e estar preenchida corretamente com a expressão
 *pós-condição: -
*/
float Calculo (Arv* a);

#endif /* ARVORE_H_ */
