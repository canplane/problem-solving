// BOJ 1300 G2 K번째 수

using namespace std;
#include <cstdio>
#include <algorithm>

long val_to_idx(long val, long N)
{
	long idx = 0;
	for (int i = 1; i <= N; i++)
		idx += min(val / i, N);
	return idx;
}
int inv_lower_bound(long val_l, long val_r, long idx, long N)	// [l, r)
{
	while (val_l < val_r) {
		long val_m = (val_l + val_r) / 2;
		long idx_m = val_to_idx(val_m, N);
		// lower bound: stretches to the minimum of values that can have same index.
		if (idx <= idx_m)
			val_r = val_m;
		else
			val_l = val_m + 1;
	}
	return val_l;
}

int main()
{
	long N, k;
	scanf("%ld %ld", &N, &k);
	long ans = inv_lower_bound(1, N * N + 1, k, N);
	printf("%ld", ans);
}