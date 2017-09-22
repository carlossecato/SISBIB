//Carlos Henrique de Carvalho Secato nUSP 9292890

#include<stdio.h>
#include<stdlib.h>

#include "lista.h"
#include "pilha.h"

int menu();

eleml EntraDados(Lista *);

int Cadastra(Lista*, eleml*, int*);

elemLivro EntraDadosLivros(ListaLivros*);

int CadastraLivro(ListaLivros*, elemLivro*, int*);

int removeAluno(Lista*, char*);

int removeLivro(ListaLivros*, char*,int*);

int retiraLivro(Lista*, ListaLivros*, Pilha *P, char*, char*,int*);

int devolveLivro(Lista*, ListaLivros*, Pilha *P, char*, int*);

void imprime_pilha(Pilha*);
