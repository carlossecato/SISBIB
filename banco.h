#include<stdio.h>
#include<stdlib.h>

#define TAM 5

typedef int elem;

typedef struct {
        elem info;
        int prox;
} no;

typedef struct {
        int ini, fim, primeiro_vazio;
        no v[TAM];
} Banco;

void cria(Banco*);

void getnode(Banco*,int*);

void freenode(Banco*,int*);

int IsEmpty(Banco*);

int IsFull(Banco*);

void inserir_no_comeco(Banco*B,elem*,int*);

void retirar_do_comeco(Banco*B,elem*,int*);

void inserir_no_fim(Banco*B,elem*,int*);
