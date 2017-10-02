trab1_alg_dim: main_dim.o biblioteca_dim.o fila_dim.o lista_dim.o pilha_dim.o biblioteca_dim.h fila_dim.h lista_dim.h pilha_dim.h 
	gcc main_dim.o biblioteca_dim.o pilha_dim.o pilha_dim.h fila_dim.o fila_dim.h lista_dim.o lista_dim.h -o trab1_alg_dim
main_dim.o: main_dim.c
	gcc -c main_dim.c
pilha_dim.o: pilha_dim.c
	gcc -c pilha_dim.c
fila_dim.o: fila_dim.c
	gcc -c fila_dim.c
lista_dim.o: lista_dim.c
	gcc -c lista_dim.c
biblioteca_dim.o: biblioteca_dim.c
	gcc -c biblioteca_dim.c
clean: 
	rm -rf main_dim*o pilha_dim*.o fila_dim*.o lista_dim*.o biblioteca_dim*.o
