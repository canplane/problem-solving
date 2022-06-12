#include <iostream>
#include <algorithm>
#include <climits>
#define MAX_N 100000

using namespace std;

int dp[MAX_N];

int f(int n)
{
    int d = INT_MAX, i;
    if (dp[n]) return dp[n - 1];

    for (i = 1; i * i < n; i++)
        d = min(d, f(n - i * i) + 1);
    if (i * i == n)
        d = 1;
    return dp[n - 1] = d;
}

int main()
{
    int N;
    cin >> N;
    cout << f(N);
}