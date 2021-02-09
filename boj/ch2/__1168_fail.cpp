/* segment tree */

#include <cstdio>

int seg[400001];

int init(int l, int r, int idx) {
    if (l == r)
        return seg[idx] = 1;
    int mid = (l + r) / 2;
    return seg[idx] = init(l, mid, 2 * idx) + init(mid + 1, r, 2 * idx + 1);
}

// start부터 end까지의 합
int sum(int start, int end, int l, int r, int idx) {
    if (r < start || end < l)
        return 0;
    if (start <= l && r <= end)
        return seg[idx];
    int mid = (l + r) / 2;
    return sum(start, end, l, mid, 2 * idx) + sum(start, end, mid + 1, r, 2 * idx + 1);
}

void update(int node, int diff, int l, int r, int idx) {
    if (node < l || r < node)
        return;
    seg[idx] += diff;
    if (l == r)
        return;
    int mid = (l + r) / 2;
    update(node, diff, l, mid, 2 * idx), update(node, diff, mid + 1, r, 2 * idx + 1);
}

int find(int start, int k, int N) {
    int end = N;
    int s = sum(start, end, 1, N, 1);
    if (s < k)
        k -= s, start = 1;

    int pre_end = N;
    while (true) {
        s = sum(start, end, 1, N, 1);
        if (s < k)
            k -= s, start = end % N + 1, end = pre_end;
        else {
            if (start == end)
                break;
            pre_end = end, end = (start + end) / 2;
        }
    }
    update(end, -1, 1, N, 1);
    return end;
}


int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    init(1, N, 1);

    int cur = 0, i = N;
    printf("<");
    while (true) {
        cur = find(cur % N + 1, K, N);
        if (!--i) {
            printf("%d", cur);
            break;
        }
        printf("%d, ", cur);
    }
    printf(">");
}