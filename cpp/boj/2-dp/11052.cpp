#include <iostream>
#include <algorithm>
using namespace std;

int P[1001], N;
int dp[1001];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }

    for (int i = 1; i <= N; i++) {
        dp[i] = P[i];
        for (int j = i - 1; j > 0; j--) {
            dp[i] = max(dp[i], P[j] + dp[i - j]);
        }
    }
    cout << dp[N];
}