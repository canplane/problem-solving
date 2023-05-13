#include <cstdio>

char s[100];

int main()
{
    /** string length */
    // stdin example: "12345678"
    scanf("%5s", s);    // s = "12345"
    printf("%3s", s);   // "12345" (not "123"!)
}