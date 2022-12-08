$(CC) = gcc

final:
	$(CC) lexer.c logic.c main.c -o final.exe
