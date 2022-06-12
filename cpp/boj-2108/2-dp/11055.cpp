#include <iostream>
#include <algorithm>
using namespace std;

int A[1000], dp[1000], maxsum;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        
        dp[i] = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (A[j] < A[i])
                dp[i] = max(dp[i], dp[j]);
        }
        dp[i] += A[i];
        maxsum = max(maxsum, dp[i]);
    }
    cout << maxsum;
}