#include <iostream>
#include <algorithm>
#define MEMOSZ 1000000

using namespace std;

int memo[MEMOSZ + 1];  // 희한하게 없애도 시간 차이가 없네...

int f(int n)
{
    if (memo[n] || n < 2)
        return 0;
    return memo[n] = min(f(n / 3) + n % 3, f(n / 2) + n % 2) + 1;
}

int main()
{
    int N;
    
    cin >> N;
    cout << f(N);
}