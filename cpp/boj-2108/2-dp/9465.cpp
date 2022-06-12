#include <iostream>
#include <algorithm>
using namespace std;

int dp[2][100000 + 1];

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> dp[0][i];
        for (int i = 1; i <= n; i++)
            cin >> dp[1][i];
        
        // col이 n
        for (int i = 2; i <= n; i++) {
            dp[0][i] += max(dp[1][i - 1], dp[1][i - 2]);
            dp[1][i] += max(dp[0][i - 1], dp[0][i - 2]);
        }
        cout << max(dp[0][n], dp[1][n]) << endl;
    }
}