// 수가 너무 커서 좌표 압축이 필요하다.

#include <cstdio>
#define MAX_NUM 1000000000

int seg[0xf0000000];  // (2^31 - 1) + 1

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
    if (to < l || r < from)
        return 0;
    if (l <= from && to <= r)
        return seg[idx];
    int mid = ((long long)l + r) / 2;
    return sum(2 * idx, l, mid, from, to) + sum(2 * idx + 1, mid + 1, r, from, to);
}

int main() {
    int N, num, cnt = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        cnt += sum(1, 1, MAX_NUM, num + 1, MAX_NUM);
        printf("%d\n", cnt);
        update(1, 1, MAX_NUM, num, 1);
    }
    printf("%d", cnt);
}