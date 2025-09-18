#include <stdio.h>
#include "Utils.h"
#include "ArvoreRubroNegra.h"

pDArvore constroiArvore(int dados[], int tam){

    pDArvore arvore = criarArvoreRubroNegra(2);
    int i;
    for(i=0; i<tam; i++){
        incluirInfo(arvore, alocaInt(dados[i]),comparaInt);
    }

    return arvore;
}


int main(){

   int ex1[]   = {5, 10, 3, 4};          // caso 1
   int ex1_1_2[]   = {5, 10, 3, 2};          // caso 1
   int ex1_1[] = {5, 3, 2};              // caso 2.1
   int ex1_2[] = {5, 10, 12};            // caso 2.2
   int ex1_3[] = {5, 3, 4};              // caso 2.3
   int ex2[]   = {5, 10, 3, 2, 12, 11};  // caso 1 e caso 2.3
   int ex3[]   = {5, 10, 3, 2, 7, 8};    // caso 2.2
   int ex4[]   = {5, 10, 3, 2, 14, 12};  // caso 2.4
   int ex5[]   = {8, 3, 21, 16, 27, 9, 18, 29, 10}; // v�rios casos juntos

   //constroiArvore(ex1, 4);
   
   
   
  

    //TESTE FILHO ESQUERDO VERMELHO
   //pDArvore arvore = constroiArvore(ex1, 4);
   //excluirInfo(arvore, alocaInt(3), comparaInt);
   //desenhaArvore(arvore, imprimeInt);

    //TESTE FILHO DIREITO VERMELHO
    pDArvore arvore2 = constroiArvore(ex5, 9);  // Usar ex5 que tem mais elementos
    desenhaArvore(arvore2, imprimeInt);
    
    // TESTE buscarInfo
    printf("\n==== TESTE: buscarInfo ====\n");
    int valorBusca = 8;
    int *ptrBusca = alocaInt(valorBusca);
    pNohArvore resultado = buscarInfo(arvore2, ptrBusca, comparaInt);
    if (resultado && resultado != arvore2->sentinela)
        printf("Valor %d encontrado no endereço %p\n", valorBusca, (void*)resultado);
    else
        printf("Valor %d NÃO encontrado na árvore\n", valorBusca);
    free(ptrBusca);


    // TESTE ancestralComum
    printf("\n==== TESTE: ancestralComum ====\n");
    
    printf("Caso 1: ancestralComum(3, 18) = ");
    int *p1 = alocaInt(3), *p2 = alocaInt(18);
    void *result = ancestralComum(arvore2, p1, p2, comparaInt);
    if (result && result != arvore2->sentinela) {
        printf("%d\n", *(int*)result);
    } else {
        printf("Não encontrado\n");
    }
    free(p1); free(p2);

    // TESTE similares
    printf("\n==== TESTE: similares ====\n");
    
    // Teste 1: Árvores com mesma estrutura (2 nós cada)
    printf("=== TESTE 1: Árvores similares (2 nós) ===\n");
    pDArvore arvore_A = criarArvoreRubroNegra(2);
    incluirInfo(arvore_A, alocaInt(10), comparaInt);
    incluirInfo(arvore_A, alocaInt(5), comparaInt);
    
    pDArvore arvore_B = criarArvoreRubroNegra(2);
    incluirInfo(arvore_B, alocaInt(20), comparaInt);
    incluirInfo(arvore_B, alocaInt(15), comparaInt);
    
    printf("Árvore A: "); desenhaArvore(arvore_A, imprimeInt);
    printf("Árvore B: "); desenhaArvore(arvore_B, imprimeInt);
    printf("A similar a B: %s\n\n", similares(arvore_A, arvore_B) ? "SIM" : "NÃO");
    
    // Teste 2: Árvore vazia vs não vazia
    printf("=== TESTE 2: Vazia vs Não-vazia ===\n");
    pDArvore arvore_vazia = criarArvoreRubroNegra(2);
    printf("Vazia similar a A: %s\n\n", similares(arvore_vazia, arvore_A) ? "SIM" : "NÃO");
    
    // Teste 3: Duas árvores vazias
    printf("=== TESTE 3: Duas vazias ===\n");
    pDArvore arvore_vazia2 = criarArvoreRubroNegra(2);
    printf("Vazia similar a Vazia: %s\n\n", similares(arvore_vazia, arvore_vazia2) ? "SIM" : "NÃO");
    
    // Teste 4: Estruturas diferentes
    printf("=== TESTE 4: Estruturas diferentes ===\n");
    pDArvore arvore_C = criarArvoreRubroNegra(2);
    incluirInfo(arvore_C, alocaInt(30), comparaInt);
    incluirInfo(arvore_C, alocaInt(25), comparaInt);
    incluirInfo(arvore_C, alocaInt(35), comparaInt);  // 3 nós
    
    printf("Árvore C (3 nós): "); desenhaArvore(arvore_C, imprimeInt);
    printf("A (2 nós) similar a C (3 nós): %s\n\n", similares(arvore_A, arvore_C) ? "SIM" : "NÃO");
    
    printf("Testes concluídos!\n");

   
   
   //constroiArvore(ex1_2, 3);
   //constroiArvore(ex1_3, 3);
   //constroiArvore(ex2, 6);
   //constroiArvore(ex3, 6);
   //constroiArvore(ex4, 6);
   //constroiArvore(ex5, 9);
 }

