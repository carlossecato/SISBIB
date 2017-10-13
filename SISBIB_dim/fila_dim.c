//Trabalho 1 - Disciplina: Algoritmos e Estrutura de Dados
//Data: 15/10/2017
//Alberice Lucas de Araújo nUSP 7986563
//Carlos Henrique de Carvalho Secato nUSP 9292890

#include<stdio.h>
#include<stdlib.h>

#include "fila_dim.h"

//cria uma fila F 
void Cria(Fila *F) {
	F->inicio = NULL;
	F->fim = NULL;
}


//esvazia uma fila F
void Esvazia(Fila *F) {
	F->inicio = NULL;
	F->fim = NULL;
}


//Retorna 1 se a fila estiver vazia, 0 se a fila tiver conteudo
int EstaVazia(Fila *F) {
	if(F->inicio == NULL)
		return 1;
		else return 0;
}


//Retorna 1 se a fila estiver cheia, 0 se a fila tiver conteudo ou vazia
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


//Insere o elemento X na fila F. Retorna erro 0 se não houver erro, Retorna erro 1 se algum erro acontecer
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


//Remove o elemento X da fila F. Retorna erro 0 se não houver erro, Retorna erro 1 se algum erro acontecer
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



