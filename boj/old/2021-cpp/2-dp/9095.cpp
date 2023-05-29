#include <iostream>
#define MAX_N 10

using namespace std;

int dp[MAX_N] = { 1, 2, 4 };

int f(int n) {
    if (dp[n - 1])
        return dp[n - 1];
    return dp[n - 1] = f(n - 1) + f(n - 2) + f(n - 3);
}

int main()
{
    int T, n;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        cout << f(n) << endl;
    }
}
