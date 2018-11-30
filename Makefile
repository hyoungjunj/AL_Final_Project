main: Main.o LinkedList.o Graph.o
	gcc -lm -o main Main.o LinkedList.o Graph.o

Main.o: Main.c LinkedList.c Graph.c LinkedList.h Graph.h
	gcc -c Main.c
