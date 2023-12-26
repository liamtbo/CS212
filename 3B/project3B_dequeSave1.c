#include "project3B_deque.h"
#include <stddef.h> // for size_t -> represents the size of objexts in memory, such as butes occupied by an array or the length of a string
#include <stdio.h> // for fprintf, stderr
#include <stdlib.h> // for exit failure
#include <string.h> // for memcpy
#include <stddef.h> // for size_t

// done
Node *newNode(void *data, size_t dataSize) {
    Node* node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Error allocating memory for node");
        exit(EXIT_FAILURE);
    }
    node->data = malloc(dataSize);
    if (node->data == NULL) {
        fprintf(stderr, "Error allocating memory for node data");
        exit(EXIT_FAILURE);
    }
    memcpy(node->data, data, dataSize);
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// done
Deque *createDeque() {
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    if (deque == NULL) {
        fprintf(stderr, "Error allocating memory for deque.\n");
        exit(EXIT_FAILURE);
    }
    deque->front = NULL;
    deque->back = NULL;
    deque->count = 0;

    return deque;
}

// done
void insertFront(Deque *deque, void *data, size_t dataSize){
    Node *node = newNode(data, dataSize);
    // no prior nodes exist
    if (deque->front == NULL) {
        deque->front = node;
        deque->back = node;
    }
    // prior front node exist
    else {
        Node *prev_front = deque->front;
        prev_front->prev = node;
        node->next = prev_front;
        deque->front = node;
    }
    deque->count += 1;
}

// done
void insertBack(Deque *deque, void *data, size_t dataSize) {
    Node *node = newNode(data, dataSize);
    // no prior back node exists
    if (deque->back == NULL) {
        deque->back = node;
        deque->back->prev = deque->front;
        if (deque->front != NULL) {
            deque->front->next = deque->back;
        }
    }
    // prior back node exists
    else {
        Node *prev_back = deque->back;
        prev_back->next = node;
        node->prev = prev_back;
        deque->back = node;
    }
    deque->count += 1;
}

void removeFront(Deque *deque, void *data, size_t dataSize) {
    if (deque->count == 0) {
        // data = NULL;
        return;
    } else if (deque->count == 1) {
        Node * cur = deque->front;
        void *removed_data = deque->front->data;
        memcpy(data, removed_data, dataSize);
        deque->front = deque->back = NULL;
        deque->count = 0;
        free(cur->data);
        free(cur);
        return;
    }
    Node *cur = deque->front;
    void *removed_data = deque->front->data;
    memcpy(data, removed_data, dataSize);
    deque->front = deque->front->next;
    deque->front->prev = NULL;
    deque->count -= 1;
    free(cur->data);
    free(cur);
}

void removeBack(Deque *deque, void *data, size_t dataSize){
    if (deque->count == 1){
        // data = NULL;
        deque->back = deque->front;
        return;
    }
    else if (deque->count < 4) {
        Node *curr = deque->back;
        void *removed_data = curr->data;
        memcpy(data, removed_data, dataSize);
        deque->count -= 1;
        deque->back = deque->back->prev;
        deque->front->next = NULL;
        free(curr->data);
        free(curr);
        return;
    }
    Node *curr = deque->back;
    void *removed_data = curr->data;
    memcpy(data, removed_data, dataSize);
    deque->back = curr->prev;
    deque->back->next = NULL;
    deque->count -= 1;
    free(curr->data);
    free(curr);

}

void freeDeque(Deque *deque) {
    free(deque);
}


typedef void (*printData)(void *);

// done
void printLongInt(void *data) {
    long int *value = (long int *)data;
    printf("%ld ", *value);
}

// done
void printStr(void *data) {
    char *value = (char *)data;
    printf("%s ", value);
}

// done
void printDeque(Deque *deque, printData print) {
    Node *currFront = deque->front;
    while (1) {
        print(currFront->data);
        if (currFront->next == NULL) {
            break;
        }
        currFront = currFront->next;
    }
    printf("\n");
}

// doesnt work with three entries not sure why