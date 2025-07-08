#include <stdio.h>

char* getLocalString() {
    char localString[] = "Hello, World!";
    return localString;
}

int main() {
    char *str = getLocalString();
    printf("%s\n", str);
    return 0;
}
