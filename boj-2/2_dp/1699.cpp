#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001], N;

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        dp[i] = i;
        for (int x = 1; x * x <= i; x++) {
            dp[i] = min(dp[i], dp[i - x * x] + 1);
        }
    }
    cout << dp[N];
}