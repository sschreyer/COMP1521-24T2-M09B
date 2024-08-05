#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_LINE 1024

void *feed_me(void *arg) {
    char *message = arg;
    while (true) {
        printf("%s", message);
        sleep(1);
    }

    return NULL;
}

int main(void) {
    pthread_t thread_id;

    char *message = "Feed me input\n";
    pthread_create(&thread_id, NULL, feed_me, message);

    char buffer[MAX_LINE];
    while (fgets(buffer, MAX_LINE, stdin) != NULL) {
        printf("you entered: %s", buffer);
    }

    pthread_cancel(thread_id);

    return 0;
}