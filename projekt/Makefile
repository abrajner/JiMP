__start__: a.out
	./a.out

./a.out: main.o macierze.o
	gcc main.o macierze.o

main.o: main.c macierze.h
	gcc -c main.c 

macierze.o: macierze.h macierze.c
	gcc -c macierze.c

