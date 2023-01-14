NAME = zombies_attack
SRC = ./src/*.cpp
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++11 -I ./include/
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all:
	$(CC) main.cpp $(SRC) -o $(NAME) $(CFLAGS) $(LIBS)

clean:
	rm -f $(OBJ) main

re:	clean all