#include <cstdio>
#include <algorithm>
using namespace std;

int A[4000], B[4000], C[4000], D[4000], N;
int AB[4000 * 4000], CD[4000 * 4000];
long long ans;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            AB[N * i + j] = A[i] + B[j], CD[N * i + j] = -(C[i] + D[j]);
    sort(CD, CD + N * N);
    for (int i = 0; i < N * N; i++) {
        int l, r, mid;
        for (l = 0, r = N * N; l < r; ) {  // lower_bound
            mid = (l + r) / 2;
            if (CD[mid] < AB[i])
                l = mid + 1;
            else
                r = mid;
        }
        int lo = r;
        for (l = 0, r = N * N; l < r; ) {  // upper_bound
            mid = (l + r) / 2;
            if (CD[mid] <= AB[i])
                l = mid + 1;
            else
                r = mid;
        }
        int hi = r;
        ans += hi - lo;
    }
    printf("%lld", ans);
}