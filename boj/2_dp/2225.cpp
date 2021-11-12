#include <iostream>
using namespace std;

int dp[201][201];

int main() {
    int N, K;
    cin >> N >> K;

    for (int j = 1; j <= K; j++) {
        dp[0][j] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000000;
        }
    }

    cout << dp[N][K];
}