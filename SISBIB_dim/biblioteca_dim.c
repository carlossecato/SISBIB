//Carlos Henrique de Carvalho Secato nUSP 9292890
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "lista_dim.h"
//#include "fila.h"
#include "pilha_dim.h"

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

char maiuscula(char *nome){
	int tam,i;
	tam = strlen(nome);
	for(i=0;i<tam;i++){
 	nome[i] = toupper(nome[i]);
	}

	return nome;
}

eleml EntraDados(Lista *L){
	int op,tam;
	eleml A;

	if(!lista_cheia(L)){

		printf("   >>> SISBIB - Cadastro Aluno <<<  \n\n");
		printf("Nome: "); scanf(" %[^\n]s", A.nome); 	
	        maiuscula(A.nome);
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
		maiuscula(A.titulo);
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
        } else printf("Erro ao cadastrar");

}

int CadastraLivro(ListaLivros *LL, elemLivro *Y, int *erro){
	

	insereListaLivros(LL,Y);

	

}

int removeLivro(ListaLivros *LL, char *titulo, int *exemplar){
	
	removeListaLivro(LL,titulo,exemplar);

}

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
		Push(P,X->info.nusp);
		Push(P,Y->info.titulo);
		}
	return 1;
	}else return 0;
}
	return 0;
}

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
