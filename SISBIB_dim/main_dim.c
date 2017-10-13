//Trabalho 1 - Disciplina: Algoritmos e Estrutura de Dados
//Data: 15/10/2017
//Alberice Lucas de Araújo nUSP 7986563
//Carlos Henrique de Carvalho Secato nUSP 9292890

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#include "biblioteca_dim.h"
//#include "pilha.h"




int main(){
	
	char nome[50], titulo[50], nusp[30];
	int op, op2, erro, opcao,t, opcao2, exemplar;
	eleml X;
	elemLivro Y;
	Pilha P;
//	Fila F;
	Lista L;
	ListaLivros LL;
//	Cria(&F);
	Create(&P);
	cria_lista(&L);
	cria_livros(&LL);
	do{
	
	op=menu();
	
	switch(op){
	
	  case 1: do{
		  X=EntraDados(&L);
		  Cadastra(&L,&X,&erro);
		  printf("Deseja inserir mais um cadastro? (1-sim, 0-nao)");
		  scanf("%d",&opcao);
		 } while(opcao==1);

			imprime_lista(&L);  //remover esta funcao 
	  break;
	  case 2: do{
		  Y = EntraDadosLivros(&LL);
		  CadastraLivro(&LL,&Y,&erro);
		  printf("Deseja cadastrar mais livros? (1-sim, 0-nao)");

	          scanf("%d",&opcao2);
		}while(opcao2==1);
			imprimeListaLivros(&LL);  //remover esta funcao
	  break;
	  case 3: 
	   	  printf("   >>> SISBIB - Retirar Livro <<<  \n\n"); 
		  printf("Digite o nUsp do aluno: ");
		  scanf("%s", nusp);
		  printf("Digite o titulo do Livro: ");
		  scanf(" %[^\n]s",titulo);
		  maiuscula(titulo);
		  printf("Digite o exemplar: ");
		  scanf("%d", &exemplar);
		t=retiraLivro(&L,&LL,&P,&nusp,&titulo,&exemplar);	
		if(t==0)
			printf("Erro ao retirar Livro\n");
		if(t==1)
			printf("Livro retirado com sucesso\n");	
	  break;
	  case 4: printf("   >>> SISBIB - Retornar Livro <<<  \n\n");
		  printf("Digite o titulo do Livro: ");
                  scanf(" %[^\n]s", titulo);
		  maiuscula(titulo);
                  printf("Digite o exemplar: ");
                  scanf("%d", &exemplar);
                t=devolveLivro(&L,&LL,&P,&titulo,&exemplar);
                if(t==0)
                        printf("Erro ao devolver Livro\n");
                if(t==1)
                        printf("Livro devolvido com sucesso\n"); 
	  break;
	  case 5:  printf("Digite o Titulo do Livro a ser removido: ");
                   scanf(" %[^\n]s",titulo);
		   maiuscula(titulo);
		   printf("Digite o numero do exemplar: ");
		   scanf("%d",&exemplar);	
		  
                   t= removeLivro(&LL,&titulo,&exemplar);
                   if(t==0)
                        printf("Erro ao remover\n");
                   if(t==1)
                        printf("Livro removido com sucesso!\n");
          break;
	  case 6: printf("Digite o nome do usuario a ser removido: ");
		  scanf(" %[^\n]s",nome);
		  maiuscula(nome);
		 t= removeAluno(&L,&nome);
		if(t==0)
			printf("Erro ao remover\n");
		if(t==1)
			printf("Usuario removido com sucesso!\n");
	  break;
	  case 7: imprime_pilha(&P); 
 	  break;
	  case 8: return 0;
	  break;
	
	default: printf("Opcao Invalida!");
	break;
	}

	printf("Deseja continuar(1-sim, 0-nao): ");
	scanf("%d",&op2);

	

	}while(op2==1);
	


	
	
}





