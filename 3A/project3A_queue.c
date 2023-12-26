#include "project3A_queue.h"
#include <string.h>

// done
void initialize(Queue* q) {
    q->array = (char**)malloc(8 * sizeof(char*)); // allocating memory for 8 str with potential length of 256
    for (int i = 0; i < 8; i++) {
        q->array[i] = (char*)malloc((256) * sizeof(char)); 
    }
    q->front = 0; // queue front index, initially 0
    q->rear = 0; // queue rear index, initally 0
    q->capacity = Q_SIZE; // queue capacity, initiallly 8
    q->size = 0; //queue array popilated count, initially 0
}

int string_len(char *value) {
        int string_len = 0;
        while (*value != '\0') {
            string_len += 1;
            value += 1;
        }
    return string_len;
}

void cleanup(Queue* q) {
     for (int i = 0; i < q->capacity; i++) {
        free(q->array[i]);
    }
    free(q->array);
    printf("Cleaning up queue\n");
}

// done
int isFull(Queue* q) {
    if (q->size == q->capacity) {
        return 1;
    }
    return 0;
}

int isEmpty(Queue* q){
    if (q->size == 0) {
        return 1;
    }
    return 0;
}

void resize(Queue* q) {
    q->capacity *= 2;
    printf("Resizing queue to %d\n", q->capacity);
    char** new_array = (char**)malloc(q->capacity * sizeof(char*));
    for (int i = 0; i < q->capacity; i++) {
        new_array[i] = (char*)malloc(256 * sizeof(char));
    }

    // Copy elements from the old array to the new array
    // use and increment font to accounr for the case where rear < front
    int index = q->front;
    for (int i = 0; i < q->size; i++) {
        strncpy(new_array[i], q->array[index], string_len(q->array[index]));
        index = (index + 1) % q->capacity;
    }

    // Free the old array elements
    for (int i = 0; i < q->capacity / 2; i++) {
        free(q->array[i]);
    }
    free(q->array);

    q->front = 0;
    q->rear = q->size;
    q->array = new_array;
}


void enqueue(Queue* q, char* value) {
    if (isFull(q)) {
        resize(q);
    }
    int len = string_len(value);
    strncpy(q->array[q->rear], value, len);
    printf("Enqueued (%d): %s\n", q->rear, value);
    q->size++;
    q->rear++;
    if (q->rear == q->capacity) {
        q->rear = 0;
    }
}


char* dequeue(Queue* q) {
    char* str = q->array[q->front];
    printf("Dequeued (%d): %s\n", q->front, str);
    if (q->front != q->capacity -1) {
        q->front++;
    }
    else {
        q->front=0;
    }
    q->size--;
    return str;
}

void printQueue(Queue* q) {
    printf("%d: %s\n", q->front, q->array[q->front]);
    int index = q->front + 1;

    if (index == q->capacity)   index = 0;

    while (index != q->rear) {
        printf("%d: %s\n", index, q->array[index]);
        index = index == q->capacity ? 0 : index + 1;
    }
}
