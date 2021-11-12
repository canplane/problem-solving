#include <cstdio>

const char *days[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
const int dates[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
    int m, d, diff = 0;
    scanf("%d %d", &m, &d);

    for (int i = 1; i < m; i++)
        diff += dates[i - 1];
    diff += d;
    puts(days[diff % 7]);
}