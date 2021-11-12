#include <iostream>
using namespace std;

long long dp[90][2] = {
    { 0, 1 },
};

int main() {
    for (int i = 1; i < 90; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
    
    int N;
    cin >> N;
    cout << dp[N - 1][0] + dp[N - 1][1];
}