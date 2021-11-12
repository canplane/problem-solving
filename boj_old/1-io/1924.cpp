#include <cstdio>

const char *days[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

int main()
{
    int m, d, diff = 0;
    scanf("%d %d", &m, &d);

    for (int i = 1; i < m; i++)
        switch (i) {
        case 2:
            diff += 28;
            break;
        case 4: case 6: case 9: case 11:
            diff += 30;
            break;
        default:
            diff += 31;
            break;
        }
    diff += d;
    puts(days[diff % 7]);
}