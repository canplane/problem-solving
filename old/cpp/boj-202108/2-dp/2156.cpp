#include <cstdio>
#include <algorithm>
using namespace std;

int _v[10004], _dp[10004];  // 3 + (10000 + 1)

int main() {
    int n;
    int *v = _v + 3, *dp = _dp + 3;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);

    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i - 1], v[i] + dp[i - 2]);
        dp[i] = max(dp[i], v[i] + v[i - 1] + dp[i - 3]);
    }
    printf("%d", dp[n]);
}