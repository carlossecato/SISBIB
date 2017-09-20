#include<stdio.h>
#include<stdlib.h>

#include "lista.h"


int menu();

eleml EntraDados(Lista *);

int Cadastra(Lista*, eleml*, int*);

elemLivro EntraDadosLivros(ListaLivros*);

int CadastraLivro(ListaLivros*, elemLivro*, int*);

int removeAluno(Lista*, char*);

int removeLivro(ListaLivros*, char*,int*);

int retiraLivro(Lista*, ListaLivros*, char*, char*,char*);

int devolveLivro(Lista*, ListaLivros*, char*, char*);
