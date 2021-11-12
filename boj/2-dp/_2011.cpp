#include <iostream>
using namespace std;

char s[5001];
int dp[5000];

#define n(i) (s[i] - '0')

int main() {
    cin >> s;

    int i, tmp;
    for (i = 0; s[i]; i++) {
        if (n(i)) {
            dp[i] = i ? dp[i - 1] : 1;
        }
        if (i && 9 < (tmp = 10 * n(i - 1) + n(i)) && tmp < 27) {
            dp[i] = (dp[i] + (i > 1 ? dp[i - 2] : 1)) % 1000000;
        }
    }
    cout << dp[i - 1];
}