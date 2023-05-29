#include <iostream>
#include <algorithm>
#define MAX_N 1000

using namespace std;

int a[MAX_N], dp[MAX_N];

int main()
{
    int N, len = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        len = max(len, dp[i]);
    }
    cout << len;
}