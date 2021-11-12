/*
 * 배치 위치를 먼저 생각하지 말고, 거리가 몇일 때 가능한 위치 수를 보면서 범위를 결정해 나가자.
 */

#include <cstdio>
#include <algorithm>

int coords[200000], N, C;

int search(int l, int r) {
    if (l == r)
        return l;
    long long mid = (l + r) / 2 + 1;
    int n = 1, prev = coords[0];
    for (int i = 1; i < N; i++) {
        if (mid <= coords[i] - prev) {
            prev = coords[i];
            ++n;
        }
    }
    if (n < C)
        return search(l, mid - 1);
    else
        return search(mid, r);
}

int main() {
    scanf("%d %d", &N, &C);
    for (int i = 0; i < N; i++)
        scanf("%d", &coords[i]);
    std::sort(coords, coords + N);
    printf("%d", search(1, 1000000000));
}