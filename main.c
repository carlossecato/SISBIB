#include<stdio.h>
#include<stdlib.h>

#include "fila.h"
#include "pilha.h"
#include "lista.h"
#include "extra.h"




int main(){

	int op, op2,opcao, erro;
	elem X,aux;
	Pilha P;
	Fila F;
	Cria(&F);
	do{
	
	op=menu();
	
	switch(op){
	
	  case 1: 	do{
			X=cadastra(&F);
			Entra(&F,&X,&erro);
			printf("Deseja realizar mais um cadastro? (1-sim, 0-nao)");
	        	scanf("%d",&opcao);
        
        }while(opcao==1 && !EstaCheia(&F));
	
	while(!EstaVazia(&F)){
	Sai(&F,&aux,&erro);
	printf("%s",aux.nome);
	}
          break;
	  case 2:
	  break;
	  case 3: 
	  break;
	  case 4: 
	  break;
	  case 5:
	  break;
	  case 6: 
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





