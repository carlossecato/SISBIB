//Carlos Henrique de Carvalho Secato nUSP 9292890

#include <stdio.h> 
#include <stdlib.h>

#include "pilha_dim.h"

void Create(Pilha *P){
	P->topo = NULL;
}

int Push(Pilha* P, elemp *X){
	noPilha *pont;

		  
	pont = (noPilha*)malloc(sizeof(noPilha));
	if(pont==NULL)
		return 1;
		else {
			pont->info = *X;
			pont->prox = P->topo;
			P->topo = pont;
			return 0;			
		}
}

int Pop(Pilha *P, elemp *X){
	noPilha *pont;
	
	if(IsEmpty(P))
		return 1;
		else {
			
			*X = P->topo->info;
			pont = P->topo;
			P->topo = P->topo->prox;
			free(pont);
			return 0;
		}
}

int IsFull(Pilha* P){
    return 0;
}

int IsEmpty(Pilha *P){
	if(P->topo == NULL)
		return 1;
		else return 0;
}


