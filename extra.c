#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "lista.h"
//#include "fila.h"


int  menu(){

	int opcao;	

	printf("   >>> SISBIB <<<  \n\n");
	printf("Menu: \n");
	printf("1. Cadastrar Aluno \n");
	printf("2. Cadastrar Livro \n");
	printf("3. Retirar Livro \n");
	printf("4. Retornar Livro \n");
	printf("5. Remover Livro \n");
	printf("6. Remover Aluno \n");
	printf("7. Sair \n");
	printf("Escolha a opcao desejada: \n");

	scanf("%d", &opcao);

	return opcao;
}

eleml EntraDados(Lista *L){
	int op;
	eleml A;

	if(!lista_cheia(L)){

		printf("   >>> SISBIB - Cadastro Aluno <<<  \n\n");
		printf("Nome: "); scanf("%s", A.nome);
		printf("Num USP: "); scanf("%s", A.nusp);
		printf("Telefone: "); scanf("%s", A.tel);
		printf("Email: "); scanf("%s", A.email);
		return A;
	} else printf("Erro ao cadastrar");

}

int Cadastra(Lista *L, eleml *X){

	
	insere_lista(L,X);
	

}

int removeAluno(Lista *L, char *nome){
	
	remove_lista(L,nome);
}

elemLivro EntraDadosLivros(ListaLivros *LL){
	 int op;
        elemLivro A;

        if(!listaLivro_cheia(LL)){
		printf("   >>> SISBIB - Cadastro Livro <<<  \n\n");
                printf("Titulo: "); scanf("%s", A.titulo);
                printf("Autor: "); scanf("%s", A.autor);
                printf("ISBN: "); scanf("%s", A.ISBN);
                printf("Editora: "); scanf("%s", A.editora);
                printf("Ano: "); scanf("%d", &A.ano);
                printf("Exemplar: "); scanf("%d", &A.exemplar);  
                printf("Edicao: "); scanf("%s", A.edicao);
		A.disponivel = 1;
                return A;
        } else printf("Erro ao cadastrar");

}

int CadastraLivro(ListaLivros *LL, elemLivro *Y, int *erro){
	

	insereListaLivros(LL,Y);

	

}

int removeLivro(ListaLivros *LL, char *titulo, int *exemplar){
	
	removeListaLivro(LL,titulo,exemplar);

}

int retiraLivro(Lista *L, ListaLivros *LL, char *nusp, char *titulo, char *exemplar){
		
	eleml X;
	elemLivro Y;
	int i,erro;
	
	L->dados[i] = buscaAluno(L,nusp);
	LL->dados[i]=buscaLivro(LL,titulo,exemplar);
	
	if(LL->dados[i].disponivel != 0){
	LL->dados[i].disponivel = 0;
	// inserir mensagem de sucesso
	return 1;
	}else{
	Entra(&LL->dados[i].F,&L->dados[i],&erro);
	printf("%d",erro);
	return 0;
	}
}

int devolveLivro(Lista *L, ListaLivros *LL, char *titulo, char *exemplar){
	
	eleml X;
	int i,erro;		
	LL->dados[i] = buscaLivro(LL,titulo,exemplar);
	
	if(LL->dados[i].disponivel == 0){
	LL->dados[i].disponivel = 1;
		if(!EstaVazia(&LL->dados[i].F)){
		Sai(&LL->dados[i].F,&X,&erro);
		printf("%s",X.nome);
		}
	return 1;
	}else return 0;

}
