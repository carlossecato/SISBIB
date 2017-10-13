//Trabalho 1 - Disciplina: Algoritmos e Estrutura de Dados
//Data: 15/10/2017
//Alberice Lucas de Araújo nUSP 7986563
//Carlos Henrique de Carvalho Secato nUSP 9292890

#include<stdio.h>
#include<stdlib.h>

#define TamFila 100


typedef struct {
	char nome[50];
	char nusp[10];
	char tel[10];
	char email[30];
}elem;

typedef struct bloco {
	struct bloco *prox;
	elem info;
}no;

typedef struct{
	no *inicio, *fim;
}Fila;


//operações básicas

void Cria(Fila*);

void Esvazia(Fila*);

int EstaVazia(Fila*);

int EstaCheia(Fila*);

void Entra(Fila*, elem*, int*);

void Sai(Fila*, elem*, int*);

elem cadastra(Fila*);

//outras operações mais sofisticadas
/*
   int Crescente(Fila*);

   elem Primeiro(Fila*, int*);

   void Unir(Fila*, Fila*, Fila*, int*);
 */
