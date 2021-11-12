#include <iostream>
#include <algorithm>

using namespace std;

long long memo[1000000 + 1];
int N;

int main() {
    cin >> N;
    
    for (int i = 2; i <= N; i++) {
        memo[i] = memo[i - 1] + 1;
        memo[i] = min(1 + memo[i / 2] + i % 2, memo[i]);
        memo[i] = min(1 + memo[i / 3] + i % 3, memo[i]);
    }

    cout << memo[N];
}