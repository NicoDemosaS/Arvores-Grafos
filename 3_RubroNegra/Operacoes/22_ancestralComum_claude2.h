#ifndef ancestralComum_ARVORE_BINARIA_H
#define ancestralComum_ARVORE_BINARIA_H

#include "9_nivel.h"
#include "4_buscarInfo.h"

    void* ancestralComumRecursivo(pDArvore arvore, void* info1, void* info2,
    FuncaoComparacao pfc){
        printf("DEBUG: Entrando em ancestralComumRecursivo\n");
        
        if(arvore->raiz == arvore->sentinela)
            return arvore->sentinela;
         
        printf("DEBUG: Buscando u...\n");
        pNohArvore u = buscarInfoRecursivo(arvore->raiz, arvore->sentinela, info1, pfc);
        printf("DEBUG: u encontrado: %p\n", (void*)u);
        
        printf("DEBUG: Buscando v...\n");
        pNohArvore v = buscarInfoRecursivo(arvore->raiz, arvore->sentinela, info2, pfc);
        printf("DEBUG: v encontrado: %p\n", (void*)v);

        if(u == arvore->sentinela || v == arvore->sentinela) {
            printf("DEBUG: Um dos valores não foi encontrado!\n");
            return arvore->sentinela; // nao encontrou um dos valores
        }

        printf("DEBUG: Calculando níveis...\n");
        int nivel_u = nivel(arvore, u->info, pfc);
        int nivel_v = nivel(arvore, v->info, pfc);
        printf("DEBUG: nivel_u = %d, nivel_v = %d\n", nivel_u, nivel_v);

        // Verificar se um é ancestral do outro
        printf("DEBUG: Verificando se um é ancestral do outro...\n");
        
        // Se u tem nível menor (mais próximo da raiz), verificar se u é ancestral de v
        if (nivel_u < nivel_v) {
            pNohArvore temp = v;
            int diff = nivel_v - nivel_u;
            printf("DEBUG: u pode ser ancestral de v, subindo v %d níveis...\n", diff);
            
            for (int i = 0; i < diff && temp != arvore->sentinela; i++) {
                temp = temp->pai;
                printf("DEBUG: Subindo v: temp = %p\n", (void*)temp);
            }
            
            if (temp == u) {
                printf("DEBUG: u é ancestral de v!\n");
                return u->info;
            }
        }
        // Se v tem nível menor, verificar se v é ancestral de u
        else if (nivel_v < nivel_u) {
            pNohArvore temp = u;
            int diff = nivel_u - nivel_v;
            printf("DEBUG: v pode ser ancestral de u, subindo u %d níveis...\n", diff);
            
            for (int i = 0; i < diff && temp != arvore->sentinela; i++) {
                temp = temp->pai;
                printf("DEBUG: Subindo u: temp = %p\n", (void*)temp);
            }
            
            if (temp == v) {
                printf("DEBUG: v é ancestral de u!\n");
                return v->info;
            }
        }

        printf("DEBUG: Igualando profundidades...\n");
        printf("DEBUG: Antes da equalização - u: %p (nivel %d), v: %p (nivel %d)\n", 
               (void*)u, nivel_u, (void*)v, nivel_v);
        
        // Igualar profundidades - subir o nó mais profundo
        while(nivel_u > nivel_v) {
            printf("DEBUG: Subindo u (nivel %d, pai = %p)\n", nivel_u, (void*)u->pai);
            u = u->pai;
            if (u == arvore->sentinela) {
                printf("DEBUG: u chegou na sentinela durante equalização\n");
                return NULL;
            }
            nivel_u--;
        }
        while(nivel_v > nivel_u) {
            printf("DEBUG: Subindo v (nivel %d, pai = %p)\n", nivel_v, (void*)v->pai);
            v = v->pai;
            if (v == arvore->sentinela) {
                printf("DEBUG: v chegou na sentinela durante equalização\n");
                return NULL;
            }
            nivel_v--;
        }
        
        printf("DEBUG: Após equalização - u: %p (nivel %d), v: %p (nivel %d)\n", 
               (void*)u, nivel_u, (void*)v, nivel_v);

        printf("DEBUG: Buscando ancestral comum...\n");
        while(u != v && u != arvore->sentinela && v != arvore->sentinela && u != NULL && v != NULL){ // procura o ancestral.
            printf("DEBUG: u = %p, v = %p\n", (void*)u, (void*)v);
            
            // Verificar se os pais são válidos
            printf("DEBUG: u->pai = %p, v->pai = %p, sentinela = %p\n", 
                   (void*)u->pai, (void*)v->pai, (void*)arvore->sentinela);
            
            // Se chegamos na raiz (pai NULL ou sentinela), paramos
            if (u->pai == NULL || v->pai == NULL || 
                u->pai == arvore->sentinela || v->pai == arvore->sentinela) {
                printf("DEBUG: Um dos pais é NULL ou sentinela, parando busca\n");
                
                // Se ambos chegaram na raiz, eles podem ser iguais
                if ((u->pai == NULL || u->pai == arvore->sentinela) && 
                    (v->pai == NULL || v->pai == arvore->sentinela)) {
                    // Se são o mesmo nó, este é o ancestral comum
                    if (u == v) {
                        printf("DEBUG: Ambos são o mesmo nó: ancestral comum encontrado\n");
                        return u->info;
                    }
                    // Se são diferentes mas ambos na raiz, não há ancestral comum
                    printf("DEBUG: Ambos na raiz mas são diferentes - não há ancestral comum\n");
                    return NULL;
                }
                
                // Se apenas um chegou na raiz, o outro pode ser o ancestral
                if (u->pai == NULL || u->pai == arvore->sentinela) {
                    printf("DEBUG: u chegou na raiz, u pode ser ancestral de v\n");
                    return u->info;
                }
                if (v->pai == NULL || v->pai == arvore->sentinela) {
                    printf("DEBUG: v chegou na raiz, v pode ser ancestral de u\n");
                    return v->info;
                }
                
                break;
            }
            
            u = u->pai;
            v = v->pai;
        }
        
        // Se encontramos o ancestral comum
        if (u == v && u != arvore->sentinela && u != NULL) {
            printf("DEBUG: Ancestral comum encontrado: %p\n", (void*)u);
            return u->info;
        }
        
        printf("DEBUG: Não foi possível encontrar ancestral comum válido\n");
        return NULL;
        return u->info;
    }


    void* ancestralComum(pDArvore arvore, void* info1, void* info2,
    FuncaoComparacao pfc){
        return ancestralComumRecursivo(arvore, info1, info2, pfc);

}

#endif







