#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Coord { int x, y; };

struct comp {
    bool operator()(const Coord& a, const Coord& b) const {
        if (a.x != b.x)
            return a.x < b.x;
        return a.y < b.y;
    }
};

int main()
{
    int N, i;
    scanf("%d", &N);
    vector<Coord> v(N);
    for (i = 0; i < N; i++)
        scanf("%d %d", &v[i].x, &v[i].y);
    sort(v.begin(), v.end(), comp());
    for (i = 0; i < N; i++)
        printf("%d %d\n", v[i].x, v[i].y);
}