//Trabalho 1 - Disciplina: Algoritmos e Estrutura de Dados
//Data: 15/10/2017
//Alberice Lucas de Araújo nUSP 7986563
//Carlos Henrique de Carvalho Secato nUSP 9292890

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "lista_dim.h"

//cria lista de alunos L
void cria_lista(Lista *L){
	L->inicio = NULL;
	L->fim = NULL;
}


//cria lista de livros LL
void cria_livros(ListaLivros *LL){
	LL->inicio = NULL;
	LL->fim = NULL;
}


//esvazia lista de alunos L
void libera_lista(Lista* L){
	noLista *p;
	
	p=L->inicio;	
	while(p!=NULL){
		L->inicio = L->inicio->prox;
		free(p);
		p=L->inicio;
	}

	L->fim = p;
}


//esvazia lista de alunos L
void liberaLivros(ListaLivros *LL){
	noLivro *p;

	p=LL->inicio;	
	while(p!=NULL){
		LL->inicio = LL->inicio->prox;
		free(p);
		p=LL->inicio;
	}

	LL->fim = p;
}
/*
int consulta_lista_pos(Lista* L, int pos, eleml *X){
	if(L == NULL || pos <= 0 ||  pos > L->qtd)
		return 0;
	*X = L->dados[pos-1];
	return 1;

}
*/


//insere o elemento aluno na lista L. Returna 0 se erro, 1 se insercao correta
int insere_lista(Lista* L, eleml *X){
	noLista *p;

	p = (noLista*)malloc(sizeof(noLista));
	if(p==NULL){
	//	*erro = 1;
		return;
	} else //
	p->info = *X;
	p->prox = NULL;
	
	if(L->inicio == NULL)
		L->inicio = p;
		else L->fim->prox = p;
		
	L->fim = p;
}


//insere o elemento livro na lista LL. Retorna 0 se erro, 1 se insercao correta
int insereListaLivros(ListaLivros *LL, elemLivro *X){
	noLivro *p;

	p = (noLivro*)malloc(sizeof(noLivro));
	if(p==NULL){
		//*erro = 1;
		return;
	} else //*erro = 0;
	p->info = *X;
	p->prox = NULL;

	if(LL->inicio == NULL)
		LL->inicio = p;
		else LL->fim->prox = p;

	LL->fim = p;
}


//remove o elemento aluno buscado pelo nome, e inicia um novo no na posicao buscada, liga-se ao proximo ponteiro e libera o no buscado
int remove_lista(Lista* L, char *nome){
 	noLista *p, *aux;
   	int teste = 0;
 
	p = L->inicio;
        while ((p!=NULL) && (!teste)) {
           if (strcmp(p->info.nome,nome)==0) {
		if (p == L->inicio)
                 L->inicio = L->inicio->prox;
              else if (p == L->fim) {	
                   L->fim = aux;
                   L->fim->prox = NULL;
		  
              }
              else aux->prox = p->prox;
              free(p);
              teste = 1;
	      return 1;
           }
           else {
                aux = p;
                p = p->prox;
           }

     }
		return 0;     
}


//remove o elemento livro buscado pelo titulo e exemplar, inicia um novo no na posicao buscada, liga-se ao proximo ponteiro e libera o no buscado
int removeListaLivro(ListaLivros *LL, char *titulo, int *exemplar){
	noLivro *p, *aux;
        int teste = 0;
	
        p = LL->inicio;
        while ((p!=NULL) && (!teste)) {
           if (strcmp(p->info.titulo,titulo)==0 && p->info.exemplar == *exemplar) {
		if (p == LL->inicio)
                 LL->inicio = LL->inicio->prox;
              else if (p == LL->fim) {
                   LL->fim = aux;
                   LL->fim->prox = NULL;

              }
              else aux->prox = p->prox;
              free(p);
              teste = 1;
              return 1;
           }
           else {
                aux = p;
                p = p->prox;
           }

     }
                return 0;
}
/*
int tamanho_lista(Lista* L){
	if(L == NULL)
		return 0;
	else
		return (1+tamanho_lista(L->prox));
}
*/


//retorna se a lista de alunos esta cheia ou nao
int lista_cheia(Lista* L){
	noLista *p;
	
	p = (noLista*)malloc(sizeof(noLista));
	if(p == NULL)
	return 1;
	else return 0;

}


//retorna se a lista de livros esta cheia ou nao
int listaLivro_cheia(ListaLivros *LL){
	noLivro *p;
	
	p = (noLivro*)malloc(sizeof(noLivro));
	if(p == NULL)
	return 1;
	else return 0;
}

/*
int lista_vazia(Lista* L){
	if(L == NULL)
		return -1;
	return (L->qtd == 0);
}
*/

