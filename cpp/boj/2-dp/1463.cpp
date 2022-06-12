#include <iostream>
#define MEMOSZ 1000000

using namespace std;

int memo[MEMOSZ + 1];

int main()
{
    int N;

    cin >> N;
    for (int i = 2; i <= N; i++) {
        memo[i] = memo[i - 1];
        if (!(i % 3))
            memo[i] = min(memo[i], memo[i / 3]);
        if (!(i % 2))
            memo[i] = min(memo[i], memo[i / 2]);
        memo[i]++;
    }
    cout << memo[N];
}