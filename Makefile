CC = g++
CFLAGS = -Wall -g3 -03

OBJ = etat.o parcours_profondeur.o
DEPS = etat.h ouvert.h

all : main

main : main.o $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) -o main main.cpp $(OBJ)

%.o: %.c $(DEPS)
	$(CC) $(CCFLAGS) -c $^


clean:
	- rm -f $(OBJ)
	- rm -f main
