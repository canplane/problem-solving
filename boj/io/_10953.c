#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 5

int main()
{
    int t;
    int a, b;

    char line[MAXLEN], *tok;
    scanf("%d", &t);
    printf("%d", t);
    while (t--) {
        fgets(line, MAXLEN, stdin);
        a = atoi(strtok(line, ","));
        b = atoi(strtok(NULL, ","));
        printf("%d\n", a + b);
    }
}