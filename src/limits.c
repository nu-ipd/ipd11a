#include <stdio.h>
#include <limits.h>

#define SHOW_ME(Type, Fmt, Min, Max) \
    printf("%-19s %2zu bytes %21" Fmt " to %-21" Fmt "\n", \
           #Type, sizeof(Type), (Type)Min, (Type)Max)

int main(void)
{
    SHOW_ME(signed char,        "hhd", SCHAR_MIN, SCHAR_MAX);
    SHOW_ME(short,              "hd",  SHRT_MIN,  SHRT_MAX);
    SHOW_ME(int,                "d",   INT_MIN,   INT_MAX);
    SHOW_ME(long,               "ld",  LONG_MIN,  LONG_MAX);
    SHOW_ME(long long,          "lld", LLONG_MIN, LLONG_MAX);

    SHOW_ME(unsigned char,      "hhu", 0,         UCHAR_MAX);
    SHOW_ME(unsigned short,     "hu",  0,         USHRT_MAX);
    SHOW_ME(unsigned int,       "u",   0,         UINT_MAX);
    SHOW_ME(unsigned long,      "lu",  0L,        ULONG_MAX);
    SHOW_ME(unsigned long long, "llu", 0LL,       ULLONG_MAX);

    SHOW_ME(char,               "hhd", CHAR_MIN, CHAR_MAX);
}
