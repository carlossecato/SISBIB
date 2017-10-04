//Carlos Henrique de Carvalho Secato nUSP 9292890

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "lista_dim.h"


void cria_lista(Lista *L){
	L->inicio = NULL;
	L->fim = NULL;
}

void cria_livros(ListaLivros *LL){
	LL->inicio = NULL;
	LL->fim = NULL;
}


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
int insere_lista(Lista* L, eleml *X){
	noLista *p;

	p = (noLista*)malloc(sizeof(noLista));
	if(p==NULL){
	//	*erro = 1;
		return;
	} else // *erro = 0;
	p->info = *X;
	p->prox = NULL;
	
	if(L->inicio == NULL)
		L->inicio = p;
		else L->fim->prox = p;
		
	L->fim = p;
}

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
int lista_cheia(Lista* L){
	noLista *p;
	
	p = (noLista*)malloc(sizeof(noLista));
	if(p == NULL)
	return 1;
	else return 0;

}

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

void imprime_lista(Lista* L){
	if(L == NULL)
		return;
	noLista *p;
	p = L->inicio;

	while(p != NULL){
		printf("Nome: %s\n",p->info.nome);
		printf("NUsp: %s\n",p->info.nusp);
		printf("Tel: %s\n",p->info.tel);
		printf("Email: %s\n",p->info.email);

		printf("-------------------------------\n");
	p = p->prox;
	}
}

void imprimeListaLivros(ListaLivros *LL){
//	if(LL == NULL)
  //              return;
        noLivro *p;

	p = LL->inicio;

        while(p != NULL){
                printf("Titulo: %s\n",p->info.titulo);
                printf("Autor: %s\n",p->info.autor);
                printf("ISBN: %s\n",p->info.ISBN);
                printf("Editora: %s\n",p->info.editora);
                printf("Ano: %d\n",p->info.ano);
                printf("Exemplar: %d\n",p->info.exemplar);
                printf("Edicao: %s\n",p->info.edicao);

                printf("-------------------------------\n");
        p = p->prox;
	}
}

noLista *buscaAluno(Lista *L, char *nusp){
	noLista *p;
	
        p = L->inicio;
        while(p != NULL && strcmp(p->info.nusp, nusp)!=0){
               p = p->prox;
		if(p == NULL)
			return NULL;
	}
        return p;

}

noLivro *buscaLivro(ListaLivros *LL, char *titulo, int *exemplar){
	noLivro *p;
	
        p = LL->inicio;
        while(p != NULL && strcmp(p->info.titulo, titulo)!=0 && p->info.exemplar != exemplar){
           p = p->prox;
		if(p == NULL)
		return NULL;
	}
        return p;
}

