#include <cstdio>
#define MAX2(a, b) ((a) > (b) ? (a) : (b))
#define MIN2(a, b) ((a) < (b) ? (a) : (b))
#define MIN_INT (1 << 31)
#define MAX_INT ~MIN_INT

int main()
{
    int n;
    int min = MAX_INT, max = MIN_INT, tmp;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &tmp);
        min = MIN2(min, tmp), max = MAX2(max, tmp);
    }
    printf("%d %d", min, max);
}