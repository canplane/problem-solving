#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

int dist(int a, int b) {
    return (a - b)*(a - b);
}
int dist(pair<int, int>& a, pair<int, int>& b) {
    return dist(a.first, b.first) + dist(a.second, b.second);
}

int search(int l, int r, int to, int d) {
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    if (dist(v[mid].first, v[to].first) > d)
        return search(mid + 1, r, to, d);
    else
        return search(l, mid, to, d);
}

int sweep() {
    int min_d;
    int prev_x, cur_x;

    min_d = dist(v[0], v[1]);
    if (v[0].first != v[1].first)
        prev_x = 0, cur_x = 1;
    else
        prev_x = -1, cur_x = 0;

    for (int i = 1; i < v.size(); i++) {
        if (v[i - 1].first != v[i].first) {
            cur_x = i;
            if (prev_x == -1)
                prev_x = search(0, cur_x - 1, cur_x, min_d);
            else
                prev_x = search(prev_x, cur_x - 1, cur_x, min_d);
        }

        if (v[i - 1].first == v[i].first)
            min_d = min(min_d, dist(v[i - 1].second, v[i].second));
        if (prev_x != -1) {
            for (int j = prev_x; j < cur_x; j++) {
                min_d = min(min_d, dist(v[j], v[i]));  //
            }
            prev_x = search(prev_x, cur_x - 1, cur_x, min_d);
        }
    }
    return min_d;
}

int main() {
    int N;
    scanf("%d", &N);
    v.resize(N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &v[i].first, &v[i].second);
    sort(v.begin(), v.end());
    printf("%d", sweep());
}