CC = gcc
OBJS = main.o
TARGET = server client
all:$(TARGET)
server:
	$(CC) -DSERVER -o server main.c
client:
	$(CC) -USERVER -o client main.c

clean:
	rm server client
