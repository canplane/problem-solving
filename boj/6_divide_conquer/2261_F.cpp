#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int dist(pair<int, int>& a, pair<int, int>& b) {
    return (b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second);
}

/*int solve(vector<pair<int, int>>& v) {
    int min_d = 0x7fffffff;
    int prev_x_l, prev_x_r = -1, prev_y = -1;
    for (int i = 1; i < v.size(); i++) {
        if (v[i - 1].first != v[i].first) {
            prev_x_l = prev_x_r + 1, prev_x_r = i - 1;
            prev_y = -1;
        }
        else if (v[i - 1].second != v[i].second)
            prev_y = i - 1;

        if (prev_x_r != -1)
            for (int j = prev_x_l; j <= prev_x_r; j++)
                min_d = min(min_d, dist(v[j], v[i]));
        if (prev_y != -1)
            min_d = min(min_d, dist(v[prev_y], v[i]));
    }
    return min_d;
}*/
int solve(vector<pair<int, int>>& v) {
    int min_d = 0x7fffffff;
    int prev_x_l, prev_x_r = -1;
    for (int i = 1; i < v.size(); i++) {
        if (v[i - 1].first != v[i].first)
            prev_x_l = prev_x_r + 1, prev_x_r = i - 1;
        
        if (prev_x_r != -1)
            for (int j = prev_x_l; j <= prev_x_r; j++)
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
    printf("%d", solve(points));
}