#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

void *thread_run(void *data) {
    char *message = data;
    while (true) {
        printf("%s", message);
    }

    return NULL;
}

int main(void) {
    char *thread_message = "Hello\n";

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread_run, thread_message);

    while (true) {
        printf("%s", "there!\n");
    }

    // not stricly necessary (but good practice)
    pthread_join(thread_id, NULL);

    return 0;
}