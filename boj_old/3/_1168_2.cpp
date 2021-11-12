#include <cstdio>

int seg[262144];

int init(int l, int r, int idx) {
    if (l == r)
        return seg[idx] = 1;
    int mid = (l + r) / 2;
    return seg[idx] = init(l, mid, 2 * idx) + init(mid + 1, r, 2 * idx + 1);
}
int sum(int from, int to, int l, int r, int idx) {
    if (r < from || to < l)
        return 0;
    if (from <= l && r <= to)
        return seg[idx];
    int mid = (l + r) / 2;
    return sum(from, to, l, mid, 2 * idx) + sum(from, to, mid + 1, r, 2 * idx + 1);
}
void update(int at, int l, int r, int idx) {
    if (r < at || at < l)
        return;
    seg[idx]--;
    if (l == r)
        return;
    int mid = (l + r) / 2;
    update(at, l, mid, 2 * idx), update(at, mid + 1, r, 2 * idx + 1);
}
int find(int sum, int r) {
    int idx = 1, l = 1, mid;
    while (1) {
        if (l == r)
            return (sum == seg[idx]) ? l : -1; 
        mid = (l + r) / 2;
        if (seg[2 * idx] < sum)
            sum -= seg[2 * idx], idx = 2 * idx + 1, l = mid + 1;
        else
            idx = 2 * idx, r = mid;
    }
}

int main() {
    int N, K, cur, s;
    scanf("%d %d", &N, &K);
    
    init(1, N, 1);
    
    cur = K;
    printf("<%d", cur), update(cur, 1, N, 1);
    while (1) {
        if (!seg[1])
            break;
        if (!(s = (sum(1, cur, 1, N, 1) + K) % seg[1]))
            s = seg[1];
        cur = find(s, N);
        printf(", %d", cur), update(cur, 1, N, 1);
    }
    printf(">");
}