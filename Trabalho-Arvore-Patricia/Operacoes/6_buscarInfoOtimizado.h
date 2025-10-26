#ifndef BUSCAR_INFO_OTIMIZADO_PREFIXO_H
#define BUSCAR_INFO_OTIMIZADO_PREFIXO_H

int buscarInfoPrefixoOtimizadoRecursivo (pNohPrefixo raiz, char chave[], int k, int* L)
{
    (*L)++; // incrementa pois iniciou em -1, igual ao original

    // caso base 1 - a chave nao foi encontrada na arvore (noh nao existe)
    if(raiz == NULL){
       return 0;
    }

    // caso base 2 - chegou em um noh terminal (folha com chave)
    if(raiz->terminal == 1){
        // aqui verifica relacoes de prefixo, igual ao buscarInfo original
        
        // se chegou ate o final da chave buscada (*L == k), 
        // significa que a chave eh prefixo de uma chave existente
        if(*L >= k){
            return 1; // a chave buscada eh prefixo
        }
        
        // se nao chegou ate o final (*L < k), mas eh terminal,
        // significa que a chave existente eh prefixo da chave buscada
        if(*L < k){
            return 1; // chave existente eh prefixo da buscada
        }
    }

    // caso recursivo - noh interno (nao terminal)
    // DIFERENCA PRINCIPAL: usa o salto ao inves de testar bit por bit sequencial
    
    // verifica se tem salto valido
    if(raiz->salto != -1){
        // se o salto eh maior ou igual ao tamanho da chave, chave eh muito curta
        if(raiz->salto >= k){
            return 0; // chave nao pode existir nesta subarvore
        }
        
        // atualiza L para a posicao do salto
        *L = raiz->salto;
        
        // testa o bit na posicao do salto para decidir qual caminho seguir
        if (chave[raiz->salto] == '0'){
            // bit eh 0, vai para esquerda
            return buscarInfoPrefixoOtimizadoRecursivo(raiz->esquerda, chave, k , L);
        }
        else {
            // bit eh 1, vai para direita  
            return buscarInfoPrefixoOtimizadoRecursivo(raiz->direita, chave, k , L);
        }
    }
    else {
        // se nao tem salto valido (salto == -1), usa comportamento sequencial como o original
        if (chave[*L] == '0'){
            return buscarInfoPrefixoOtimizadoRecursivo(raiz->esquerda, chave, k , L);
        }
        else {
            return buscarInfoPrefixoOtimizadoRecursivo(raiz->direita, chave, k , L);
        }
    }
}


/* ----------------------------------------------------------*/
int buscarInfoPrefixoOtimizado (pDPrefixo arvore, char chave[], int k)
{
    // verifica se a arvore existe (protecao extra)
    if(!arvore || !arvore->raiz){
        return 0;
    }

    // inicializa L em -1, exatamente igual ao buscarInfo original
    int L=-1;

    // chama a funcao recursiva para buscar a chave na arvore otimizada
    return buscarInfoPrefixoOtimizadoRecursivo(arvore->raiz, chave, k, &L);
}

#endif

