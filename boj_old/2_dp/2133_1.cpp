#include <iostream>
#define MAX_N 30

using namespace std;

int dp[MAX_N + 1] = { 1, 0, 3 };

int main() {
    int N, i, j;
    cin >> N;
    if (!(N % 2))
        for (i = 4; i <= N; i += 2)
            dp[i] = 4 * dp[i - 2] - dp[i - 4];
    cout << dp[N];
}