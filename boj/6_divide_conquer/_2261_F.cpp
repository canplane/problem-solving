#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int dist(pair<int, int>& a, pair<int, int>& b) {
    return (b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second);
}

int solve(vector<pair<int, int>>& v) {
    int min_d = 0x7fffffff;
    int prev_x = 0, cur_x = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i - 1].first != v[i].first) {
            cur_x = i;
            for (int j = prev_x; j <= i; i++) {
                if ((cur_x - j) * (cur_x - j) <= min_d) {
                    prev_x = j;
                    break;
                }
            }
        }
        if (cur_x)
            for (int j = prev_x; j < cur_x; j++)
                min_d = min(min_d, dist(v[j], v[i]));
        min_d = min(min_d, dist(v[i - 1], v[i]));
    }
    return min_d;
}

int main() {
    int N;
    scanf("%d", &N);

    vector<pair<int, int>> points(N);
    int x, y;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);
        points[i] = { x, y };
    }
    sort(points.begin(), points.end());
    for (int i = 0; i < N; i++)
        printf("<%d %d> ", points[i].first, points[i].second);
    printf("\n");
    printf("%d", solve(points));
}