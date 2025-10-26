#ifndef INCLUIR_INFO_PREFIXO_H
#define INCLUIR_INFO_PREFIXO_H


int buscarInfoPrefixo (pDPrefixo, char [], int);

/* --------------------------*/
pNohPrefixo incluirInfoPrefixoRecursivo(pNohPrefixo raiz, pDPrefixo arvore, char chave[], int k, int* L){

  pNohPrefixo novo;

  (*L)++;

  // caso base - todos os d�gitos foram colocados na �rvore
   if (*L == k){
    novo = criarNohPrefixo(1);   // cria um terminal
    novo->chave = strdup(chave); // guarda copia da chave
    novo->salto = -1;
    if (arvore) arvore->quantidadeNohs++;
    return novo;
   }

   if (raiz == NULL){
     // cria um novo n�h interno para acomodar o pr�ximo d�gito da chave
     novo = criarNohPrefixo(0);
     novo->chave = NULL;
     novo->salto = -1;
     novo->esquerda = novo->direita = NULL;
       if (chave[*L] == '0'){
       // pr�ximo s�mbolo da chave, pois L come�ou com ZERO
          novo->esquerda = incluirInfoPrefixoRecursivo(novo->esquerda, arvore, chave, k, L);
    }
    else {
      novo->direita = incluirInfoPrefixoRecursivo(novo->direita, arvore, chave, k, L);
    }

     if (arvore) arvore->quantidadeNohs++;
     return novo;
  }

  // caso recursivo
   if (chave[*L] == '0'){
       raiz->esquerda = incluirInfoPrefixoRecursivo(raiz->esquerda, arvore, chave, k, L);
   }
   else{
      raiz->direita = incluirInfoPrefixoRecursivo(raiz->direita, arvore, chave, k, L);
   }

  return raiz;

}

/* ----------------------------------------------------------*/
int incluirInfoPrefixo (pDPrefixo arvore, char chave[], int k){

   int L=-1;

   printf("\n Buscando a chave: %s", chave);
   int r = buscarInfoPrefixo(arvore, chave, k);  // verifica tamb�m se � prefixo

   printf("\n Achou chave ou prefixo= %d \n", r);
   if (r == 0){
      // a raiz da �rvore n�o deve ser alterada devido a uma inclus�o
      arvore->raiz = incluirInfoPrefixoRecursivo(arvore->raiz, arvore, chave, k, &L);
      return 1;
   }

   return 0;
}

#endif

