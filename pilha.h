#include<stdio.h>
#include<stdlib.h>

#define TamPilha 100



typedef struct {
        char nome[50];
        char nusp[10];
        char tel[10];
        char email[30];
	char mensagem[100];
}elemp;


typedef struct {
		int topo;
		elemp itens[TamPilha];
} Pilha;



// Cria uma pilha P
void Create(Pilha *);

// Esvazia uma pilha P
void Empty(Pilha *);

//Insere o elemento X na pilha P. Retorna 0 se não houver erro, Retorna 1 se algum erro acontecer
int Push(Pilha *, elemp*);

//Remove o elemento X da pilha P. Retorna 0 se não houver erro, Retorna 1 se algum erro acontecer
int Pop(Pilha *, elemp *);

//Retorn a 1 se a pilha estiver vazia, 0 se a pilha tiver conteudo
int IsEmpty(Pilha *P);

//Retorn a 1 se a pilha estiver cheia, 0 se a pilha tiver conteudo ou vazia
int IsFull(Pilha *P);
