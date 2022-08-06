#include <iostream>
#include <algorithm>
using namespace std;

int _A[3 + 300 + 1], _dp[3 + 300 + 1];

int main() {
    int *A = A + 3, *dp = _dp + 3;
    int N;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= N; i++) {
        dp[i] = A[i] + max(A[i - 1] + dp[i - 3], dp[i - 2]);
    }
    cout << dp[N];
}