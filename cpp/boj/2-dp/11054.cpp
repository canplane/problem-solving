#include <iostream>
#include <algorithm>
#define MAX_N 1000

using namespace std;

int a[MAX_N], asc[MAX_N], desc[MAX_N];

int main()
{
    int N, i, j, ans;
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (i = 0; i < N; i++) {
        asc[i] = 1;
        for (j = i - 1; j >= 0; j--) {
            if (a[j] < a[i]) {
                asc[i] = max(asc[i], asc[j] + 1);
            }
        }
    }
    for (i = N - 1; i >= 0; i--) {
        desc[i] = 1;
        for (j = i + 1; j < N; j++) {
            if (a[i] > a[j]) {
                desc[i] = max(desc[i], desc[j] + 1);
            }
        }
    }
    ans = 0;
    for (i = 0; i < N; i++) {
        ans = max(ans, asc[i] + desc[i] - 1);
    }
    cout << ans;
}