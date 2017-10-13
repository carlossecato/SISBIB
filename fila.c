//Trabalho 1 - Disciplina: Algoritmos e Estrutura de Dados
//Data: 15/10/2017
//Alberice Lucas de Araújo nUSP 7986563
//Carlos Henrique de Carvalho Secato nUSP 9292890

#include<stdio.h>
#include<stdlib.h>

#include "fila.h"

//cria uma fila F 
void Cria(Fila *F) {
	F->inicio=0;
	F->fim=0;
	F->total=0;

	return;
}

//esvazia uma fila F
void Esvazia(Fila *F) {
	F->inicio=0;
	F->fim=0;
	F->total=0;

	return;
}


//Retorna 1 se a fila estiver vazia, 0 se a fila tiver conteudo
int EstaVazia(Fila *F) {
	if (F->total==0)
		return 1;

	else return 0;
}

//Retorna 1 se a fila estiver cheia, 0 se a fila tiver conteudo ou vazia
int EstaCheia(Fila *F) {
	if (F->total==TamFila)
		return 1;

	else return 0;
}


//Insere o elemento X na fila F. Retorna erro 0 se não houver erro, Retorna erro 1 se algum erro acontecer
void Entra(Fila *F, elem *X, int *erro) {
	if (!EstaCheia(F)) {
		*erro=0;
		F->total++;
		F->itens[F->fim]=*X;

		if (F->fim==TamFila-1) F->fim=0;
		else F->fim++;
	}

	else *erro=1;
	return;
}

//Remove o elemento X da fila F. Retorna erro 0 se não houver erro, Retorna erro 1 se algum erro acontecer
void Sai(Fila *F, elem *X, int *erro) {
	if (!EstaVazia(F)) {
		*erro=0;
		F->total--;
		*X=F->itens[F->inicio];

		if (F->inicio==TamFila-1) F->inicio=0;
		else F->inicio++;
	}

	else *erro=1;
	return;
}


