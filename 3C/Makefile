CC = gcc
CFLAGS = -W -Wall -g -o
SRCS = project3C.c project3C_hashtable.c
TARGET = project3C

all:
	$(CC) $(CFLAGS) $(TARGET) $(SRCS)

run:
	./$(TARGET)

val:
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

zip:
	tar -zcvf proj3C.tgz project3C.c project3C_hashtable.h project3C_hashtable.c wordlist1.txt wordlist2.txt Makefile