#include <stdio.h>
#include <stdlib.h>

static void incrementer(int* i, unsigned* c)
{
    printf("before: %d, %u\n", *i, *c);
    ++c;
    ++i;
    printf("after:  %d, %u\n", *i, *c);
}

int main(int argc, char* argv[])
{
    union {
        int ui;
        unsigned uc;
    } u;

    u.ui = 0;

    incrementer(&u.ui, &u.uc);
}
