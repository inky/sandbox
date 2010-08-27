#include <stdio.h>
#include <stdlib.h>

void iswap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void plot(int x, int y)
{
    printf("(%2d, %2d)\n", x, y);
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

int main()
{
    line(0, 0, 10, 7);
    return 0;
}
