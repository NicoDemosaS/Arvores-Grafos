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
  

   int ex0[] = {5, 8, 3, 1, 2};          
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
   arvore2 = constroiArvore(ex1, 6);
   //printf("Quantidade de NOHS: %d", quantidadeNohsInternos(arvore));

   //printf("SAO IGUAIS: %d", ArvoreIguais(arvore1, arvore2, comparaInt));

   //printf("EH ESTRITO BIARNIO?:%d", estritamenteBinario(arvore2));

   //arvoreespelho = constroiArvoreEspelho(ex2, 5);

   //printf("TA BALANCEADO: %d", balanceada(arvore2));

   //printf("EH ABB: %d", isABB(arvore2, arvore2->raiz->info, arvore2->raiz->info, comparaInt));

    printf("TESTANDO EM ORDEM\n");
    emOrdem(arvore2, imprimeInt);

    printf("\nTESTANDO PRE ORDEM\n");
    preOrdem(arvore2, imprimeInt);

    printf("\nTESTANDO POS ORDEM\n");
    posOrdem(arvore2, imprimeInt);

    // -----------------------------
    // TESTES DE FUNÇÕES IMPLEMENTADAS
    // -----------------------------

    printf("\n\n==== TESTE: buscarInfo ====\n");
    int valorBusca = 7;
    printf("Valor %d %s na árvore\n", valorBusca, buscarInfo(arvore2, &valorBusca, comparaInt) ? "encontrado" : "NÃO encontrado");

    printf("\n==== TESTE: nivel ====\n");
    int valorNivel = 8;
    int nivelValor = nivel(arvore2, &valorNivel, comparaInt);
    if(nivelValor >= 0)
        printf("Nível do valor %d: %d\n", valorNivel, nivelValor);
    else
        printf("Valor %d não encontrado na árvore\n", valorNivel);

    printf("\n==== TESTE: ehFolha ====\n");
    int valorFolha = 8;
    printf("Valor %d %s folha\n", valorFolha, ehFolha(arvore2, &valorFolha, comparaInt) ? "é" : "NÃO é");



    // Outros testes

    printf("\n==== TESTE: umFilho ====\n");
    int qtdUmFilho = filhoUnico(arvore2);
    printf("Quantidade de nós com exatamente um filho: %d\n", qtdUmFilho);

    printf("\n==== TESTE: somenteNivel ====\n");
    int nivelDesejado = 1; // Altere para o nível que deseja testar
    printf("Nós no nível %d: ", nivelDesejado);
    somenteNivel(arvore2, nivelDesejado, imprimeInt);
    printf("\n");


    // -----------------------------
    // FIM DOS TESTES
    // -----------------------------
}
