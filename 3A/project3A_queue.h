
#ifndef project3A_queue_H
#define project3A_queue_H

#define Q_SIZE 8
#define MAX_LEN 256

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char** array;
    int front;
    int rear;
    int capacity;
    int size;
} Queue;


void initialize(Queue* q);
void cleanup(Queue* q);
int isFull(Queue* q);
int isEmpty(Queue* q);
void resize(Queue* q);
void enqueue(Queue* q, char* value);
char* dequeue(Queue* q);
void printQueue(Queue* q);

#endif // project3A_queue.h