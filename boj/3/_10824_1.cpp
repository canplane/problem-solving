// 64비트에서는 long == long long == 8bytes
// C는 atol(), atoll() : <cstdlib>, char *
// C++은 stol(), stoll() : <string>, string

#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() {
    char a[15], b[8], c[15], d[8];
    scanf("%s %s %s %s", a, b, c, d);
    strcat(a, b), strcat(c, d);
    printf("%ld\n", atoll(a) + atoll(c));
}