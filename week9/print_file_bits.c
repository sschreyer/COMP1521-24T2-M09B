#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    int32_t num;
    while (fscanf(file, "%x", &num) != EOF) {
        int32_t result = num & 0xFF;

        if (result & (1u << 7)) {
            result |= 0xFFFFFF00;
        }

        printf("%d\n", result);
    }


    return 0; 
}