#include <iostream>
#define MAX_N 1000

using namespace std;

int memo[MAX_N + 1] = { -1, 1, 2 };

int f(int n) {
    if (memo[n])
        return memo[n];
    return memo[n] = (f(n - 1) + f(n - 2)) % 10007;
    /* 모듈러 연산 : 
        (A + B) mod C = (A mod C + B mod C) mod C
        (A - B) mod C = (A mod C - B mod C) mod C
        AB mod C = ((A mod C)(B mod C)) mod C
     */
}

int main()
{
    int n;
    cin >> n;
    cout << f(n);
}