#include <iostream>
#define MAX_N 100

using namespace std;

long long dp[MAX_N + 1] = { 0, 1, 1, 1, 2, 2 };

int main()
{
    int T, N, i;
    for (i = 6; i <= MAX_N; i++) dp[i] = dp[i - 1] + dp[i - 5];
            
    cin >> T;
    while (T--)
        cin >> N, cout << dp[N] << endl;
}