using namespace std;
#include <cstdio>
#include <algorithm>

long get_idx(long N, long val)
{
	long idx = 0;
	for (int i = 1; i <= N; i++) {
		idx += min(val / i, N);
	}
	return idx;
}
int bs(long N, long lo, long hi, long k)
{
	if (lo == hi) {
		return lo;
	}
	long mi = (lo + hi) / 2;
	long idx = get_idx(N, mi);
	if (k <= idx)	// lower bound
		return bs(N, lo, mi, k);
	else
		return bs(N, mi + 1, hi, k);
}

int main()
{
	long N, k;
	scanf("%ld %ld", &N, &k);
	long ans = bs(N, 1, N * N, k);
	printf("%ld", ans);
}