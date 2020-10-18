// Demonstrates weird UB with arrays.
//
// Things to know:
//
//  - `fprintf` is like `printf`, but you get to specify the output
//  “file.” `stderr` is a special output stream for printing errors. It
//  usually goes to the same place as `stdout`, but it's possible to
//  treat them differently if you want.
//
//  - The type `char*` is how C represents a string. We'll see more
//  about this soon.
//
//  - The `main` function can take two arguments:
//
//        int argc;
//        char* argv[];
//
//    `argv` is an array of the command-line arguments passed to the
//    program (where `argv[0]` is the name of the program itself and
//    `argv[1]` is the actual first argument). `argc` is the length
//    of `argv`.
//
//  - `printf` uses format specifier %s to print a string.
//
//  - Function `int atoi(const char*)` (“ASCII to int”) tries to convert
//  a string to an `int`. (The `const` means it won't modify the
//  string.)

#include <stdio.h>
#include <stdlib.h>

int const CAPACITY = 1;

int copy(size_t write_index, size_t read_index)
{
    int array[CAPACITY];
    array[write_index] = 5;
    return array[read_index];
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s WRITE_INDEX READ_INDEX\n", argv[0]);
        exit(1);
    }

    size_t wi = atoi(argv[1]);
    size_t ri = atoi(argv[2]);
    printf("%d\n", copy(wi, ri));
}
