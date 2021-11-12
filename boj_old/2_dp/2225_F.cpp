#include <iostream>
#define MAX_N 200

using namespace std;

int dp[MAX_N + 1];

int f(int n, int dep) {
    int ret = 0;
    if (dep == 1) return 1;
    
    if (dp[n]) return dp[n];
    for (int i = 0; i <= n; i++)
        ret = (ret + f(i, dep - 1)) % 1000000000;
    return dp[n] = ret;
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << f(N, K);
}