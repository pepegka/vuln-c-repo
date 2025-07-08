#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *buffer = (char*)malloc(sizeof(char));
    if (buffer == NULL) {
        return 2;
    }

    FILE *file = fopen("/etc/passwd", "r");
    if (file == NULL) {
        return -1;
    }

    char firstChar = fgetc(file);
    if (firstChar != EOF) {
        *buffer = firstChar;
        printf("First character in file: %c\n", *buffer);
    }

    fclose(file);
    free(buffer);

    return 0;
}
