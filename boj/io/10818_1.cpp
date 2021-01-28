#include <cstdio>
#include <climits>
#include <algorithm>

int main()
{
    int n;
    int min = INT_MAX, max = INT_MIN, tmp;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &tmp);
        min = std::min(min, tmp), max = std::max(max, tmp);
    }
    printf("%d %d", min, max);
}