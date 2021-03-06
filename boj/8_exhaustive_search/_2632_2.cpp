#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int A[1001], B[1001], m, n, N, sum[1000000], sz, i, j;
long long ans;

void f(int e) {
	auto [lo, hi] = equal_range(sum, sum + sz, N - e);
	ans += hi - lo;
}

int main() {
	scanf("%d %d %d", &N, &m, &n);
	for (i = 1; i <= m; i++)
		scanf("%d", &A[i]), A[i] += A[i - 1];
	for (i = 1; i <= n; i++)
		scanf("%d", &B[i]), B[i] += B[i - 1];

	sum[sz++] = 0, sum[sz++] = A[m];
	for (i = 0; i < m; i++)
		for (j = (i + 1) % m; j != i; j = (j + 1) % m)
			sum[sz++] = A[j] + (j < i) * A[m] - A[i];
	sort(sum, sum + sz);

	f(0), f(B[n]);
	for (i = 0; i < n; i++)
		for (j = (i + 1) % n; j != i; j = (j + 1) % n)
			f(B[j] + (j < i) * B[n] - B[i]);

	printf("%lld", ans);
}