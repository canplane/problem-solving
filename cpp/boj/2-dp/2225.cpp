#include <iostream>
#define MAX_N 200
#define MAX_K 200

using namespace std;

int m[MAX_K + 1][MAX_N + 1];

int main() {
    int N, K, i, j;
    cin >> N >> K;

    for (i = 1; i <= MAX_K; i++) m[i][0] = 1;
    for (j = 0; j <= MAX_N; j++) m[1][j] = 1;

    for (i = 2; i <= MAX_K; i++)
        for (j = 1; j <= MAX_N; j++)
            m[i][j] = (m[i][j - 1] + m[i - 1][j]) % 1000000000;
    cout << m[K][N];
}