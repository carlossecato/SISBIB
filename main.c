#include<stdio.h>
#include<stdlib.h>



#include "extra.h"
#include "pilha.h"




int main(){
	
	char nome[50], titulo[50];
	int op, op2, erro, opcao,t, opcao2, exemplar;
	eleml X;
	elemLivro Y;
	Pilha P;
	//Fila F;
	Lista L;
	ListaLivros LL;
	//Cria(&F);
	cria_lista(&L);
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
	  break;
	  case 4: 
	  break;
	  case 5:  printf("Digite o Titulo do Livro a ser removido: ");
                   scanf("%s",titulo);
		  
		   printf("Digite o numero do exemplar: ");
		   scanf("%d",&exemplar);	
		  
                   t= removeLivro(&LL,&titulo,&exemplar);
                   if(t==0)
                        printf("Erro ao remover\n");
                   if(t==1)
                        printf("Livro removido com sucesso!\n");
          break;
	  case 6: printf("Digite o nome do usuario a ser removido: ");
		  scanf("%s",nome);
		  
		 t= removeAluno(&L,&nome);
		if(t==0)
			printf("Erro ao remover\n");
		if(t==1)
			printf("Usuario removido com sucesso!\n");
	  break;
	  case 7: return 0;
 	  break;
	
	default: printf("Opcao Invalida!");
	break;
	}

	printf("Deseja continuar(1-sim, 0-nao): ");
	scanf("%d",&op2);

	

	}while(op2==1);
	


	
	
}





