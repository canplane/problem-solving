// [18 mins]

using namespace std;
#include <cstdio>
#include <algorithm>
#include <climits>

int N;
int A[11], B[4];

int ans_M = INT_MIN, ans_m = INT_MAX;
void dfs(int i, int ret)
{
	if (i == N) {
		ans_M = max(ans_M, ret), ans_m = min(ans_m, ret);
		return;
	}
	int next_ret[4] = { ret + A[i], ret - A[i], ret * A[i], ret / A[i] };
	for (int j = 0; j < 4; j++) {
		if (B[j] > 0) {
			B[j]--;
			dfs(i + 1, next_ret[j]);
			B[j]++;
		}
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &B[i]);
	}

	dfs(1, A[0]);
	printf("%d\n%d\n", ans_M, ans_m);
}