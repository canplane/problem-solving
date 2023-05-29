#include <cstdio>

int len[1000000], N, M;

int search(int l, int r) {
    if (l == r)
        return l;
    long long mid = (l + r) / 2 + 1;
    long long sum = 0;  // big integer! 오버플로우 항상 생각해!
    for (int i = 0; i < N; i++)
        sum += len[i] < mid ? 0 : len[i] - mid;
    if (sum < M)
        return search(l, mid - 1);
    else
        return search(mid, r);
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &len[i]);
    printf("%d", search(0, 1000000000));
}