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

