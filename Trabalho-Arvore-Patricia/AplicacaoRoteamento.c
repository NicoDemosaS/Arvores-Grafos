#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include "Utils.h"
#include "ArvorePrefixo.h"

//=========================================================
// Estrutura simples para roteador
typedef struct {
    char nome[10];
    pDPrefixo tabela;
} Roteador;

//=========================================================
// Funcao simples: pega o primeiro numero do IP e converte pra binario
void ipParaBinario(char* ip, char* binario) {
    int primeiro_octeto;
    sscanf(ip, "%d", &primeiro_octeto); // Pega só o primeiro número
    
    // Converte pra binário bit por bit (método simples)
    for(int i = 5; i >= 0; i--) { // Só 6 bits pra ficar simples
        if(primeiro_octeto >= (1 << i)) {
            binario[5-i] = '1';
            primeiro_octeto -= (1 << i);
        } else {
            binario[5-i] = '0';
        }
    }
    binario[6] = '\0'; // Termina a string
}

//=========================================================
// Cria roteador simples
Roteador* criarRoteadorSimples(char* nome, char* redes[], int numRedes) {
    Roteador* router = malloc(sizeof(Roteador));
    strcpy(router->nome, nome);
    router->tabela = criarArvorePrefixo();
    
    printf("\n=== ROTEADOR %s ===\n", nome);
    
    for(int i = 0; i < numRedes; i++) { // 
        char prefixo[7]; // 6 bits + terminador
        ipParaBinario(redes[i], prefixo);
        
        int ok = incluirInfoPrefixo(router->tabela, prefixo, 6);
        if(ok) {
            printf("Rede %s -> %s adicionada\n", redes[i], prefixo);
        }
    }
    
    // Otimiza
    int antes = router->tabela->quantidadeNohs;
    otimizarArvore(router->tabela);
    printf("Otimizado: %d -> %d nos\n", antes, router->tabela->quantidadeNohs);
    
    return router;
}

//=========================================================
// Testa se um IP pode ser roteado por um roteador
void testarRoteamento(Roteador* router, char* ip) {
    char binario[7];
    ipParaBinario(ip, binario);
    
    int encontrou = buscarInfoPrefixoOtimizado(router->tabela, binario, 6);
    
    printf("%s roteia %s (%s): %s\n", 
           router->nome, ip, binario, 
           encontrou ? "SIM" : "NAO");
}

//=========================================================
int main() {
    printf("=== SIMULACAO SIMPLES DE ROTEAMENTO ===\n");
    
    // Roteador A - redes 192.x.x.x e 10.x.x.x
    char* redesA[] = {"192.0.0.0", "10.0.0.0"};
    Roteador* routerA = criarRoteadorSimples("RouterA", redesA, 2);
    
    // Roteador B - redes 172.x.x.x e 203.x.x.x  
    char* redesB[] = {"172.0.0.0", "203.0.0.0"};
    Roteador* routerB = criarRoteadorSimples("RouterB", redesB, 2);
    
    printf("\n=== TESTES DE ROTEAMENTO ===\n");
    
    // IPs para testar
    char* ips[] = {"192.168.1.1", "10.0.1.1", "172.16.1.1", "8.8.8.8"};
    
    for(int i = 0; i < 4; i++) {
        printf("\nTestando IP: %s\n", ips[i]);
        testarRoteamento(routerA, ips[i]);
        testarRoteamento(routerB, ips[i]);
    }
    
    printf("\n=== TABELAS OTIMIZADAS ===\n");
    printf("\nTabela RouterA:\n");
    desenhaArvorePrefixo(routerA->tabela);
    
    printf("\nTabela RouterB:\n");
    desenhaArvorePrefixo(routerB->tabela);
    
    free(routerA);
    free(routerB);
    return 0;
}
