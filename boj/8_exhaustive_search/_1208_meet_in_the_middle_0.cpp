#include <cstdio>
#include <map>
using namespace std;

int A[40], N, S;
long long ans;
map<int, int> m;

void dfs_l(int i, int sum) {
	m[sum]++;
	for (; i < N / 2; i++)
		dfs_l(i + 1, sum + A[i]);
}
void dfs_r(int i, int sum) {
	ans += m[S - sum];
	for (; i >= N / 2; i--)
		dfs_r(i - 1, sum + A[i]);
}

int main() {
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	dfs_l(0, 0), dfs_r(N - 1, 0);
	printf("%lld", ans - !S);
}