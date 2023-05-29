#include <cstdio>
#include <map>
using namespace std;

int A[40], N, S, mid;
long long ans;
map<int, int> m;

void dfs_l(int i, int sum) {
	if (i == mid) {
		m[sum]++;
		return;
	}
	dfs_l(i + 1, sum);
	dfs_l(i + 1, sum + A[i]);
}
void dfs_r(int i, int sum) {
	if (i == N) {
		ans += m[S - sum];
		return;
	}
	dfs_r(i + 1, sum);
	dfs_r(i + 1, sum + A[i]);
}

int main() {
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	mid = N / 2;
	dfs_l(0, 0), dfs_r(mid, 0);
	printf("%lld", ans - !S);
}