#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int A[1000], B[1000], N, m, n;
int sum_A[1001], sum_B[1001];
long long ans;

int main() {
	scanf("%d %d %d", &N, &m, &n);
	for (int i = 0; i < m; i++) {
		scanf("%d", &A[i]);
		sum_A[i + 1] = sum_A[i] + A[i];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &B[i]);
		sum_B[i + 1] = sum_B[i] + B[i];
	}

	vector<int> vec_a, vec_b;
	vec_a.push_back(sum_A[0]), vec_a.push_back(sum_A[m]);
	for (int i = 0; i < m; i++)
		for (int j = (i + 1) % m; j != i; j = (j + 1) % m)
			vec_a.push_back((sum_A[j] - sum_A[i]) + ((i < j) ? 0 : sum_A[m]));
	sort(vec_a.begin(), vec_a.end());

	vec_b.push_back(sum_B[0]), vec_b.push_back(sum_B[n]);
	for (int i = 0; i < n; i++)
		for (int j = (i + 1) % n; j != i; j = (j + 1) % n)
			vec_b.push_back((sum_B[j] - sum_B[i]) + ((i < j) ? 0 : sum_B[n]));

	for (auto it = vec_b.begin(); it != vec_b.end(); it++) {
		auto [lo, hi] = equal_range(vec_a.begin(), vec_a.end(), N - *it);
		ans += hi - lo;
	}
	printf("%lld", ans);
}