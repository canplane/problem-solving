#include <cstdio>
#include <map>

int A[1001], B[1001], m, n, N;
long long ans;
std::map<int, int> mp;

int main() {
	scanf("%d %d %d", &N, &m, &n);
	for (int i = 1; i <= m; i++)
		scanf("%d", &A[i]), A[i] += A[i - 1];
	for (int i = 1; i <= n; i++)
		scanf("%d", &B[i]), B[i] += B[i - 1];

	mp[0]++, mp[A[m]]++;
	for (int i = 0; i < m; i++)
		for (int j = (i + 1) % m; j != i; j = (j + 1) % m)
			mp[A[j] + (j < i) * A[m] - A[i]]++;

	ans += mp[N] + mp[N - B[n]];
	for (int i = 0; i < n; i++)
		for (int j = (i + 1) % n; j != i; j = (j + 1) % n)
			ans += mp[N - (B[j] + (j < i) * B[n] - B[i])];

	printf("%lld", ans);
}