/* inversion counting - 세그먼트 트리 + 좌표 압축 */

#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int seg[1048576];  // (2 ^ (ceil(lg 500000) + 1) - 1) + 1 == 2 ^ 20 == 1 << 20

void update(int idx, int l, int r, int at, int diff) {
    if (at < l || r < at)
        return;
    seg[idx] += diff;
    if (l == r)
        return;
    int mid = ((long long)l + r) / 2;
    update(2 * idx, l, mid, at, diff), update(2 * idx + 1, mid + 1, r, at, diff);
}

int sum(int idx, int l, int r, int from, int to) {
    if (r < from || to < l)
        return 0;
    if (from <= l && r <= to)
        return seg[idx];
    int mid = ((long long)l + r) / 2;
    return sum(2 * idx, l, mid, from, to) + sum(2 * idx + 1, mid + 1, r, from, to);
}

int main() {
    int N;
    scanf("%d", &N);

    vector<pair<int, int>> v(N); 
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        v[i] = {num, i};
    }
    sort(v.begin(), v.end());

    vector<int> w(N);
    for (int i = 0; i < N; i++)
        w[v[i].second] = i + 1;  // 좌표 압축
    
    long long cnt = 0;  // 최대 499999 * (499999 + 1) / 2 > INT_MAX
    for (int i = 0; i < N; i++) {
        int num = w[i];
        cnt += sum(1, 1, N, num + 1, N);
        update(1, 1, N, num, 1);
    }
    printf("%lld", cnt);
}