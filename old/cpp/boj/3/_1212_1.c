#include <stdio.h>

char s[333335];

int main() {
    int o;
    scanf("%s", s);
    
    o = s[0] - '0';
    if (o & 4)
        printf("1%d%d", (o & 2) == 2, o & 1);
    else if (o & 2)
        printf("1%d", o & 1);
    else
        printf("%d", o & 1);
    for (int i = 1; s[i]; i++) {
        o = s[i] - '0';
        printf("%d%d%d", (o & 4) == 4, (o & 2) == 2, o & 1);
    }
}