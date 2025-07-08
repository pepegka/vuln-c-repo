#include <stdio.h>

int main() {
    char *buffer = (char*)malloc(100 * sizeof(char));
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    sprintf(buffer, "Sample text for buffer.");

    free(buffer);

    printf("Some content: %s\n", buffer);

    return 0;
}