/*
 * mid = (l + r) / 2 면 그 다음은 (l, mid), (mid + 1, r)
 * mid = (l + r) / 2 + 1 면 그 다음은 (l, mid - 1), (mid, r)
 * 
 * 조건을 만족하는 것 중에 최대인 것을 구하려면 ==이 우측, 최소면 좌측
 */

#include <cstdio>

int len[10000], K, N;

int search(int l, int r) {
    if (l == r)
        return l;
    long long mid = (l + r) / 2 + 1;
    int pieces = 0;
    for (int i = 0; i < K; i++)
       pieces += len[i] / mid;
    if (pieces < N)
        return search(l, mid - 1);
    else
        return search(mid, r);  
}

int main() {
    scanf("%d %d", &K, &N);
    for (int i = 0; i < K; i++)
        scanf("%d", &len[i]);
    printf("%d", search(1, 0x7fffffff));
}