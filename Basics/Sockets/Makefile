# EXECUTABLES
CLIENT_EXE = TCPClient/client
SERVER_EXE = TCPServer/server

# SOURCE FILES
CLIENT_SRC = TCPClient/client.c
SERVER_SRC = TCPServer/server.c

# GCC
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
CFLAGS = -std=c99 -lpthread -g
DEBUG = -DDEBUG
CC = gcc

OBJS = *.o *.dSYM

client: $(CLIENT_SRC)
	@$(CC) -o $(CLIENT_EXE) $(CLIENT_SRC) $(WARNING) $(ERROR) $(CFLAGS) $(DEBUG)

server: $(SERVER_SRC)
	@$(CC) -o $(SERVER_EXE) $(SERVER_SRC) $(WARNING) $(ERROR) $(CFLAGS) $(DEBUG)

clean:
	rm -rf $(OBJS) $(MAIN_EXE) $(DOTFILE) $(DOT_OUTPUT) valgrind*.log *.b *.txt
