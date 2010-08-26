/**
 * K&R Exercise 1-19.
 * Reversing input a line at a time.
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int getline(char string[], int limit);
void puts_reverse(char *string);

int main()
{
    int len;
    char line[MAXLINE];
    while ((len = getline(line, MAXLINE)) > 0)
        puts_reverse(line);
    return 0;
}

/* K&R, Section 1.9 */
int getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

void puts_reverse(char *s)
{
    int i, slen = 0;
    while (s[slen] != '\0') slen++;

    char r[slen + 1];
    for (i = 0; i < slen; i++)
        r[i] = s[slen - i - 1];

    r[slen] = '\0';
    puts(r);
}
