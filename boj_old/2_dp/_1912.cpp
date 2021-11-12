#include <iostream>
#include <algorithm>
#include <climits>
#define MAX_N 100000

using namespace std;

int a[MAX_N], dp[MAX_N];

int main()
{
    int n, ans;
    int i, j, inter;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    ans = dp[0] = a[0];
    for (i = 1; i < n; i++) {
        dp[i] = max(a[i], dp[i - 1] + a[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
}