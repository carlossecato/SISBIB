//Carlos Henrique de Carvalho Secato nUSP 9292890

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "lista.h"


void cria_lista(Lista *L){
	L->qtd = 0;
}

void cria_livros(ListaLivros *LL){
	LL->qtd = 0;
}


void libera_lista(Lista* L){
	L->qtd = 0;
}

void liberaLivros(ListaLivros *LL){
	LL->qtd = 0;
}

int consulta_lista_pos(Lista* L, int pos, eleml *X){
	if(L == NULL || pos <= 0 ||  pos > L->qtd)
		return 0;
	*X = L->dados[pos-1];
	return 1;

}

int insere_lista(Lista* L, eleml *X){

	if(L == NULL)
        return 0;
    if(L->qtd == TamLista)//lista cheia
        return 0;
    L->dados[L->qtd] = *X;
    L->qtd++;
    return 1;
}

int insereListaLivros(ListaLivros *LL, elemLivro *X){
	if(LL == NULL)
        return 0;
    if(LL->qtd == TamListaLivro)//lista cheia
        return 0;
    LL->dados[LL->qtd] = *X;
    LL->qtd++;
    return 1;
}

int remove_lista(Lista* L, char *nome){
	if(L == NULL)
		return 0;
	if(L->qtd == 0)
		return 0;

	int k,i = 0;
	while(i<L->qtd && strcmp(L->dados[i].nome, nome)!=0)
		i++;
	if(i == L->qtd)//elemento nao encontrado
		return 0;

	for(k=i; k< L->qtd-1; k++)
		L->dados[k] = L->dados[k+1];
	L->qtd--;
	return 1;
}

int removeListaLivro(ListaLivros *LL, char *titulo, int *exemplar){
	if(LL == NULL)
                return 0;
        if(LL->qtd == 0)
                return 0;

        int k,i = 0;
        while(i<LL->qtd && strcmp(LL->dados[i].titulo, titulo)!=0 && strcmp(LL->dados[i].exemplar,exemplar) !=0)
                i++;
        if(i == LL->qtd)//elemento nao encontrado
                return 0;

        for(k=i; k< LL->qtd-1; k++)
                LL->dados[k] = LL->dados[k+1];
        LL->qtd--;
        return 1;
}

int tamanho_lista(Lista* L){
	if(L == NULL)
		return -1;
	else
		return L->qtd;
}

int lista_cheia(Lista* L){
	if(L == NULL)
		return -1;
	return (L->qtd == TamLista);
}

int listaLivro_cheia(ListaLivros *LL){
	if(LL == NULL)
	return -1;
	return(LL->qtd == TamListaLivro);
}

int lista_vazia(Lista* L){
	if(L == NULL)
		return -1;
	return (L->qtd == 0);
}

void imprime_lista(Lista* L){
	if(L == NULL)
		return;
	int i;

	for(i=0; i< L->qtd; i++){
		printf("Nome: %s\n",L->dados[i].nome);
		printf("NUsp: %s\n",L->dados[i].nusp);
		printf("Tel: %s\n",L->dados[i].tel);
		printf("Email: %s\n",L->dados[i].email);

		printf("-------------------------------\n");
	}
}

void imprimeListaLivros(ListaLivros *LL){
	if(LL == NULL)
                return;
        int i;

        for(i=0; i< LL->qtd; i++){
                printf("Titulo: %s\n",LL->dados[i].titulo);
                printf("Autor: %s\n",LL->dados[i].autor);
                printf("ISBN: %s\n",LL->dados[i].ISBN);
                printf("Editora: %s\n",LL->dados[i].editora);
                printf("Ano: %d\n",LL->dados[i].ano);
                printf("Exemplar: %d\n",LL->dados[i].exemplar);
                printf("Edicao: %s\n",LL->dados[i].edicao);

                printf("-------------------------------\n");
        }
}

eleml buscaAluno(Lista *L, char *nusp){

        int i = 0;
        while(i<L->qtd && strcmp(L->dados[i].nusp, nusp)!=0)
                i++;

        return L->dados[i];

}

int buscaLivro(ListaLivros *LL, char *titulo, int *exemplar){

        int i = 0;
        while(i<LL->qtd && strcmp(LL->dados[i].titulo, titulo)!=0 && LL->dados[i].exemplar != exemplar)
                i++;

        return i;
}

