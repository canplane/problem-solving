#include <iostream>
#include <algorithm>

using namespace std;

int m[1001];

int main()
{
    int N, i, j;
    cin >> N;
    for (i = 1; i <= N; i++) {
        cin >> m[i];
        for (j = i - 1; j >= 1; j--)
            m[i] = max(m[i], m[j] + m[i - j]);
    }
    cout << m[N];
}