/*
 * "Yeah, Garbage, okay, gimme Garbage..."
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BYTECOUNT 1400000
int main()
{
    int i;
    srand(time(NULL));
    for (i = 0; i < BYTECOUNT; i++)
        putchar(rand() % 256);
    return 0;
}
