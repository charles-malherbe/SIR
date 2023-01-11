NAME = pandemic
SRC = ./src/*.cpp
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++11 -I ./include/

all:
	$(CC) $(CFLAGS) main.cpp $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ) main

re:	clean all