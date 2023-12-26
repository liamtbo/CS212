#include "project3C_hashtable.h"        
#include <stdlib.h>              
#include <string.h>          
#include <stdio.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

/*
Need to add case for word not being in file at all
*/

unsigned int hash(const char *key) {
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = hash * 31 + key[i];
    }
    return hash % BUCKET_SIZE;
}

void initialize(HashTable *ht) {
    for (int i = 0; i < BUCKET_SIZE; i++) {
        ht->bucket[i] = NULL;
    }
    ht->count = 0;
}

Node *createNode(const char *key, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->key = strdup(key); // NEED TO FREE EACH duplicate
    newNode->next = NULL;
    newNode->value = value;
    return newNode;
}

void insert(HashTable *ht, const char *key, int value) {
    Node *newNode = createNode(key, value);
    int hashIndex = hash(key);

    if (ht->bucket[hashIndex] == NULL) {
        ht->bucket[hashIndex] = newNode;
    }
    else {
        Node *currNode = ht->bucket[hashIndex];
        while (currNode->next != NULL) {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }
    ht->count += 1;
}

void get(HashTable *ht, const char *key, int **results, int *count) {

    unsigned int nameHash = hash(key);
    Node *currentNode = ht->bucket[nameHash];
    if (ht->bucket[nameHash] == NULL) {
        return;
    }
    while (1) {
        if (strcmp(currentNode->key, key) == 0) {
            break;
        }
        if (currentNode->next == NULL) {
            return;
        }
        currentNode = currentNode->next;
    } 

    *results = (int *)malloc(sizeof(int) * 100);
    
    while (1) {
        if (strcmp(currentNode->key, key) == 0) {
            // printf("%d\n", currentNode->value);
            (*results)[*count] = currentNode->value;
            (*count)++;
        }
        if (currentNode->next == NULL) {
            break;
        }
        currentNode = currentNode->next;
    } 
}

void freeHashTable(HashTable *ht) {
    Node *curNode;
    Node *tmpNext;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        curNode = ht->bucket[i];
        while(1) {
            if (curNode == NULL) {
                break;
            }
            tmpNext = curNode->next;
            free(curNode->key);
            free(curNode);
            if (ht->bucket[i]->next == NULL) {
                break;
            }
            curNode = tmpNext;
        }
    }
    ht->count = 0;
}

float calculateLoadFactor(HashTable *ht) {
    return (float)ht->count / BUCKET_SIZE;
}

void newLineRem(char *str) {
    while (*str != '\0') {
        if (*str == '\n') {
            *str = '\0';
        }
        if (*str == '\r') {
            *str = '\0';
        }
        str++;
    }
}