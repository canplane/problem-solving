#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

struct cmp_y {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        return (p1.second != p2.second) ? (p1.second < p2.second) : (p1.first < p2.first);
    }
};

int dist(pair<int, int> p1, pair<int, int> p2) {
    return (p2.first - p1.first)*(p2.first - p1.first) + (p2.second - p1.second)*(p2.second - p1.second);
}

int dc(int l, int r) {
    if (l == r)
        return 0x7fffffff;
    if (l + 1 == r)
        return dist(v[l], v[r]);
    
    int mid = (l + r) / 2;
    int min_d = min(dc(l, mid), dc(mid + 1, r));
    
    vector<pair<int, int>> w;
    w.reserve(r - l + 1);
    for (int i = mid; i >= l; i--) {
        if (dist({ v[i].first, 0 }, { v[mid + 1].first, 0 }) >= min_d)
            break;
        w.push_back(v[i]);
    }
    for (int i = mid + 1; i <= r; i++) {
        if (dist({ v[mid].first, 0 }, { v[i].first, 0 }) >= min_d)
            break;
        w.push_back(v[i]);
    }
    sort(w.begin(), w.end(), cmp_y());

    for (int i = 0; i < w.size(); i++) {
        for (int j = i + 1; j < w.size(); j++) {
            if (dist({ 0, w[i].second }, { 0, w[j].second }) >= min_d)
                break;
            min_d = min(min_d, dist(w[i], w[j]));
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
    
    printf("%d", dc(0, N - 1));
}