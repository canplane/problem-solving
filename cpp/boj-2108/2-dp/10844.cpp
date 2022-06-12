#include <iostream>
using namespace std;

int dp[100 + 1][10] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
};  // len, dgt

int main() {
    int N;
    cin >> N;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0)
                dp[i][j] = dp[i - 1][j + 1];
            else if (j == 9)
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
    }
    
    int ans = 0;
    for (int j = 0; j <= 9; j++)
        ans = (ans + dp[N][j]) % 1000000000;
    cout << ans;
}