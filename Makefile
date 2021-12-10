
CC = gcc

tictactoe:
	$(CC) main.c -o tictactoe

clean:
	rm -f tictactoe
