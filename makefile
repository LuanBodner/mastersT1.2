contigua:
	gcc -c fila_contigua.c -o fila_contigua.o
	gcc main_contigua.c fila_contigua.o -o main_contigua

encadeada:
	gcc -c fila_encadeada.c -o fila_encadeada.o
	gcc main_encadeada.c fila_encadeada.o -o main_encadeada

clean:
	rm -f main_encadeada
	rm -f main_contigua
	rm -f *.o