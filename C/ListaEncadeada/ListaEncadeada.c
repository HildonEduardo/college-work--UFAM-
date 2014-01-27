//
//  Fila.c
//  GraphImplementation
//
//  Created by Hildon Lima de Paula on 1/9/13.
//  Copyright (c) 2013 Hildon Lima de Paula. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct no* TNo;
typedef struct lista TLista;

struct no {
	int num;
	struct no* prox;
    
};

struct lista {
    TNo inicio;
    TNo fim;
};
/*Funcoes a sere ultilizadas */
void insere_inicio(TLista* l,int num);
void insere_fim(TLista* l, int num);
void remove_fim(TLista* l);
void removerElem(TLista* l, int num);
int buscaNum(TLista* l,int num);
TLista* criar();

//Procedimentos a serem utilizados
void imprimeLista (TLista* lista);

TLista *criar() {
    TLista* lista = (TLista*)malloc(sizeof(TLista));
    lista->inicio = NULL;
    return lista;
}

void insere_inicio(TLista* l,int num) {
    TNo novo;
    novo = (TNo)malloc(sizeof(struct no));
    novo->num=num;
    novo->prox=l->inicio;
    l->inicio = novo;

}

void insere_fim(TLista* l, int num) {
    TNo novo;
    novo = (TNo) malloc(sizeof(struct no));
    novo->num = num;
    novo->prox = NULL;
    
    if (l->inicio == NULL) {
        l->inicio = novo;
    } else if (l->inicio == l->fim) {
        l->inicio->prox = novo;
    } else {
        l->fim->prox = novo;

    }
    
    l->fim = novo;
}

void removerElem(TLista* l, int num) {
    TNo aux, ant = l->inicio;
    
    if (l == NULL) {
        return;
    } else if (l->inicio->num == num) {
        aux = l->inicio;
        l->inicio = l->inicio->prox;
        free(aux);
        
        return;
    } else if (l->fim->num == num) {
        for (aux = l->inicio->prox; aux != NULL; aux = aux->prox) {
            if (num == aux->prox->num) {
                ant->prox = NULL;
                aux->prox = NULL;
                free(aux);
                l->fim = ant;
                return;
            }
            ant = aux;
        }
    } else {
        for (aux = l->inicio->prox; aux != NULL; aux = aux->prox) {
            if (num == aux->num) {
                ant->prox = aux->prox;
                aux->prox = NULL;
                free(aux);
                return;
            }
            ant = aux;
        }
    }
}

void remove_fim (TLista* l) {
    TNo aux;
    
    if (l == NULL)
        return ;
    
    for (aux = l->inicio;aux!=NULL;aux=aux->prox) {
        
        if (aux->prox->prox==NULL) {
            aux->prox=NULL;
            free(aux->prox);
        }
        
    }
    
}
int buscaNum(TLista* l,int num) {//devolve a posicao;0 a N.
    TNo aux;
    int pos = 0;
    if (l->inicio == NULL) {
        printf("\nLista Vazia!\n");
        return 0;
    }
    for (aux = l->inicio; aux != NULL; aux = aux->prox) {
        if (aux->num == num) {
            return pos;
        }
        pos++;
    }
    
    return -1;
}

void imprimeLista (TLista* lista)
{
	TNo aux;
    
    printf("(");
    for (aux = lista->inicio; aux != NULL; aux = aux->prox)
    {
        
        printf("%d", aux->num);
        if (aux->prox!=NULL) 
            printf(",");
        
    }
    printf(")");  
}
