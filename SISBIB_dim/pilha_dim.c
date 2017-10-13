//Trabalho 1 - Disciplina: Algoritmos e Estrutura de Dados
//Data: 15/10/2017
//Alberice Lucas de Araújo nUSP 7986563
//Carlos Henrique de Carvalho Secato nUSP 9292890


#include <stdio.h> 
#include <stdlib.h>

#include "pilha_dim.h"


// Cria uma pilha P
void Create(Pilha *P){
	P->topo = NULL;
}


//Insere o elemento X na pilha P. Retorna 0 se não houver erro, Retorna 1 se algum erro acontecer
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


//Remove o elemento X da pilha P. Retorna 0 se não houver erro, Retorna 1 se algum erro acontecer
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


//Retorn a 1 se a pilha estiver cheia, 0 se a pilha tiver conteudo ou vazia
int IsFull(Pilha* P){
    return 0;
}


//Retorn a 1 se a pilha estiver vazia, 0 se a pilha tiver conteudo
int IsEmpty(Pilha *P){
	if(P->topo == NULL)
		return 1;
		else return 0;
}


