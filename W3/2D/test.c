#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse_string(char *s) {
    int count = 0;
    while(*s) {
        s++;
        count++;
    }
    s -= count;
    char tmp;
    for (int i = 0; i < count / 2; i++) {
        tmp = s[i];
        s[i] = s[count - i - 1];
        s[count - i - 1] = tmp;
    }
    printf("%s\n", s); 
}

int main() {
    char str[] = "banana";
    reverse_string(str);
}
