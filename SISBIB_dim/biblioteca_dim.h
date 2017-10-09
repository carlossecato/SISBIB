//Carlos Henrique de Carvalho Secato nUSP 9292890

#include<stdio.h>
#include<stdlib.h>

#include "lista_dim.h"
#include "pilha_dim.h"

int menu();

eleml EntraDados(Lista *);

int Cadastra(Lista*, eleml*, int*);

char maiusculo(char*);

elemLivro EntraDadosLivros(ListaLivros*);

int CadastraLivro(ListaLivros*, elemLivro*, int*);

int removeAluno(Lista*, char*);

int removeLivro(ListaLivros*, char*,int*);

void imprime_lista(Lista*);

void imprimeListaLivro(ListaLivros*);

noLista *buscaAluno(Lista *,char*);

noLivro *buscaLivro(ListaLivros *, char*, int*);

int retiraLivro(Lista*, ListaLivros*, Pilha *P, char*, char*,int*);

int devolveLivro(Lista*, ListaLivros*, Pilha *P, char*, int*);

int imprime_pilha(Pilha*);


