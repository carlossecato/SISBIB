#include<stdio.h>
#include<stdlib.h>

#include"fila.h"
#include"pilha.h"


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

elem cadastra(Fila *F){
	int op;
	elem A;

	if(!EstaCheia(F)){
	printf("Nome: "); scanf("%s", A.nome);
	printf("Num USP: "); scanf("%s", A.nusp);
	printf("Telefone: "); scanf("%s", A.tel);
	printf("Email: "); scanf("%s", A.email);
	return A;
	} else printf("Erro ao cadastrar");
		
}
