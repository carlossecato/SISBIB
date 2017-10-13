//Trabalho 1 - Disciplina: Algoritmos e Estrutura de Dados
//Data: 15/10/2017
//Alberice Lucas de Araújo nUSP 7986563
//Carlos Henrique de Carvalho Secato nUSP 9292890


#include<stdio.h>
#include<stdlib.h>

typedef struct {
        char nome[50];
        char nusp[10];
        char tel[10];
        char email[30];
	char mensagem[100];
}elemp;

typedef struct bloco2{
	elemp info;
	struct bloco2 *prox;
}noPilha;

typedef struct pilha {
	noPilha  *topo;

}Pilha;



void Create(Pilha *);

void Empty(Pilha* pi);

int Push(Pilha *, elemp*);

int Pop(Pilha *, elemp *);

int IsEmpty(Pilha *P);

int IsFull(Pilha *P);


