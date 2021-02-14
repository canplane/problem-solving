#include <cstdio>
#include <algorithm>

int cards[500000], N;

int search(int n, int l, int r) {
    if (l > r)
        return 0;
    long long mid = (l + r) / 2;
    if (cards[mid] > n)
        return search(n, l, mid - 1);
    if (cards[mid] < n)
        return search(n, mid + 1, r);
    return 1;
}

int main() {
    int M, tmp;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &cards[i]);
        
    std::sort(cards, cards + N);

    scanf("%d", &M);
    while (M--) {
        scanf("%d", &tmp);
        printf("%d ", search(tmp, 0, N - 1));
    }
}