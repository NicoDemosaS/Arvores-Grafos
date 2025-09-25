#ifndef STRUCT_NOH_BTREE_H
#define STRUCT_NOH_BTREE_H

struct nohBTree;

//----------------------------
struct chaveValor{

      void*            chave;
      void*            valor; // dados
      struct nohBTree* filhoMaior;
};

// cada nó da árvore B possui k chaves e k+1 filhos,
// onde  d <= k <= 2d
//----------------------------
struct nohBTree{
   struct nohBTree  *primeiroFilho;

   // lista com as chaves, valores e filhos "maiores"
   pDLista           listaChavesValores;

   // apontamento para o pai para facilitar a implementação das
   // operações de particionamento, concatenação e redistribuição
   struct nohBTree  *pai;
};

#endif
