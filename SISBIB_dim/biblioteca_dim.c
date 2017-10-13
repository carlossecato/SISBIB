//Trabalho 1 - Disciplina: Algoritmos e Estrutura de Dados
//Data: 15/10/2017
//Alberice Lucas de Araújo nUSP 7986563
//Carlos Henrique de Carvalho Secato nUSP 9292890

#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxNome 50
#define MaxTitulo 50

#include "lista_dim.h"
#include "pilha_dim.h"


//menu principal da aplicação, o usuario escolhe a opçao que será acessada pelo sistema.
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


//funcao para tranformar qualquer entrada de string, visando a padronizacao evitando erros de busca
char maiuscula(char *nome){
	int tam,i;
	tam = strlen(nome);
	for(i=0;i<tam;i++){
		nome[i] = toupper(nome[i]);
	}

	return nome;
}


//funcao que compara o tamanho maximo da variavel nome com o tamanho inserido pelo usuario, retorna 0 quando eh maior que o permitido, 1 quando esta dentro do aceitavel
int verificaNome(char *nome){
	int tam;
	tam = strlen(nome);
	if(tam > MaxNome){
		return 0;
	}
	else return 1;
}


//funcao para realizar a entrada dos dados dos alunos, o usuario deve entrar com as informacoes pertinentes e a funcao retorna um elemento aluno
eleml EntraDados(Lista *L){
	int op,tam;
	eleml A;

	if(!lista_cheia(L)){

		printf("   >>> SISBIB - Cadastro Aluno <<<  \n\n");
		printf("Nome: "); scanf(" %[^\n]s", A.nome); 	
		maiuscula(A.nome);
		if(verificaNome(A.nome) != 0){
			printf("Num USP: "); scanf("%s", A.nusp);
			printf("Telefone: "); scanf("%s", A.tel);
			printf("Email: "); scanf("%s", A.email);
			return A;

		} else{
			printf("Erro ao cadastrar: nome excede limite\n");
			strcpy(A.nome, "erro");
			return A;
		}
	}else printf("Erro ao cadastrar: Lista cheia\n");

}


//funcao que recebe o elemento aluno e atraves do TAD insere essa informacao na lista de alunos, retorna sucesso ou erro ao cadastrar
int Cadastra(Lista *L, eleml *X){

	if(strcmp(X->nome,"erro")==0)
		return 0;
	else{	
		insere_lista(L,X);
	}


}


//funcao que recebe a lista de alunos e um nome, que será buscado na lista e removido, retorna sucesso ou erro ao remover
int removeAluno(Lista *L, char *nome){

	remove_lista(L,nome);
}


//funcao que compara o tamanho maximo da variavel titulo com o tamanho inserido pelo usuario, retorna 0 quando eh maior que o permitido, 1 quando esta dentro do aceitavel
int verificaTitulo(char *titulo){
	int tam;
	tam = strlen(titulo);
	if(tam > MaxTitulo)
		return 0;
	else return 1;
}


//funcao para realizar a entrada dos dados dos livros, o usuario deve entrar com as informacoes pertinentes e a funcao retorna um elemento livro
elemLivro EntraDadosLivros(ListaLivros *LL){
	int op;
	elemLivro A;

	if(!listaLivro_cheia(LL)){
		printf("   >>> SISBIB - Cadastro Livro <<<  \n\n");
		printf("Titulo: "); scanf(" %[^\n]s", A.titulo);
		maiuscula(A.titulo);
		if(verificaTitulo(A.titulo) != 0){
			printf("Autor: "); scanf(" %[^\n]s", A.autor);
			maiuscula(A.autor);
			printf("ISBN: "); scanf("%s", A.ISBN);
			printf("Editora: "); scanf(" %[^\n]s", A.editora); 
			maiuscula(A.editora);
			printf("Ano: "); scanf("%d", &A.ano);
			printf("Exemplar: "); scanf("%d", &A.exemplar);  
			printf("Edicao: "); scanf("%s", A.edicao);
			A.disponivel = 1;
			Cria(&A.F);
			return A;
		} else{
			printf("Erro ao cadastrar: titulo excede o limite\n");
			strcpy(A.titulo,"erro");
			return A;
		}
	} else printf("Erro ao cadastra: Lista cheia \n");
}


