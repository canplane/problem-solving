#include <stdio.h>

// segment tree
// 1. N이 2의 제곱 꼴이면 높이(0부터 시작) H가 lg N인 full binary tree. 즉 노드 수는 2 * N - 1.
// 2. N이 2의 제곱 꼴이 아니라면 높이는 ceil(lg N)인 tree.
// 높이가 H인 full binary tree의 노드 수는 2 ^ (H + 1) - 1.
int seg[262144];  // (2 ^ (ceil(lg 100000) + 1 ) - 1) + 1 = 2 ^ 18

int init(int idx, int l, int r) {
    if (l == r)
        return seg[idx] = 1;
    int mid = (l + r) / 2;
    return seg[idx] = init(2 * idx, l, mid) + init(2 * idx + 1, mid + 1, r);
}

// 1번부터 시작해서 합이 sum이 되는 가장 작은 번지의 숫자를 반환. 일치하는 게 없으면 -1 반환
int find(int sum, int max) {
    int idx = 1;
    int l = 1, r = max, mid;
    while (1) {
        if (l == r)
            return sum == seg[idx] ? l : -1;
        mid = (l + r) / 2;
        if (seg[2 * idx] < sum)
            sum -= seg[2 * idx], idx = 2 * idx + 1, l = mid + 1;
        else
            idx = 2 * idx, r = mid;
    }
}

// from번부터 to번까지의 합을 반환
int sum(int idx, int l, int r, int from, int to) {
    if (r < from || to < l)
        return 0;
    if (from <= l && r <= to)
        return seg[idx];
    int mid = (l + r) / 2;
    return sum(2 * idx, l, mid, from, to) + sum(2 * idx + 1, mid + 1, r, from, to);
}

// at번의 값에 diff를 더하여 갱신
void update(int idx, int l, int r, int at, int diff) {
    if (r < at || at < l)
        return;
    seg[idx] += diff;
    if (l == r)
        return;
    int mid = (l + r) / 2;
    update(2 * idx, l, mid, at, diff), update(2 * idx + 1, mid + 1, r, at, diff);
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    init(1, 1, N);

    int cur = K, s;
    printf("<%d", cur), update(1, 1, N, cur, -1);
    while (1) {
        if (!seg[1])
            break;
        s = (sum(1, 1, N, 1, cur) + K) % seg[1];
        cur = find(s ? s : seg[1], N);
        printf(", %d", cur), update(1, 1, N, cur, -1);
    }
    printf(">");
}