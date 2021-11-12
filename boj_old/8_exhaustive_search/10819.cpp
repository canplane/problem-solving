#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int A[8], N;

int f(int idx) {
    int ret = 0;
    if (idx == N)
        for (int i = 1; i < N; i++)
            ret += abs(A[i - 1] - A[i]);
    else
        for (int i = idx; i < N; i++) {
            swap(A[idx], A[i]);
            ret = max(ret, f(idx + 1));
            swap(A[idx], A[i]);
        }
    return ret;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    printf("%d", f(0));
}