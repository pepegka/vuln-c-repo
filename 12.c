#include <pthread.h>
#include <stdio.h>

volatile int counter = 0;

void* incrementCounter(void* arg) {
    for (int i = 0; i < 100000; ++i) {
        counter++;
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, incrementCounter, NULL);
    pthread_create(&thread2, NULL, incrementCounter, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final counter value: %d\n", counter);
    return 0;
}
