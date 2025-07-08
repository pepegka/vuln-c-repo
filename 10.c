#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* innerArray;
    int size;
} MyStruct;

int main() {
    int numStructs = 5;
    MyStruct **outerArray = (MyStruct**)malloc(numStructs * sizeof(MyStruct*));

    if (outerArray == NULL) {
        perror("Failed to allocate memory for outerArray");
        return 1;
    }

    for (int i = 0; i < numStructs; ++i) {
        outerArray[i] = (MyStruct*)malloc(sizeof(MyStruct));
        if (outerArray[i] == NULL) {
            perror("Failed to allocate memory for outerArray element");
            for (int j = 0; j < i; j++) {
                free(outerArray[j]->innerArray);
                free(outerArray[j]);
            }
            free(outerArray);
            return 1;
        }
        
        outerArray[i]->size = 10;
        outerArray[i]->innerArray = (int*)malloc(outerArray[i]->size * sizeof(int));
        if (outerArray[i]->innerArray == NULL) {
            perror("Failed to allocate memory for innerArray");
            for (int j = 0; j <= i; j++) {
                free(outerArray[j]);
            }
            free(outerArray);
            return 1;
        }

        for (int j = 0; j < outerArray[i]->size; j++) {
            outerArray[i]->innerArray[j] = j;
        }
    }

    for (int i = 0; i < numStructs; ++i) {
        free(outerArray[i]);
    }
    free(outerArray);

    return 0;
}
