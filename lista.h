#include<stdio.h>
#include<stdlib.h>

typedef int eleml;

typedef struct bloco {
	eleml info;
	struct bloco *prox;
}no;

typedef struct {
	no *inicio, *fim;
}Lista;


void cria(Lista*);

void inserir(Lista*,eleml*,int*);

void finaliza(Lista*);

int tamanho(Lista*);

int tamanho_rec(no*);

int esta_na_lista(Lista*,eleml*);

int esta_na_lista_rec(no*,eleml*);

void imprimir(Lista*);

//deixar a função "eliminar" para o fim, pois é mais complexa

void eliminar(Lista*,eleml*,int*);

void eliminar_rec(Lista*,no*,no*,eleml*,int*);




