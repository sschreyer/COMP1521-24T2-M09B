// remove public write from specified as command line arguments if needed

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void chmod_if_needed(char *pathname);

int main(int argc, char *argv[]) {
    for (int arg = 1; arg < argc; arg++) {
        chmod_if_needed(argv[arg]);
    }
    return 0;
}


void chmod_if_needed(char *pathname) {
    struct stat file_info; 
    if (stat(pathname, &file_info) != 0) {
        perror(pathname);
        exit(1);
    }

    mode_t mode = file_info.st_mode;
    if (!(mode & S_IWOTH)) {
        printf("%s is not publically writable\n", pathname);
        return; 
    }

    mode_t new_mode = mode & ~(S_IWOTH);
    if (chmod(pathname, new_mode) != 0) {
        perror(pathname);
        exit(1);
    }

    printf("Successfully remove 'other' write permission from %s\n", pathname);
}