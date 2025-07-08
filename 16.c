#include <stdio.h>

int main() {
    char buffer[50];

    printf("Enter a string: ");
    gets(buffer);

    printf("You entered: %s\n", buffer);
    return 0;
}
