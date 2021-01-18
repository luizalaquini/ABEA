#define _GNU_SOURCE
#include "arv.h"
#include <string.h>

struct arvore {
    char op; //operador
    int num; //numero/operando - OBS: não haverão números negativos
    Arv* esq; //sae
    Arv* dir; //sad
};

Arv* CriaArv (void) {
    return NULL;
}

Arv* AlocaArv (Arv* a) {
    a = (Arv*) malloc(sizeof(Arv));

    a->op = '\0'; //condição falsa do operador
    a->num = -1; //condição falsa do número
    a->esq = NULL;
    a->dir = NULL;

    return a;
}

void ImprimeArv (Arv* a) {

    if (a){
        ImprimeArv(a->esq);

        if (EhNumero)
            printf(" %d", a->num);
        else if (EhOperador)
            printf(" %c", a->op);

        ImprimeArv(a->dir);
    }
}

Arv* DestroiArv (Arv* a){
    if (a){
        DestroiArv(a->esq);
        DestroiArv(a->dir);
        free(a);
    }
}

int EhNumero (char x){
    if (x >= '0' && x <= '9')
        return 1;
    else
        return 0;
}

int EhOperador (char x){
    if (x == '*' || x == '+' || x == '-' || x == '/')
        return 1;
    else
        return 0;
}

Arv* Parsing (Arv* a, char* string, int* pos){
    //ANALISA STRING CARACTER A CARACTER MONTANDO A ÁRVORE - assumindo que não há erros de sintaxe!

    //1) Se o caracter atual for '(', caminhe para sae. EXCETO SE ESTIVER ANTECEDENDO UM NÚMERO!
    if (*(string + *pos) == '('){
        if ((EhNumero(*(string + *pos + 1) == 1))) //verifica se antecede número
            *pos += 1; //atualiza posição
        else { 
            *pos += 1; //atualiza posição (ignora o parênteses que fecha o número)
            if (a->esq==NULL) //verifica se sae está vazia
                a->esq = AlocaArv(a->esq); //aloca
            a->esq = Parsing(a->esq, string, pos); //caminha pra sae chamando a função recursivamente
        }
    }

    //2) Se o caracter atual for ')', caminhe para o pai do nó. EXECETO SE ESTIVER SUCEDENDO UM NÚMERO!
    if (*(string + *pos) == ')'){
        *pos += 1; //atualiza posição

        return a; //caminha pro nó pai
    }

    //3) Se o caracter atual for um numero, atualize o valor do nó para o número e caminhe para o pai do nó
    if (EhNumero(*(string + *pos))){
        char *num = strtok((string + *pos), ")"); //lê numero (sendo a condição de parada o parênteses fechando)
        a->num = atoi(num); //arvore armazena o número convertido pra inteiro pela função atoi
        int tam = strlen(num) + 1; //calcula tamanho do número
        *pos += tam; //atualiza posição

        return a; //caminha pro nó pai
    }

    //4) Se o caracter atual for um operador ['+','-','/','*'], atualize o valor do nó para o operador e caminhe para sad.
    if (EhOperador(*(string + *pos))){
        a->op = *(string + *pos); //arvore armazena o operador
        *pos += 1; //atualiza posição
        if (a->dir==NULL) //verifica se sad está vazia
            a->dir = AlocaArv(a->dir); //aloca
        a->dir = Parsing(a->dir, string, pos); //caminha pra sad chamando a função recursivamente
    }

    return a;
}

float Calculo (Arv* a){
    float ESQ = 0.0, DIR = 0.0; //variáveis que representam o lado esquerdo e o lado direito de um nó da árvore, respectivamente.

    if (a==NULL) //verifica existencia de conteúdo no nó
        return 0;

    //Se o conteúdo é número:
    if (a->esq==NULL && a->dir==NULL)
        return a->num;
    ESQ = Calculo(a->esq); //calcula à esquerda recursivamente
    DIR = Calculo(a->dir); //calcula à direita recursivamente

    //Se o conteúdo é operador
    if(EhOperador){
        if (a->op == '+')
            ESQ += DIR;
        else if (a->op == '-')
            ESQ -= DIR;
        else if (a->op == '*')
            ESQ *= DIR;
        else if (a->op == '/')
            ESQ /= DIR;
    }
    return ESQ;
}
