#include<stdio.h>
#include<stdlib.h>
#include "lista.h"


void cria(Lista *L){
	L->inicio = NULL;
	L->fim = NULL;
}

void inserir(Lista *L, eleml *X, int *erro){
	no *p;

	p = (no*) malloc(sizeof(no));
	if(p==NULL) {
	*erro = 1;
	return;
	}
	else *erro = 0;
	p->info = *X;
	p->prox = NULL;
	if(L->inicio == NULL)
	L->inicio = p;
	else L->fim->prox = p;
	L->fim = p;
}

void finaliza(Lista *L){
	no *p;
	p = L->inicio;
	while (p!=NULL){
		L->inicio = L->inicio->prox;
		free(p);
		p = L->inicio;
	}
	L->fim = NULL;
}

int tamanho(Lista *L){
	no *p;
	int contador = 0;
	p = L->inicio;
	while(p!=NULL){
		contador++;
		p = p->prox;
	}
	return (contador);
}

int tamanho_rec(no *p){
	if (p==NULL)
	return (0);
	else return (1+tamanho_rec(p->prox));
}

int esta_na_lista(Lista *L, eleml *X){
	no *p;
	p = L->inicio;
	while((p!=NULL) && (p->info!=*X)){
		p = p->prox;
	}
	if(p!=NULL) return(1);
	else return (0);
}

int esta_na_lista_rec(no *p, eleml *x){
	if(p==NULL)
	return (0);
	else if(p->info == *x)
	return 1;
	else return(esta_na_lista_rec(p->prox,x));
}

void imprimir(Lista *L){
	no *p;
	p = L->inicio;
	while(p!=NULL){
		printf("%c", p->info);
		p = p->prox;
	}
	printf("\n\n");
	return;
}

void eliminar(Lista *L, eleml *X, int *erro){
	no *p, *anterior;
	int teste = 0;
	
	p = L->inicio;
	while((p!=NULL) && (!teste)){
		if(p->info !=*X) {
		anterior = p;
		p = p->prox;
	}
	else{
	if(p==L->inicio){
		L->inicio = L->inicio->prox;
		if(L->inicio = NULL) L->fim = NULL;
	}
	else if(p==L->fim){
		L->fim = anterior;
		L->fim->prox = NULL;
	}
	else anterior->prox = p->prox;
	free (p);
	teste = 1;
}
}
	*erro = !teste;
	return;
}


void eliminar_rec(Lista *L, no* anterior, no *atual, eleml *x, int *erro){
	if(atual == NULL)
		*erro = 1;
	else if(atual->info == *x) {
		if(atual == L->inicio) {
		L->inicio = L->inicio->prox;
			if(L->inicio == NULL) L->fim = NULL;
	}
	else if(atual == L->fim) {
		L->fim = anterior;
		L->fim->prox = NULL;
	}
	else anterior->prox = atual->prox;
	free(atual);
	*erro = 0;
	}
	else eliminar_rec(L, atual, atual->prox, x, erro);
}

	
