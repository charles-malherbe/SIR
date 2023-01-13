NAME = pandemic
SRC = ./src/*.cpp
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++11 -I ./include/
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all:
	$(CC) main.cpp $(SRC) -o $(NAME) $(CFLAGS) $(LIBS)

clean:
	rm -f $(OBJ) main

re:	clean all