#include <cstdio>
#include <algorithm>
using namespace std;

int seq[10000], N;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &seq[i]);
    sort(seq, seq + N, greater<int>());

    int mid_idx = N;
    for (int i = 0; i < N; i++) {
        if (seq[i] <= 0) {
            mid_idx = i;
            break;
        }
    }

    int ans = 0;
    for (int i = 0; i < mid_idx; i += 2) {
        if (i + 1 == mid_idx) {
            ans += seq[i];
            break;
        }
        ans += seq[i] * seq[i + 1];
    }
    for (int i = N - 1; i >= mid_idx; i -= 2) {
        if (i == mid_idx) {
            ans += seq[i];
            break;
        }
        ans += seq[i] * seq[i - 1];
    }
    printf("%d", ans);
}