// Print every third number from 24 to 42.
#include <stdio.h>

int main(void) {
    // This 'for' loop is effectively equivalent to a while loop.
// for_loop_init:
    int x = 24;
for_loop_cond:
    if (x >= 42) goto for_loop_end;
for_loop_body:
    printf("%d\n", x);

for_loop_incr:
    x += 3;
    goto for_loop_cond;
for_loop_end:

    return 0;
}
