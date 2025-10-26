#ifndef STRUCT_ARVORE_H
#define STRUCT_ARVORE_H

struct nohPrefixo{
   int                terminal;
   char*              chave;
   int                salto;
   struct nohPrefixo* esquerda;
   struct nohPrefixo* direita;
};

#endif
