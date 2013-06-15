#include <stdio.h>
#include <time.h>

int main()
{
    time_t rawtime = time(NULL);
    struct tm *timeinfo = localtime(&rawtime);
    printf("%s", asctime(timeinfo));
    return 0;
}
