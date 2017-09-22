//Carlos Henrique de Carvalho Secato nUSP 9292890

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "lista.h"
//#include "fila.h"
#include "pilha.h"

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
	printf("7. Mensagens do Sistema \n");
	printf("8. Sair \n");
	printf("Escolha a opcao desejada: \n");

	scanf("%d", &opcao);

	return opcao;
}

eleml EntraDados(Lista *L){
	int op;
	eleml A;

	if(!lista_cheia(L)){

		printf("   >>> SISBIB - Cadastro Aluno <<<  \n\n");
		printf("Nome: "); scanf(" %[^\n]s", A.nome); 	
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
		printf("Titulo: "); scanf(" %[^\n]s", A.titulo);
                printf("Autor: "); scanf(" %[^\n]s", A.autor);
                printf("ISBN: "); scanf("%s", A.ISBN);
                printf("Editora: "); scanf(" %[^\n]s", A.editora); 
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

int retiraLivro(Lista *L, ListaLivros *LL, Pilha *P, char *nusp, char *titulo, int *exemplar){
	
	char msg[100] = "Livro indisponivel, usuario inserido na fila espera";	
	eleml X;
	char aux[50] = "----------------------------------------";
	elemLivro Y;
	int i,erro;
	
	X = buscaAluno(L,nusp);
	i = buscaLivro(LL,titulo,exemplar);
	
	
	if(LL->dados[i].disponivel != 0){
	LL->dados[i].disponivel = 0;
	// inserir mensagem de sucesso	
	
	return 1;
	}else{
	
	Entra(&LL->dados[i].F,&X,&erro);	
	printf("%s",X.nome);
	Push(P,aux);
	Push(P,msg);
	Push(P,X.nome);
	
}return 0;

	
}

int devolveLivro(Lista *L, ListaLivros *LL, Pilha *P, char *titulo, int *exemplar){
	
	eleml X;
	elemp Y;
	char aux[50] = "----------------------------------------";
	int i,erro;
	char msg[100] = "O livro está disponivel. ";		
	 i = buscaLivro(LL,titulo,exemplar);
	
	if(LL->dados[i].disponivel == 0){
	LL->dados[i].disponivel = 1;
		if(!EstaVazia(&LL->dados[i].F)){
		Sai(&LL->dados[i].F,&X,&erro);
//		printf("%s\n\n",X.nome);
		Push(P,aux);
		Push(P, msg);
		Push(P,X.nome);
		
		}
	return 1;
	}else return 0;

}

void imprime_pilha(Pilha *P){
	
	elemp X;
	printf("   >>> SISBIB - Mensagens do sistema <<<  \n\n");
	while(!IsEmpty(P)){
	Pop(P,&X.nome);
	printf("%s \n",X.nome);
	

}
	
}
