#include <iostream>
#include <algorithm>
using namespace std;

int dp[100000], maxlen;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> dp[i];

        if (dp[i - 1] > 0) {
            dp[i] += dp[i - 1];
        }
    }

    // 주의! maxsum이 초깃값이면 안 된다.
    maxlen = dp[0];
    for (int i = 1; i < n; i++) {
        maxlen = max(maxlen, dp[i]);
    }
    cout << maxlen;
}