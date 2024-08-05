#include <stdio.h>

#define MAX_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "w");
    if (file == NULL) {
        fprintf(stderr, "%s", argv[0]);
        perror(argv[1]);
    }

    // char buffer[MAX_SIZE];
    // fgets(buffer, MAX_SIZE, stdin);

    // fputs(buffer, file);

    int c; 
    while ((c = fgetc(stdin)) != EOF) {
        fputc(c, file);
        if (c == '\n') {
            break;
        }
    }

    fclose(file);

    return 0;
}