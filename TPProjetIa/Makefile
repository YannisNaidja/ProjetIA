CC = g++
CFLAGS = -Wall -g -g3 -O3

OBJ = etat.o ferme.o filereader.o ouvert.o ouvert_meilleur.o ouvert_pile.o ouvert_queue.o
DEPS = etat.h ferme.h ouvert.h ouvert_pile.h ouvert_meilleur.h ouvert_queue.h filereader.h


all : main

main : main.cpp $(OBJ) $(DEPS) 
	$(CC) $(CFLAGS) -o main main.cpp $(OBJ)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $^


clean:
	- rm -f $(OBJ)
	- rm -f main
	- rm -f main.o	
	- rm -f *.gch
