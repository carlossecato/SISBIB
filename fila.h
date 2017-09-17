#include<stdio.h>
#include<stdlib.h>

#define TamFila 100


typedef struct {
	char nome[50];
	char nusp[10];
	char tel[10];
	char email[30];
}elem;

typedef struct {
			int inicio, fim, total;
			elem itens[TamFila];
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
