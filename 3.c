#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer = (char*)malloc(5 * sizeof(char));

    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    strcpy(buffer, "What a beautiful string!");

    printf("%s\n", buffer);

    free(buffer);
    return 0;
}
