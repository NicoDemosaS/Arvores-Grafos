#ifndef OTIMIZARARVORE_ARVORE_BINARIA_H
#define OTIMIZARARVORE_ARVORE_BINARIA_H

// Implementacao > o arvore complicada em
// Nicolas Gabriel Brunismann


/* --------------------------*/
pNohPrefixo otimizarArvoreRecursivo(pNohPrefixo raiz, pDPrefixo arvore){

    //caso base para nao tentar acessar outros itens dentro de uma raiz que nao existe
    //evita segmentation fault
    if(raiz == NULL){
        return NULL;
    }

    // procura recursivamente a folha na esquerda e na direita
    // e adiciona ela como filho enxugando a arvore
    raiz->esquerda = otimizarArvoreRecursivo(raiz->esquerda, arvore);
    raiz->direita  = otimizarArvoreRecursivo(raiz->direita, arvore);

    //caso seja folha, nao otimizar
    if(raiz->terminal == 1){
        return raiz;
    }
    //caso em que nao ha nenhum filho
    if(raiz->direita == NULL && raiz->esquerda == NULL){
        free(raiz);
        if(arvore){
            arvore->quantidadeNohs--;
        }
        return NULL;
    }

    // caso em que pode ser otimizado
    //aonde o noh nao eh terminal e somente um dos filhos eh NULL
    if((raiz->esquerda == NULL && raiz->direita != NULL)
    || (raiz->esquerda != NULL && raiz->direita == NULL)){
        //implementacao da otimizacao do noh 
        // promove o filho não-nulo, aqui essa linha 41, verifica se tem filho direita, ou esquerda, e promove o filho que existir.
        pNohPrefixo filho = (raiz->esquerda != NULL) ? raiz->esquerda : raiz->direita;
        /* --
            faz o mesmo que:
            if(raiz->esquerda != NULL)
                pNohPrefixo filho = raiz->esquerda
            else
                pNohPrefixo filho = raiz->direita
        */

        // libera o nó atual
        free(raiz);

        // verifica se existe arvore, atualiza contador
        if (arvore){
            arvore->quantidadeNohs--;
        } 

        // retorna o filho para o pai conectar
        return filho;
    }
    
    // Para nohs que permanecem (com 2 filhos ou terminais): 
    // recalcula salto usando folhas representantes de cada subárvore
    if (raiz->esquerda != NULL && raiz->direita != NULL){
        // encontrar representante à esquerda (primeiro terminal)
        pNohPrefixo repEsq = raiz->esquerda;
        while (repEsq && repEsq->terminal == 0){
            if (repEsq->esquerda) repEsq = repEsq->esquerda;
            else if (repEsq->direita) repEsq = repEsq->direita;
            else { repEsq = NULL; break; } // subárvore inconsistente 
        }
        // encontrar representante a direita (primeiro terminal)
        pNohPrefixo repDir = raiz->direita;
        while (repDir && repDir->terminal == 0){
            if (repDir->esquerda) repDir = repDir->esquerda;
            else if (repDir->direita) repDir = repDir->direita;
            else { repDir = NULL; break; }
        }

        if (repEsq && repDir && repEsq->chave && repDir->chave){
            const char *a = repEsq->chave;
            const char *b = repDir->chave;
            
            int la = (int)strlen(a); // tamanho da chave da esquerda
            int lb = (int)strlen(b); // tamanho da chave da direita
            int min_len = la < lb ? la : lb; // pega o menor tamanho entre la e lb
            int posicao_diferenca = min_len; // assume que diferem no final, eh fallback!
            
            // encontra primeira posição onde diferem
            for (int i = 0; i < min_len; ++i){
                int ba = (a[i] == '1') ? 1 : 0; // ba recebe 1, se a[i] for 1, se nao recebe 0
                int bb = (b[i] == '1') ? 1 : 0; // bb recebe 1, se b[i] for 1, se nao recebe 0
                if (ba != bb){ 
                    posicao_diferenca = i; //encontrou a diferenca comparando as chaves
                    break; 
                }
            }
            
            // Em Patricia trie, salto = posição onde deve testar o próximo bit
            // Se diferem na posição i, o salto deve ser i (testa bit i)
            raiz->salto = posicao_diferenca;
        } else {
            raiz->salto = 0; // valor padrão mais seguro
        }
    }

    return raiz;
}

/* ----------------------------------------------------------*/
int otimizarArvore(pDPrefixo arvore){
    if(!arvore) return 0; // aqui confirma se a arvore existe, evitando seg fault
    //isso aqui evita que a raiz original seja otimizada e fique apontando para um free;
    arvore->raiz = otimizarArvoreRecursivo(arvore->raiz, arvore);
    return 1;

}

#endif
