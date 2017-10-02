//Carlos Henrique de Carvalho Secato nUSP 9292890

#include<stdio.h>
#include<stdlib.h>

#include "fila_dim.h"


void Cria(Fila *F) {
	F->inicio = NULL;
	F->fim = NULL;
}


void Esvazia(Fila *F) {
	F->inicio = NULL;
	F->fim = NULL;
}



int EstaVazia(Fila *F) {
	if(F->inicio == NULL)
		return 1;
		else return 0;
}


int EstaCheia(Fila *F) {
	no *p;

	p=(no*)malloc(sizeof(no));
	if(p==NULL)
		return 1;
		else {
			free(p);
			return 0;
		}
}



void Entra(Fila *F, elem *X, int *erro) {
	no *p;

	p = (no*)malloc(sizeof(no));
	if(p==NULL)
		*erro = 1;
		else {
			*erro = 0;
			p->info = *X;
			p->prox = NULL;
			if(F->inicio == NULL)
				F->inicio = p;
				else F->fim->prox = p;
			F->fim = p;	
		}
}


void Sai(Fila *F, elem *X, int *erro) {
	no *p;
	
	if(EstaVazia(F))
		*erro = 1;
		else {
			*erro = 0;
			*X = F->inicio->info;
			p = F->inicio;
			F->inicio = F->inicio->prox;
			if(F->inicio == NULL)
				F->fim=NULL;
			free(p);
		}	
}


