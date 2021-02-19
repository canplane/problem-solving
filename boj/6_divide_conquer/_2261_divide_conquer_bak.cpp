/* vector */

#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

vector<pair<int, int>> v;

int dist(const pair<int, int>& a, const pair<int, int>& b) {
    return (b.first - a.first)*(b.first - a.first) + (b.second - a.second)*(b.second - a.second);
}

struct cmp_y {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return (a.second != b.second) ? (a.second < b.second) : (a.first < b.first);
    }
};

int dc(int l, int r) {
    if (l == r)
        return 0x7fffffff;
    if (l + 1 == r)
        return dist(v[l], v[r]);
    
    int mid = (l + r) / 2;
    int min_d = min(dc(l, mid), dc(mid + 1, r));
    int d = sqrt(min_d);

    vector<pair<int, int>> w;
    auto lower_x = lower_bound(v.begin(), v.end(), make_pair(v[mid + 1].first - d, -10000));
    auto upper_x = upper_bound(v.begin(), v.end(), make_pair(v[mid].first + d, 10000));
    for (auto it = lower_x; it != upper_x; it++)
        w.push_back(*it);
    sort(w.begin(), w.end(), cmp_y());

    for (auto it_to = w.begin(); it_to != w.end(); it_to++) {
        auto lower_y = lower_bound(w.begin(), w.end(), make_pair(-10000, it_to->second - d), cmp_y());
        for (auto it_from = lower_y; it_from != it_to; it_from++)
            min_d = min(min_d, dist(*it_from, *it_to));
    }
    return min_d;
}

int main() {
    int N;
    scanf("%d", &N);
    v.reserve(N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &v[i].first, &v[i].second);
    sort(v.begin(), v.end());

    printf("%d", dc(0, N - 1));
}