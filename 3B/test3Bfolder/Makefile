CC = gcc
CFLAGS = -W -Wall -g -o
SRCS = project3B.c project3B_deque.c
TARGET = project3B

all:
	$(CC) $(CFLAGS) $(TARGET) $(SRCS)

run:
	./$(TARGET) < project3B_input.scr > project3B_output.txt

val:
	valgrind --leak-check=full ./$(TARGET) < project3B_input.scr

zip:
	tar -zcvf proj3B.tgz project3B.c project3B_deque.h project3B_deque.c project3B_input.scr project3B_output.txt Makefile

checker:
	bash project3B_checker