#ifndef STRUCT_NOH_BTREE_H
#define STRUCT_NOH_BTREE_H

struct nohBTree;

//----------------------------
struct chaveValor{

      void*            chave;
      void*            valor; // dados
      struct nohBTree* filhoMaior;
};

// cada n� da �rvore B possui k chaves e k+1 filhos,
// onde  d <= k <= 2d
//----------------------------
struct nohBTree{
   struct nohBTree  *primeiroFilho;

   // lista com as chaves, valores e filhos "maiores"
   pDLista           listaChavesValores;

   // apontamento para o pai para facilitar a implementa��o das
   // opera��es de particionamento, concatena��o e redistribui��o
   struct nohBTree  *pai;
};

#endif
