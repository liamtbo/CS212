#ifndef project3B_deque_H
#define project3B_deque_H
#include <stdlib.h>

typedef struct Node {
    void *data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Deque {
    Node *front;
    Node *back;
    int count;
} Deque;

typedef void (*printData)(void *);

Node *newNode(void *data, size_t dataSize);
Deque *createDeque();
void insertFront(Deque *deque, void *data, size_t dataSize);
void insertBack(Deque *deque, void *data, size_t dataSize);
void removeFront(Deque *deque, void *data, size_t dataSize);
void removeBack(Deque *deque, void *data, size_t dataSize);
void freeDeque(Deque *deque);
typedef void (*printData)(void *);
void printDeque(Deque *deque, printData print);
void printStr(void *);
void printLongInt(void *);


#endif