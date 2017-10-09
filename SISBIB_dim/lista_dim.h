//Carlos Henrique de Carvalho Secato nUSP 9292890

#include<stdio.h>
#include<stdlib.h>
#include "fila_dim.h"

typedef struct {
        char nome[50];
        char nusp[10];
        char tel[10];
        char email[30];
}eleml;



typedef struct blocoLista{
	eleml info;
	struct blocoLista *prox;
}noLista;

typedef struct{
	noLista *inicio, *fim;
}Lista;

typedef struct {
        char titulo[50];
        char autor[50];
        char ISBN[10];
        char editora[30];
	int ano;
	int exemplar;
	char edicao[10];
	int disponivel;
	Fila F;
}elemLivro;

typedef struct bloco1 {
        elemLivro info;
	struct bloco1 *prox;
}noLivro;

typedef struct{
	noLivro *inicio, *fim;
}ListaLivros;



void cria(Lista*);

void cria_livros(ListaLivros*);

void libera_lista(Lista*);

void liberaLivros(ListaLivros*);

//int consulta_lista_pos(Lista* L, int pos, eleml *X);

//int consulta_lista_mat(Lista* L, int mat, eleml *X);

int insere_lista(Lista*, eleml*);

int insereListaLivros(ListaLivros*, elemLivro*);

int remove_lista(Lista*, char*);

int removeListaLivro(ListaLivros*, char*, int*);

//int tamanho_lista(Lista* L);

int lista_cheia(Lista* L);

int listaLivro_cheia(ListaLivros *LL);

//int lista_vazia(Lista* L);




