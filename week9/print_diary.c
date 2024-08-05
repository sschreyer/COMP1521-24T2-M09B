// print $HOME/.diary to stdout

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *basename = ".diary";

int main(int argc, char *argv[]) {
    char *home = getenv("HOME");
    if (home == NULL) {
        perror("$HOME");
        return 1;
    }

    int buffer_size = strlen(home) + strlen(basename) + 2;
    char *filename = malloc(buffer_size * sizeof(char));
    snprintf(filename, buffer_size, "%s/%s", home, basename);

    FILE *file = fopen(filename, "r");
    int c;
    // read and printf file to stdout
    while ((c = fgetc(file)) != EOF) {
        fputc(c, stdout);
    }

    fclose(file);
    free(filename);

    return 0;
}