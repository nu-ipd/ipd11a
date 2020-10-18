#include <limits.h>
#include <stdio.h>

void how_about_this_int(int z)
{
    if (z < z + 1) {
        printf("in math, %d < %d\n", z, z + 1);
    } else {
        printf("in C.S., !(%d < %d)\n", z, z + 1);
    }
}

int main(void)
{
    how_about_this_int(0);
    how_about_this_int(INT_MAX);
}
