#include <stdio.h>
#include <limits.h>

int main() {
    int some_number = INT_MAX;
    int result = some_number + 1;

    printf("Some number: %d\n", some_number);
    printf("Some number + 1: %d\n", result);

    return 0;
}