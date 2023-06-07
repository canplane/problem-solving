#include <cstdio>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

vector<pair<int, int>> v;

struct cmp_y {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        return (p1.second != p2.second) ? (p1.second < p2.second) : (p1.first < p2.first);
    }
};

int dist(pair<int, int> p1, pair<int, int> p2) {
    return pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2);
}

int sweep() {
    int min_d = dist(v[0], v[1]);
    set<pair<int, int>, cmp_y> candidates = { v[0], v[1] };
    int start = 0;
    for (int i = 2; i < v.size(); i++) {
        while (start < i) {
            if (pow(v[i].first - v[start].first, 2) < min_d)
                break;
            candidates.erase(v[start]);
            start++;
        }
        int d = sqrt(min_d);
        auto lower = candidates.lower_bound({ -10000, v[i].second - d });
        auto upper = candidates.upper_bound({ 10000, v[i].second + d });
        for (auto it = lower; it != upper; it++)
            min_d = min(min_d, dist(v[i], *it));
        candidates.insert(v[i]);
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