#include <stdio.h>

#define IN  1
#define OUT 0

/**
 * K&R Exercise 1-12.
 * Read from stdin and write to stdout one word per line.
 */
int main()
{
    int c, state = OUT;

    while ((c = getchar()) != EOF) {
        switch (c) {
            case ' ':
            case '\n':
            case '\t':
                if (state == IN) putchar('\n');
                state = OUT;
                break;
            default:
                if (state == OUT) state = IN;
        }
        if (state == IN) putchar(c);
    }
    return 0;
}