//funcao que recebe o elemento livro e atraves do TAD insere essa informacao na lista de livro, retorna sucesso ou erro ao cadastrar
int CadastraLivro(ListaLivros *LL, elemLivro *Y, int *erro){

	if(strcmp(Y->titulo,"erro")==0)
		return 0;
	else{
		insereListaLivros(LL,Y);
	}


}


//funcao que recebe a lista de livros, um titulo e o exemplar, que será buscado na lista e removido, retorna sucesso ou erro ao remover
int removeLivro(ListaLivros *LL, char *titulo, int *exemplar){

	removeListaLivro(LL,titulo,exemplar);

}


//funcao para a impressao da lista de aluno
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


//funcao para impressao da lista de livros
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


//funcao de busca que varre a lista de alunos em busca de um nome fornecido pelo usuario, retorna o ponteiro para  aluno do nome buscado
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


//funcao de busca que varre a lista de livros em busca do titulo e do exemplar fornecido pelo usuario, retorna o ponteiro para o livro buscado
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


//funcao que retira o livro tornando-o indisponivel para novos emprestimos, busca na lista de alunos e livros, nusp e qual o titulo e exemplar desejado, marca como indisponivel caso as buscas forem sucesso e o emprestimo é realizado. Caso o livro ja esteja indisponivel o usuario é colocado em uma fila de espera desse livro pelo nome e uma notificacao eh enviada na forma de mensagem que eh armazenada em uma pilha 
int retiraLivro(Lista *L, ListaLivros *LL, Pilha *P, char *nusp, char *titulo, int *exemplar){

	char msg[100] = "Livro indisponivel, usuario inserido na fila espera";	
	noLista *X;
	char aux[50] = "----------------------------------------";
	noLivro *Y;
	int i,erro;

	X = buscaAluno(L,nusp);
	Y = buscaLivro(LL,titulo,exemplar);

	if(Y == NULL || X == NULL){
		printf("Livro ou usuário inexistente. Tente novamente\n");
	}
	else{
		if(Y->info.disponivel != 0){
			Y->info.disponivel = 0;
			// inserir mensagem de sucesso	

			return 1;
		}else{
			Entra(&Y->info.F,&X,&erro);	
			printf("%s",X->info.nome);
			Push(P,aux);
			Push(P,msg);
			Push(P,X->info.nome);

		}
	}
	return 0;

}


//funcao que devolve o livro tornando disponivel. O usuario informa titulo e exemplar e a partir de uma busca o livro é colocado como disponivel. Caso a fila esteja diferente de zero, a funcao tira um nome da fila, e esse nome eh notificado com uma mensagem armazenada em uma pilha
int devolveLivro(Lista *L, ListaLivros *LL, Pilha *P, char *titulo, int *exemplar){

	noLista *X;
	noLivro *Y;
	char aux[50] =  "----------------------------------------";
	int i,erro;
	char msgDev[100] = "O livro esta disponivel";			

	Y = buscaLivro(LL,titulo,exemplar);

	if(Y == NULL){
		printf("Livro inexistente. Tente novamente\n");
	}
	else{
		if(Y->info.disponivel == 0){
			Y->info.disponivel = 1;
			if(!EstaVazia(&Y->info.F)){
				Sai(&Y->info.F,&X,&erro);
				printf("%s\n\n",X->info.nome);
				Push(P,aux);
				Push(P,msgDev);
				Push(P,X->info.nome);
				Push(P,Y->info.titulo);
			}
			return 1;
		}else return 0;
	}
	return 0;
}


//funcao que imprime todas as mensagens do sistema, ela recebe a pilha de mensagens e imprime todo seu conteudo para o usuario
int imprime_pilha(Pilha *P){
	noPilha *X;

	printf("   >>> SISBIB - Mensagens do sistema <<<  \n\n");

	X = P->topo;

	if(X == NULL)
		printf("Nenhuma mensagem...\n");
	else{
		while(X != NULL){
			printf("%s \n",X->info.nome);
			X = X->prox;
		}
	}
}
