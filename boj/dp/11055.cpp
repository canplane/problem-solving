#include <iostream>
#include <algorithm>
#define MAX_N 1000

using namespace std;

int a[MAX_N], dp[MAX_N];

int main()
{
    int N, ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i], dp[i] = a[i];
        for (int j = i - 1; j >= 0; j--)
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + a[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
}