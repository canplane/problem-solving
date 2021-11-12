/*
 * ==을 우측으로 보내면 조건을 만족하는 것 중에 제일 오른쪽 위치를 반환. 단 ==이 있는 곳에 mid를 포함해야 할 것. 
 */

#include <cstdio>
#include <algorithm>

int cards[500000], N;

int l_search(int n, int l, int r) {
    if (l == r)
        return cards[l] == n ? l : -1;
    long long mid = (l + r) / 2;
    if (cards[mid] < n)
        return l_search(n, mid + 1, r);
    else
        return l_search(n, l, mid);
}
int r_search(int n, int l, int r) {
    if (l == r)
        return cards[l] == n ? l : -1;
    long long mid = (l + r) / 2 + 1;
    if (cards[mid] > n)
        return r_search(n, l, mid - 1);
    else
        return r_search(n, mid, r);
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
        int l = l_search(tmp, 0, N - 1);
        printf("%d ", l == -1 ? 0 : r_search(tmp, l, N - 1) - l + 1);
    }
}