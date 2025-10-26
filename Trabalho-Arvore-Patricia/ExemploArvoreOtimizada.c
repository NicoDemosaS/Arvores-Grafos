#include <stdio.h>
#include <strings.h>
#include "Utils.h"
#include "ArvorePrefixo.h"

//=========================================================
pDPrefixo constroiArvorePrefixo(char* chaves[], int tam){

    pDPrefixo arvore = criarArvorePrefixo();
    int i, r;
    printf("\n=== CONSTRUINDO ARVORE ===\n");
    for(i=0; i<tam; i++){
        printf("Incluindo chave: %s\n", chaves[i]);
        r = incluirInfoPrefixo(arvore, chaves[i], strlen(chaves[i]));
        if (r == 0)
            printf("ERRO na inclusao da chave [%s] - ja existe ou eh prefixo de outra chave!", chaves[i]);
        else
            printf("Chave [%s] incluida com sucesso!\n", chaves[i]);
    }

    printf("\n=== ARVORE ORIGINAL ===\n");
    desenhaArvorePrefixo(arvore);
    return arvore;
}

//=========================================================
void testaArvoreOtimizada(char* chaves[], int tam) {
    
    // 1. Constroi arvore original
    pDPrefixo arvore = constroiArvorePrefixo(chaves, tam);
    
    printf("\n=== TESTANDO BUSCA NA ARVORE ORIGINAL ===\n");
    // Testa busca na arvore original
    char* chavesTeste[] = {"001100", "01", "1010", "10", "001", "111", "00110"};
    int numTestes = 7;
    
    for(int i = 0; i < numTestes; i++){
        int resultado = buscarInfoPrefixo(arvore, chavesTeste[i], strlen(chavesTeste[i]));
        printf("Busca '%s' na arvore original: %s\n", 
               chavesTeste[i], resultado ? "ENCONTRADO" : "NAO ENCONTRADO");
    }
    
    // 2. Otimiza a arvore
    printf("\n=== OTIMIZANDO ARVORE ===\n");
    printf("Nos antes da otimizacao: %d\n", arvore->quantidadeNohs);
    
    int resultadoOtimizacao = otimizarArvore(arvore);
    if(resultadoOtimizacao){
        printf("Arvore otimizada com sucesso!\n");
        printf("Nos apos a otimizacao: %d\n", arvore->quantidadeNohs);
    } else {
        printf("ERRO ao otimizar arvore!\n");
        return;
    }
    
    printf("\n=== ARVORE OTIMIZADA ===\n");
    desenhaArvorePrefixo(arvore);
    
    // 3. Testa busca na arvore otimizada
    printf("\n=== TESTANDO BUSCA NA ARVORE OTIMIZADA ===\n");
    
    for(int i = 0; i < numTestes; i++){
        int resultado = buscarInfoPrefixoOtimizado(arvore, chavesTeste[i], strlen(chavesTeste[i]));
        printf("Busca '%s' na arvore otimizada: %s\n", 
               chavesTeste[i], resultado ? "ENCONTRADO" : "NAO ENCONTRADO");
    }
    
    // 4. Compara resultados (opcional)
    printf("\n=== COMPARACAO DE RESULTADOS ===\n");
    printf("Testando se busca original e otimizada dao mesmo resultado...\n");
    
    // Para comparar, criamos uma nova arvore original
    pDPrefixo arvoreOriginal = constroiArvorePrefixo(chaves, tam);
    
    for(int i = 0; i < numTestes; i++){
        int resultOriginal = buscarInfoPrefixo(arvoreOriginal, chavesTeste[i], strlen(chavesTeste[i]));
        int resultOtimizado = buscarInfoPrefixoOtimizado(arvore, chavesTeste[i], strlen(chavesTeste[i]));
        
        if(resultOriginal == resultOtimizado){
            printf("Chave '%s': OK (Original=%d, Otimizado=%d)\n", 
                   chavesTeste[i], resultOriginal, resultOtimizado);
        } else {
            printf("DIFERENCA na chave '%s': Original=%d, Otimizado=%d\n", 
                   chavesTeste[i], resultOriginal, resultOtimizado);
        }
    }
}

//-------------------------------------------------------
int main(){

    printf("=== TESTE DE ARVORE PATRICIA OTIMIZADA ===\n\n");

    // Exemplo 1 - conjunto de chaves para testar
    char* ex1[] = {"001100", "01", "001101", "1010", "11"};
    printf("EXEMPLO 1 - Chaves: 001100, 01, 001101, 1010, 11\n");
    testaArvoreOtimizada(ex1, 5);
    
    printf("\n==================================================\n\n");
    
    // Exemplo 2 - outro conjunto de chaves
    char* ex2[] = {"100101", "101", "001101", "101011", "11"};
    printf("EXEMPLO 2 - Chaves: 100101, 101, 001101, 101011, 11\n");
    testaArvoreOtimizada(ex2, 5);

    return 0;
}
