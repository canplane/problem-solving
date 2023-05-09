#include <iostream>
#include <algorithm>
#define MAX_N 300

using namespace std;

int a[MAX_N], dp[MAX_N];

int main()
{
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0] = a[0], dp[1] = a[1] + a[0], dp[2] = a[2] + max(a[1], dp[0]);
    for (i = 3; i < n; i++) {
        dp[i] = a[i] + max(a[i - 1] + dp[i - 3], dp[i - 2]);
    }
    cout << dp[n - 1];
}