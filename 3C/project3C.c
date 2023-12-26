#include "project3C_hashtable.h"
// #include "project3C_hashtable.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // tolower
#define MAX_SIZE 256


int main() {
    HashTable ht;
    initialize(&ht);
    FILE *file;

    char fileName[256];
    while (1) {
        printf("Enter the filename (or leave blank to quit): ");
        fgets(fileName, MAX_SIZE, stdin);
        if (fileName[0] == '\n') {
            printf("No file entered, exiting program...\n");
            exit(0);
        }
        newLineRem(fileName);
        file = fopen(fileName, "r");
        if (file == NULL) {
            printf("Failed to open file \'%s\'. Please try again.\n", fileName);
            continue;
        }
        break;
    }
    printf("Tokenizing file \'%s\' and building hash bucket...", fileName);

    char tmp[100];
    char *token;
    int lineNum = 1;
    while(fgets(tmp, sizeof(tmp), file) != NULL) { // tmp is a new line each iteration
        newLineRem(tmp);
        token = strtok(tmp, " ");
        while (token != NULL) {
            for (int i = 0; token[i] != '\0'; i++) {
                token[i] = tolower(token[i]);
            }
            insert(&ht, token, lineNum);
            token = strtok(NULL, " "); // gets next word in line
        }
        lineNum++;
    }
    fclose(file);

    printf("done.\n");
    printf("Load factor: %.2f\n", calculateLoadFactor(&ht));

    char searchWord[100];
    int *nameLines = NULL;
    int *searchCounter = (int*)malloc(sizeof(int));
    while (1) {
        printf("Enter a word to search (or leave blank to quit): ");
        fgets(searchWord, MAX_SIZE, stdin);
        if (searchWord[0] == '\n') {
            break;
        }
        for (int i = 0; searchWord[i] != '\0'; i++) {
            searchWord[i] = tolower(searchWord[i]);
        }
        newLineRem(searchWord);
        *searchCounter = 0;
        get(&ht, searchWord, &nameLines, searchCounter);

        if (*searchCounter != 0) {
            printf("Word \'%s\' found at line number(s): ", searchWord);
            for (int i = 0; i < *searchCounter; i++) {
                printf("%d ", nameLines[i]);
            }
            printf("\n");
        }
        else {
            printf("Word \'%s\' not found.\n", searchWord);
        }
    }    
    
    freeHashTable(&ht);
    free(searchCounter);
    free(nameLines);
}