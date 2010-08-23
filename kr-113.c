/**
 * K&R Exercise 1-13.
 * Print a histogram of the lengths of words in stdin.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 20

int main()
{
    int hist[MAX_LENGTH], i, j, c, len = 0;

    for (i = 0; i < MAX_LENGTH; i++) hist[i] = 0;

    while ((c = getchar()) != EOF) {
        switch (c) {
            case ' ':
            case '\n':
            case '\t':
                if (len > 0) hist[len - 1]++;
                len = 0;
                break;
            default:
                if (len < MAX_LENGTH) len++;
        }
    }

    for (i = 0; i < MAX_LENGTH; i++) {
        if (i < MAX_LENGTH - 1) printf("%2d  | ", i + 1);
        else printf("%2d+ | ", MAX_LENGTH);

        c = (hist[i] <= 70) ? hist[i] : 70;
        for (j = 0; j < c; j++) putchar('#');
        if (hist[i] > 70) putchar('+');
        putchar('\n');
    }

    return 0;
}
