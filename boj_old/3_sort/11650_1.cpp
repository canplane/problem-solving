#include <cstdio>
#include <algorithm>
#define MAX_N 100000

using namespace std;

struct Coord { int x, y; } coords[MAX_N];

bool comp(const Coord& a, const Coord& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int main()
{
    int N, i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d %d", &coords[i].x, &coords[i].y);
    sort(coords, coords + N, comp);
    for (i = 0; i < N; i++)
        printf("%d %d\n", coords[i].x, coords[i].y);
}