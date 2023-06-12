#include <stdio.h>

int main()
{
    char c;
    while ((c = getchar()) != EOF)  putchar(c);
}
// [f|]getc(stdin), [f|]putc(c, stdout) (can be implemented if not having prefix 'f')