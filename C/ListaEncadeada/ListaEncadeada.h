//
//  ListaEncadeada.h
//  GraphImplementation
//
//  Created by Hildon Lima de Paula on 1/9/13.
//  Copyright (c) 2013 Hildon Lima de Paula. All rights reserved.
//

#ifndef GraphImplementation_ListaEncadeada_h
#define GraphImplementation_ListaEncadeada_h

typedef struct no* TNo;
typedef struct lista TLista;

void insere_inicio(TLista* l,int num);
void insere_fim(TLista* l, int num);
void remove_fim(TLista* l);
void removerElem(TLista* l, int num);
int buscaNum(TLista* l,int num);
TLista* criar();

//Procedimentos a serem utilizados
void imprimeLista (TLista* lista);


#endif
