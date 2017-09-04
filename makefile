trab1_alg: main.o pilha.o fila.o extra.o pilha.h fila.h extra.h lista.o lista.c
	gcc main.o pilha.o pilha.h fila.o fila.h extra.o extra.h lista.o lista.h -o trab1_alg
main.o: main.c
	gcc -c main.c
pilha.o: pilha.c
	gcc -c pilha.c
fila.o: fila.c
	gcc -c fila.c
extra.o: extra.c
	gcc -c extra.c
lista.o: lista.c
	gcc -c lista.c
clean:
	rm -rf main*.o pilha*.o fila*.o lista*.o extra*.o 

