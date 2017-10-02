#include<stdio.h>
#include<stdlib.h>

#include "banco.h"



void cria(Banco *B) {
     int i;
     for (i=0;i<TAM-1;i++)
         B->v[i].prox=i+1;
     B->v[TAM-1].prox=-1;
     B->ini=-1;
     B->fim=-1;
     B->primeiro_vazio=0;
}

void getnode(Banco *B, int *pos) {
    if (B->primeiro_vazio!=-1) {
       *pos=B->primeiro_vazio;
       B->primeiro_vazio=B->v[B->primeiro_vazio].prox;
       B->v[*pos].prox=-1;
    }
    else *pos=-1;
}

void freenode(Banco *B, int *pos) {
    B->v[*pos].prox=B->primeiro_vazio;
    B->primeiro_vazio=*pos;
}



int IsEmpty(Banco *B) {
    if (B->ini==-1)
       return(1);
    else return(0);
}

int IsFull(Banco *B) {
    if (B->primeiro_vazio==-1)
       return(1);
    else return(0);
}

void inserir_no_comeco(Banco *B, elem *x, int *erro) {
     int pos;
     if (IsFull(B))
        *erro=1;
     else {
          *erro=0;
          getnode(B,&pos);
          B->v[pos].info=*x;
          B->v[pos].prox=B->ini;
          B->ini=pos;
          if (B->fim==-1)
             B->fim=pos;
     }
}

void retirar_do_comeco(Banco *B, elem *x, int *erro) {
     int pos;
     if (IsEmpty(B))
          *erro=1;
     else {
          *erro=0;
          *x=B->v[B->ini].info;
          pos=B->ini;
          B->ini=B->v[B->ini].prox;
          freenode(B,&pos);
     }
}

void inserir_no_fim(Banco *B, elem *x, int *erro) {
     int pos;
     if (IsFull(B))
        *erro=1;
     else {
          *erro=0;
          getnode(B,&pos);
          B->v[pos].info=*x;
          B->v[pos].prox=-1;
          if (B->fim!=-1)
             B->v[B->fim].prox=pos;
          B->fim=pos;
          if (B->ini==-1)
             B->ini=pos;
     }
}




