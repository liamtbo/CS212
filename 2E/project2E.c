
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    if (argc < 3) {
        return 1;
    }

    FILE *file = fopen(argv[1], "r+"); // opens the file with read privledges
    if (file == NULL) {
        printf("Error message: \"%s\" is not a valid file\n", argv[1]);
        return 1;
    }
    fseek(file, 0, SEEK_END); // sets reference position to end of file
    int file_size = ftell(file          ); // returns the full size of the file
    fseek(file, 0, SEEK_SET); // sets the reference position back to the start of the file

    // printf("%d size\n", file_size);

    char *buffer = (char *)malloc(file_size * sizeof(char)); // allocates memory for the file
    fread(buffer, file_size, 1, file);

    // for counting each argument occurence. calloc creates a list full of 0 of length()
    int *count = (int *) calloc(argc - 2, sizeof(int));

    for (int j = 2; j < argc; j++) {
        
        char *arg_word = argv[j]; // gives the current argument word, argv is an array of pointers
        
        // for buiding each word
        char *word_builder = (char *)malloc(40 * sizeof(char));
        // for word builder, needs to be on heap bc it gets reset inside a scope multiple times
        int *letter_index = (int *)malloc(40 * sizeof(int));
        *letter_index = 0;

        // loop over each letter in the text file
        for (int i = 0; i < file_size; i++) {
            if (buffer[i] == '.' || buffer[i] == ',' || buffer[i] == ' ' || buffer[i] == '\n') {

                // check if space before word
                if (strlen(arg_word) == strlen(word_builder)) {

                    // checks if built word is the same as argv[j]
                    if (strncmp(word_builder, arg_word, strlen(arg_word)) == 0) {
                        count[j - 2] += 1; // count argword occurencce in   text. count[0] for argword1, count[1] for argword2 ...
                    }
                }
                // clear each var for next word
                *letter_index = 0;   
                for (int l = 0; word_builder[l] != '\0'; l++) {
                    word_builder[l] = '\0';
                }
            }
            else {
                word_builder[*letter_index] = buffer[i]; 
                *letter_index += 1;
            }
        }
        free(word_builder);
        free(letter_index);
    }
    for (int i = 0; i < argc - 2; i++) {
        printf("The word \"%s\" occurs %d times.\n", argv[i+2], count[i]);
    }
    fclose(file);
    free(buffer);
    free(count);
    return 0;
}
