#include <cstdio>

int A[40], N, S;

// 2^40이므로 시간 초과. 그러나 2^(N / 2)의 2배라면? meet in the middle!
// 2^20일 때는 경우의 수를 모두 둘러볼 수 있었기 때문에 충분히 풀 만 했지만 이 문제는 40이라 안 됨.
int dfs(int i, int sum) {
    int ret = 0;
    if (i && sum == S)
        ret++;
    for (; i < N; i++) {
        ret += dfs(i + 1, sum + A[i]);
    }
    return ret;
}

int main() {
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    printf("%d", dfs(0, 0));
}