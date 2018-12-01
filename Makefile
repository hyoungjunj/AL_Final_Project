main: Main2.o LinkedList.o Graph.o Dijkstra.o
	gcc -lm -o main Main2.o LinkedList.o Graph.o Dijkstra.o

Main.o: Main2.c LinkedList.c Graph.c LinkedList.h Graph.h Dijkstra.h
	gcc -c Main2.c
