#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char inputPassword[50];
    const char *hardcodedPassword = "secret123";

    printf("Enter password to access the system file: ");
    fgets(inputPassword, sizeof(inputPassword), stdin);
    inputPassword[strcspn(inputPassword, "\n")] = 0;

    if (strcmp(inputPassword, hardcodedPassword) == 0) {
        printf("Access granted. Reading system file...\n");

        const char *criticalFilePath = "/etc/passwd.conf";
        FILE *file = fopen(criticalFilePath, "r");

        if (file == NULL) {
            perror("Error opening file");
        } else {
            char buffer[256];
            while (fgets(buffer, sizeof(buffer), file) != NULL) {
                printf("%s", buffer);
            }
            fclose(file);
        }
    } else {
        printf("Access denied.\n");
    }

    return 0;
}
