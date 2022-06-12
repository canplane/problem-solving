#include <iostream>
using namespace std;

int dp[201][201];

int main() {
    for (int i = 1; i <= 200; i++) {
        dp[i][1] = dp[0][i] = 1;
    }
    for (int i = 1; i <= 200; i++) {
        for (int j = 1; j <= 200; j++) {
            for (int k = 0; k <= i; k++) {
                dp[i][j] = (dp[i][j] + dp[i - k][j - 1]) % 1000000000;
            }
        }
    }

    int N, K;
    cin >> N >> K;
    cout << dp[N][K];
}