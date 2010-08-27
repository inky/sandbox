#include <stdio.h>
#include <stdlib.h>

#define MAX_X 500
#define MAX_Y 500

char img[MAX_X][MAX_Y];

void iswap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void plot(int x, int y)
{
    if (x < 0 || y < 0 || x > MAX_X || y > MAX_Y) return;
    img[x][y] = 1;
}

/* Bresenham's line algorithm */
void line(int x0, int y0, int x1, int y1)
{
    int steep = abs(y1 - y0) > abs(x1 - x0);
    if (steep) {
        iswap(&x0, &y0);
        iswap(&x1, &y1);
    }
    if (x0 > x1) {
        iswap(&x0, &x1);
        iswap(&y0, &y1);
    }
    int deltax = x1 - x0,
        deltay = abs(y1 - y0),
        err = deltax >> 1,
        ystep = (y0 < y1) ? 1 : -1,
        x, y = y0;
    for (x = x0; x <= x1; x++) {
        if (steep) plot(y, x);
        else plot(x, y);
        err -= deltay;
        if (err < 0) {
            y += ystep;
            err += deltax;
        }
    }
}

/* http://en.wikipedia.org/wiki/Netpbm_format */
void printpbm()
{
    int x, y;
    puts("P1");
    printf("%d %d\n", MAX_X, MAX_Y);
    for (y = 1; y <= MAX_X; y++) {
        for (x = 1; x <= MAX_Y; x++) {
            putchar(img[x][y] ? '0' : '1');  // white on black
            if (x < MAX_X) putchar(' ');
        }
        putchar('\n');
    }
}

int main()
{
    // draw some lines
    int x, y;
    int incr_x = MAX_X * 0.1, incr_y = MAX_Y * 0.1;
    int mid_x = MAX_X >> 1, mid_y = MAX_Y >> 1;
    for (x = 0; x <= MAX_X; x += incr_x) {
        for (y = 0; y <= MAX_Y; y += incr_y) {
            line(x, y, x + MAX_X, y + MAX_Y);
            if (x != mid_x && y != mid_y)
                line(mid_x, mid_y, x, y);
        }
    }
    // output in PBM format
    printpbm();
    return 0;
}
