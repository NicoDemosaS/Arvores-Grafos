#ifndef NOHS_PRETOS_ARVORE_H
#define NOHS_PRETOS_ARVORE_H

// Função auxiliar recursiva que conta nós pretos e verifica se todos caminhos têm a mesma quantidade
int verificaCaminhosRecursivo(pNohArvore raiz, pNohArvore sentinela, int contadorPreto) {
    // Se chegou na sentinela, este é o fim de um caminho
    if (raiz == sentinela) {
        return contadorPreto; // retorna quantidade de pretos neste caminho
    }
    
    // Se é nó preto, incrementa contador
    if (raiz->cor == 'B') {
        contadorPreto++;
    }
    
    // Verifica caminhos da esquerda e direita
    int pretosEsquerda = verificaCaminhosRecursivo(raiz->esquerda, sentinela, contadorPreto);
    int pretosDireita = verificaCaminhosRecursivo(raiz->direita, sentinela, contadorPreto);
    
    // Se algum caminho deu erro ou se caminhos têm quantidades diferentes → inválida
    if (pretosEsquerda == -1 || pretosDireita == -1 || pretosEsquerda != pretosDireita) {
        return -1; // código de erro
    }
    
    return pretosEsquerda;
}

// Função principal que verifica se todos os caminhos têm a mesma quantidade de nós pretos
int nohsPretos(pDArvore arvore) {
    if (arvore == 0 || arvore->raiz == arvore->sentinela) {
        return 1; // árvore vazia é válida
    }
    
    int resultado = verificaCaminhosRecursivo(arvore->raiz, arvore->sentinela, 0);
    return (resultado != -1); // retorna 1 se válida, 0 se inválida
}

#endif
