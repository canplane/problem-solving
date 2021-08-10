#include <iostream>
using namespace std;

int dp[10 + 1];

int main() {
    dp[1] = 1;
    dp[2] = 1 + dp[1];
    dp[3] = 1 + dp[2] + dp[1];
    for (int i = 4; i < 11; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        cout << dp[n] << endl;
    }
}