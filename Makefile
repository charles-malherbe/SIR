NAME = zombies_attack
SRC = ./src/*.cpp
CC = g++
CFLAGS = -std=c++17 -I ./include/

all: clean
	$(CC) main.cpp $(SRC) -o $(NAME) $(CFLAGS) $(LIBS)

clean:
	rm -f $(OBJ) main
	rm -rf plot_szr.png plot_szir.png plot_szirt.png

re:	clean all