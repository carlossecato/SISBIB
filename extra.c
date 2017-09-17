#include<stdio.h>
#include<stdlib.h>

#include "lista.h"



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
                printf("Titulo: "); scanf("%s", A.titulo);
                printf("Autor: "); scanf("%s", A.autor);
                printf("ISBN: "); scanf("%s", A.ISBN);
                printf("Editora: "); scanf("%s", A.editora);
                printf("Ano: "); scanf("%d", &A.ano);
                printf("Exemplar: "); scanf("%d", &A.exemplar);  
                printf("Edicao: "); scanf("%s", A.edicao);
                return A;
        } else printf("Erro ao cadastrar");

}

int CadastraLivro(ListaLivros *LL, elemLivro *Y, int *erro){
	
	insereListaLivros(LL,Y);

}

int removeLivro(ListaLivros *LL, char *titulo, int *exemplar){
	
	removeListaLivro(LL,titulo,exemplar);

}
