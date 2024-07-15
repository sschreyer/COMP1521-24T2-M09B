#include <stdio.h>
#include <stdint.h>

uint32_t six_middle_bits(uint32_t u) {
    return (u >> 13) & 0x3f;
}

int main(void) {

    printf("%x\n", six_middle_bits(0x0007e000));

    return 0;
}

