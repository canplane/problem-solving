#include <iostream>
#include <algorithm>
using namespace std;

int A[300], dp[300], N;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    dp[0] = A[0];
    dp[1] = A[1] + dp[0];
    dp[2] = A[2] + max(A[1], dp[0]);
    for (int i = 3; i < N; i++) {
        dp[i] = A[i] + max(dp[i - 3] + A[i - 1], dp[i - 2]);
    }

    cout << dp[N - 1];
}