#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void floating_types(void)
{
    printf("*** Floating-point types ***\n");
    float f  = -5.1e-10;
    double d = -5.1e-10;
    printf("f: %g\n", f);
    printf("d: %g\n", d);
    printf("sizeof f: %zu bytes\n", sizeof f);
    printf("sizeof d: %zu bytes\n", sizeof d);
}

static void signed_integral_types(void)
{
    printf("*** Signed integral types ***\n");
    char c   = -5;
    short s  = -5;
    int i    = -5;
    long l   = -5;
    printf("c: %hhd\n", c);
    printf("s: %hd\n", s);
    printf("i: %d\n", i);
    printf("l: %ld\n", l);
    printf("sizeof c: %zu bytes\n", sizeof c);
    printf("sizeof s: %zu bytes\n", sizeof s);
    printf("sizeof i: %zu bytes\n", sizeof i);
    printf("sizeof l: %zu bytes\n", sizeof l);
}

static void unsigned_integral_types(void)
{
    printf("\n*** Unsigned integral types ***\n");
    unsigned char uc  = -5;
    unsigned short us = -5;
    unsigned int ui   = -5;
    unsigned long ul  = -5;
    printf("uc: %hhu\n", uc);
    printf("us: %hu\n", us);
    printf("ui: %u\n", ui);
    printf("ul: %lu\n", ul);
    printf("sizeof uc: %zu bytes\n", sizeof uc);
    printf("sizeof us: %zu bytes\n", sizeof us);
    printf("sizeof ui: %zu bytes\n", sizeof ui);
    printf("sizeof ul: %zu bytes\n", sizeof ul);
}

static void usage(const char* argv0)
{
    fprintf(stderr, "Usage: %s [floating|signed|unsigned]\n", argv0);
    exit(1);
}

int main(int argc, char* argv[])
{
    if (argc != 2)
        usage(argv[0]);

    if (!strcmp(argv[1], "floating"))
        floating_types();

    else if (!strcmp(argv[1], "signed"))
        signed_integral_types();

    else if (!strcmp(argv[1], "unsigned"))
        unsigned_integral_types();

    else usage(argv[0]);
}
