#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int A[1001], B[1001], n, m, T;
long long ans;

int main() {
	scanf("%d", &T);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &A[i]), A[i] += A[i - 1];
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", &B[i]), B[i] += B[i - 1];

	vector<int> v_A;
	for (int i = 0; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			v_A.push_back(A[j] - A[i]);
	sort(v_A.begin(), v_A.end());
	for (int i = 0; i <= m; i++)
		for (int j = i + 1; j <= m; j++) {
			auto [lo, hi] = equal_range(v_A.begin(), v_A.end(), T - (B[j] - B[i]));
			ans += hi - lo;
		}
	printf("%lld", ans);
}