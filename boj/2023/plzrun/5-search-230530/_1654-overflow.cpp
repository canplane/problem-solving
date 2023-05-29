/**
 * 틀린 이유:
 * 		* overflow :
 * 			hi + 1 -> long으로 바꾸기 (파이썬이 나음)
 * 			mi = lo + (hi - mi) / 2
 * 		* min이 아니라 max!
*/

using namespace std;
#include <cstdio>
#include <algorithm>

int K, N;
long A[10000];

long _upper_bound(long lo, long hi)
{
	while (lo < hi) {
		long mi = lo + (hi - lo) / 2;
		int pieces = 0;
		for (int i = 0; i < K; i++)
			pieces += A[i] / mi;
		if (pieces < N)
			hi = mi;
		else
			lo = mi + 1;
	}
	return lo;
}

int main()
{
	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; i++) {
		scanf("%ld", &A[i]);
	}
	long hi = A[0];
	for (int i = 0; i < K; i++)
		hi = max(hi, A[i]);
	printf("%ld", _upper_bound(1, hi + 1) - 1);
}