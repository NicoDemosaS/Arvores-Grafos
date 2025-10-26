#include <stdio.h>
#include <strings.h>
#include "Utils.h"
#include "ArvorePrefixo.h"

//=========================================================
pDPrefixo constroiArvorePrefixo(char* chaves[], int tam){

    pDPrefixo arvore = criarArvorePrefixo();
    int i, r;
    for(i=0; i<tam; i++){
        r = incluirInfoPrefixo(arvore, chaves[i], strlen(chaves[i]));
        if (r == 0)
            printf("\n Erro na inclus�o da chave [%s] - j� existe ou � prefixo de outra chave!", chaves[i]);

        desenhaArvorePrefixo(arvore);}

    //desenhaArvorePrefixo(arvore);
    return arvore;
}

//-------------------------------------------------------
int main(){

    char* ex1[] = {"001100", "01",  "001101", "1010", "11"};
    char* ex2[] = {"100101", "101", "001101", "101011", "11"};

    constroiArvorePrefixo(ex1, 5);
    //constroiArvorePrefixo(ex2, 5);


}
