#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE 65536

void search_stream(FILE *stream, char stream_name[], char search_for[]);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <search_str> [filenames]", argv[0]);
    } else if (argc == 2) {
        search_stream(stdin, "<stdin>", argv[1]);
    } else {
        // loop through 'other' command line args, attempt to open them
        // as files, and search for our 'search_str'
        for (int i = 2; i < argc; i++) {
            FILE *stream = fopen(argv[i], "r");
            if (stream == NULL) {
                fprintf(stderr, 
                        "Failed to open file with name %s, reason is %s", 
                        argv[i], strerror(errno));
                return 1;
            }

            search_stream(stream, argv[i], argv[1]);

            fclose(stream);
        }

    }



    return 0;
}

void search_stream(FILE *stream, char stream_name[], char search_for[]) {
    char buffer[MAX_LINE]; 

    int line_number = 1;
    while (fgets(buffer, MAX_LINE, stream) != NULL) {
        if (strstr(buffer, search_for)) {
            fprintf(stdout, "%s: %d: %s", stream_name, line_number, buffer);
        }

        line_number++;
    }
}