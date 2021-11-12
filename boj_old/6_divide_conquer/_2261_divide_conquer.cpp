#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

vector<pair<int, int>> v;

int dist(pair<int, int> a, pair<int, int> b) {
    return pow(b.first - a.first, 2) + pow(b.second - a.second, 2);
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

    vector<pair<int, int>> w;
    for (int i = mid; i >= l; i--) {
        if (pow(v[mid + 1].first - v[i].first, 2) >= min_d)
            break;
        w.push_back(v[i]);
    }
    for (int i = mid + 1; i <= r; i++) {
        if (pow(v[i].first - v[mid].first, 2) >= min_d)
            break;
        w.push_back(v[i]);
    }
    sort(w.begin(), w.end(), cmp_y());

    for (int i = 0; i < w.size(); i++) {
        for (int j = i + 1; j < w.size(); j++) {
            if (pow(w[j].second - w[i].second, 2) >= min_d)
                break;
            min_d = min(min_d, dist(w[i], w[j]));
        }
    }
    return min_d;
}

int main() {
    int N;
    scanf("%d", &N);
    v.resize(N);  // resize 말고 reserve로 하면 인덱스로 접근하면 안 된다.
    for (int i = 0; i < N; i++)
        scanf("%d %d", &v[i].first, &v[i].second);
    sort(v.begin(), v.end());

    printf("%d", dc(0, N - 1));
}