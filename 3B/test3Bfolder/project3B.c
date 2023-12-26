#include "project3B_deque.h"
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int main() {
    Deque *long_d = createDeque();
    Deque *str_d = createDeque();

    char input[MAX_SIZE];
    char *endptr;
    long number;

    while (1) {
        printf("Please enter an integer or a string (empty to exit): \n");
        fgets(input, MAX_SIZE, stdin);

        if (strlen(input) == 1) { // 1 for \n character at end of input
            break;
        }
        int lenStr = strlen(input);
        input[lenStr - 1] = '\0';

        // convert to long int
        number = strtol(input, &endptr, 10);
        // checl if input is a string
        if (endptr == input) {

            printf("You entered the string: \"%s\"\n", input);
            // add to front
            if (str_d->count % 2 == 0) {
                insertFront(str_d, input, sizeof(input));
            }
            // add to back
            else {
                insertBack(str_d, input, sizeof(input));
            }
        }
        // then its a number
        else {
            printf("You entered the number: %ld\n", number);
            if (long_d->count % 2 == 0) {
                insertFront(long_d, &number, sizeof(long int *));
            }
            else {
                insertBack(long_d, &number, sizeof(long int *));
            }
        }
    }

    printf("\n");
    printf("Printing string deque\n");
    if (str_d->count > 0) {
        printDeque(str_d, printStr);
    } else {
        printf("\n");
    }
    printf("\n");
    printf("Printing long deque\n");
    if (long_d->count > 0) {
        printDeque(long_d, printLongInt);
    } else {
        printf("\n");
    }
    printf("\n");

    printf("Removing string deque data using count\n");
    if (str_d->count > 0) {
        char removedData[str_d->count][256];
        int counter = str_d->count;
        if (str_d->count % 2 == 0) {
            for (int i = 0; i < counter; i++) {
                if (i % 2 == 0) {
                    removeBack(str_d, removedData[i], 256);
                    printf("Removing %s\n", removedData[i]);
                
                }
                else {
                    removeFront(str_d, removedData[i], 256);
                    printf("Removing %s\n", removedData[i]);            
                }
            }
            printf("\n");
            freeDeque(str_d);
        }
        else {
            removeFront(str_d, removedData[0], 256);
            printf("Removing %s\n", removedData[0]);
            for (int i = 1; i < counter; i++) {
                if (i % 2 == 0) {
                    removeFront(str_d, removedData[i], 256);
                    printf("Removing %s\n", removedData[i]);
                }
                else {
                    removeBack(str_d, removedData[i], 256);
                    printf("Removing %s\n", removedData[i]);            
                }
            }
            printf("\n");
            freeDeque(str_d);
        }
    } else {
        printf("\n");
    }
    printf("Removing long deque data using count\n");
    if (long_d->count > 0) {
        long int removedData[long_d->count];
        int counter = long_d->count;
        if (long_d->count % 2 == 0) {
            for (int i = 0; i < counter; i++) {
                if (i % 2 == 0) {
                    removeBack(long_d, &removedData[i], sizeof(long int *));
                    printf("Removing %ld\n", removedData[i]);
                
                }
                else {
                    removeFront(long_d, &removedData[i], sizeof(long int *));
                    printf("Removing %ld\n", removedData[i]);            
                }
            }
        }
        else{
            removeFront(long_d, &removedData[0], sizeof(long int *));
            printf("Removing %ld\n", removedData[0]);   
            for (int i = 1; i < counter; i++) {
                if (i % 2 == 0) {
                    removeFront(long_d, &removedData[i], sizeof(long int *));
                    printf("Removing %ld\n", removedData[i]);
                
                }
                else {
                    removeBack(long_d, &removedData[i], sizeof(long int *));
                    printf("Removing %ld\n", removedData[i]);            
                }
            }
        }
        freeDeque(long_d);
    }
}

