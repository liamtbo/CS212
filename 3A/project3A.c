#include "project3A_queue.h"
#include "project3A_queue.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Please provide a file name and a delimiter");
    }

    // reads a file into buffer
    FILE *file = fopen(argv[1], "r+");
    if (file == NULL) {
        printf("Could not open file %s\n", file);
    }
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *buffer = (char *)malloc(file_size * sizeof(char));
    fread(buffer, file_size, 1, file);

    // adding a string to the array
    Queue q;
    initialize(&q);

    // seperates text in file by place /0 at every delimiter postiion
    char *token = strtok(buffer, argv[2]);

    char input[1000][256];
    int input_count = 0;
    while (1) {
        if (token == NULL) {
            break;
        }
        strncpy(input[input_count], token, string_len(token));
        // printf("%s\n", token);
        token = strtok(NULL, argv[2]);
        input_count++;
    }

    printf("=> First enqueuing pass\n");
    for (int i = 0; i < input_count; i++) {
        enqueue(&q, input[i]);
    }

    printf("=> Dequeuing all elements\n");
    char* rem_value;
    for (int i = 0; i < input_count; i++) {
        rem_value = dequeue(&q);
    }

    printf("=> Second enqueuing pass\n");
    for (int i = 0; i < input_count; i++) {
        enqueue(&q, input[i]);
    }

    printf("=> Printing queue\n");
    printQueue(&q);
    printf("Capacity: %d, used: %d\n", q.capacity, q.size);

    printf("=> Calling Queue cleanup\n");
    cleanup(&q);
    free(buffer);
}