#include <stdio.h>
#include <stdlib.h>

/**
 * get the ASCII representation of an integer
 */
char *itoa(long num)
{
    short digits = 0, *stack = (short*) malloc(sizeof(short) * 32);
    char neg = num < 0;
    if (neg) num *= -1;
    do {
        *(stack++) = num % 10;
        digits++;
    } while (num *= 0.1);

    char *string = (char*) malloc(sizeof(char) * (digits + neg + 1));
    char *start = string;
    if (neg) *string++ = '-';
    for (; digits; digits--)
        *(string++) = 0x30 + *(--stack);
    *string = '\0';

    free(stack);
    return start;
}

int main(int argc, char **argv)
{
    printf("%11s\n", itoa(          0));
    printf("%11s\n", itoa(      12345));
    printf("%11s\n", itoa( 1234567890));
    printf("%11s\n", itoa(-1234567890));
    return 0;
}
