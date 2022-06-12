#include <iostream>
using namespace std;

int dp[10000][10] = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};

int main() {
    int sum;
    for (int len = 1; len < 10000; len++) {
        sum = 0;
        for (int dgt = 0; dgt < 10; dgt++) {
            sum = (sum + dp[len - 1][dgt]) % 10007;
            dp[len][dgt] = sum;
        }
    }

    int N;
    cin >> N;
    
    sum = 0;
    for (int dgt = 0; dgt < 10; dgt++) {
        sum = (sum + dp[N - 1][dgt]) % 10007;
    }
    cout << sum;
}