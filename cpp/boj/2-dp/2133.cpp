#include <iostream>
#include <algorithm>
#define MAX_N 30

using namespace std;

int dp[MAX_N + 1] = { 0, 3 };

int f(int n)
{
    int ret;
    if (dp[n - 1]) return dp[n - 1];
    ret = 3 * f(n - 2) + 2;
    for (int i = n - 4; i >= 2; i -= 2) ret += 2 * f(i);
    return dp[n - 1] = ret;
}

int main()
{
    int N, ans = 0;
    cin >> N;
    if (!(N % 2)) ans = f(N);
    cout << ans;
}