#include <iostream>
using namespace std;

long long dp[31];

int main() {
    dp[2] = 3;
    for (int i = 4; i <= 30; i += 2) {
        dp[i] = 3 * dp[i - 2];
        for (int j = i - 4; j > 0; j -= 2) {
            dp[i] += 2 * dp[j];
        }
        dp[i] += 2;
    }

    int N;
    cin >> N;
    cout << dp[N];
}