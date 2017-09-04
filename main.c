#include<stdio.h>
#include<stdlib.h>

#include "fila.h"
#include "pilha.h"
#include "lista.h"
#include "extra.h"




int main(){

	int op, op2;
	Pilha P;
	Fila F;

	do{
	
	op=menu();
	
	switch(op){
	
	  case 1:
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
	
	default: printf("Opcao Invalida");
	break;
	}

	printf("Deseja continuar(1-sim, 0-nao): ");
	scanf("%d",&op2);

	

	}while(op2==1);
	


	
	
}





