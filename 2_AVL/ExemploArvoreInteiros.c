#include <stdio.h>
#include "ArvoreAVL.h"
#include "Utils.h"

pDArvore constroiArvore(int dados[], int tam){

    pDArvore arvore = criarArvoreAVL();
    int i;
    for(i=0; i<tam; i++){
        incluirInfo(arvore, alocaInt(dados[i]),comparaInt);
        desenhaArvore(arvore, imprimeInt);
    }

    return arvore;
}


pDArvore constroiArvoreEspelho(int dados[], int tam){

    pDArvore arvore = criarArvoreAVL();
    int i;
    for(i=0; i<tam; i++){
        incluirInfoInv(arvore, alocaInt(dados[i]),comparaInt);
        desenhaArvore(arvore, imprimeInt);
    }

    return arvore;
}



int main(){

   int ex0[] = {5, 8, 3, 1};          
   int ex1[] = {5, 8, 3, 7, 6};             // rotacao simples - direita
   int ex2[] = {5, 8, 3, 12, 14};           // rotacao simples - esquerda
   int ex3[] = {5, 10, 3, 7, 8};             // rotacao dupla a direita
   int ex4[] = {5, 10, 3, 4, 12, 9, 14, 13}; // rotacao dupla a esquerda
   int ex5[] = {5, 10, 3, 4, 12, 9, 14, 13, 11};     // duas rotacoes simples

   //constroiArvore(ex1, 5);
   //constroiArvore(ex2, 5);
   //constroiArvore(ex3, 5);
   //constroiArvore(ex4, 8);
   pDArvore arvore1, arvore2, arvoreespelho;
   //arvore1 = constroiArvore(ex1, 5);
   arvore2 = constroiArvore(ex1, 5);
   //printf("Quantidade de NOHS: %d", quantidadeNohsInternos(arvore));

   //printf("SAO IGUAIS: %d", ArvoreIguais(arvore1, arvore2, comparaInt));

   //printf("EH ESTRITO BIARNIO?:%d", estritamenteBinario(arvore2));

   arvoreespelho = constroiArvoreEspelho(ex2, 5);

   //printf("TA BALANCEADO: %d", balanceada(arvore2));

   printf("EH ABB: %d", isABB(arvore2, arvore2->raiz->info, arvore2->raiz->info, comparaInt));

 }
