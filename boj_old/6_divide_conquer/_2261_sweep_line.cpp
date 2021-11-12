#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

int dist(pair<int, int> a, pair<int, int> b) {
    return (b.first - a.first)*(b.first - a.first) + (b.second - a.second)*(b.second - a.second);
}

struct cmp_y {
    template <typename T>
    bool operator()(const T& a, const T& b) const {
        return (a.second != b.second) ? (a.second < b.second) : (a.first < b.first);
    }
};

int main() {
    int N;
    scanf("%d", &N);
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &v[i].first, &v[i].second);
    sort(v.begin(), v.end());

    set<pair<int, int>, cmp_y> candidates = { v[0], v[1] };
    int start = 0;
    int ans = dist(v[0], v[1]);

    for (int i = 2; i < N; i++) {
        auto now = v[i];
        while (start < i) {
            auto p = v[start];
            int x = now.first - p.first;
            if (x*x > ans) {
                candidates.erase(p);
                ++start;
            } else
                break;
        }

        int d = (int)sqrt(ans);
        auto lower = candidates.lower_bound({ -10000, now.second - d });
        auto upper = candidates.upper_bound({ 10000, now.second + d });
        for (auto it = lower; it != upper; it++)
            ans = min(ans, dist(*it, now));
        candidates.insert(now);
    }
    printf("%d", ans);
}