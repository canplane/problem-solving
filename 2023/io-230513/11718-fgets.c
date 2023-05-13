#include <stdio.h>
#define SZ 101

char buf[SZ];

int main()
{
    while (fgets(buf, SZ, stdin))   fputs(buf, stdout);
}