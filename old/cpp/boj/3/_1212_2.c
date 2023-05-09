#include <stdio.h>

char s[333335];

int main() {
    int o;
    scanf("%s", s);
    
    o = s[0] - '0';
    printf("%d", 100 * ((o & 4) == 4) + 10 * ((o & 2) == 2) + (o & 1));
    for (int i = 1; s[i]; i++) {
        o = s[i] - '0';
        printf("%03d", 100 * ((o & 4) == 4) + 10 * ((o & 2) == 2) + (o & 1));
    }
}