#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int A[1001], B[1001], m, n, N;

int main() {
	scanf("%d %d %d", &N, &m, &n);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &A[i]);
		A[i] += A[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &B[i]);
		B[i] += B[i - 1];
	}

	vector<int> v_A, v_B;

	v_A.push_back(0), v_A.push_back(A[m]);
	for (int i = 0; i < m; i++)
		for (int j = (i + 1) % m; j != i; j = (j + 1) % m)
			v_A.push_back(A[j] + (j < i) * A[m] - A[i]);
	sort(v_A.begin(), v_A.end());

	v_B.push_back(0), v_B.push_back(B[n]);
	for (int i = 0; i < n; i++)
		for (int j = (i + 1) % n; j != i; j = (j + 1) % n)
			v_B.push_back(B[j] + (j < i) * B[n] - B[i]);

	long long ans = 0;
	for (auto& e : v_B) {
		auto [lo, hi] = equal_range(v_A.begin(), v_A.end(), N - e);
		ans += hi - lo;
	}
	printf("%lld", ans);
}