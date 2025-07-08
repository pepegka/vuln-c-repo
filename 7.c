#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    char userInput[256];
    char command[300] = "echo ";

    printf("Enter a command: ");
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\n")] = 0;

    strcat(command, userInput);

    system(command);

    return 0;
}
