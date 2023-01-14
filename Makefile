NAME = zombies_attack
SRC = ./src/*.cpp
CC = g++
CFLAGS = -std=c++17 -I ./include/

all:
	$(CC) main.cpp $(SRC) -o $(NAME) $(CFLAGS) $(LIBS)

clean:
	rm -f $(OBJ) main

re:	clean all