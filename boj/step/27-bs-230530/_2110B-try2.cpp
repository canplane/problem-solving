// BOJ 2110 G4 공유기 설치

using namespace std;
#include <cstdio>
#include <algorithm>

long x[200000];
int N, C;

long _upper_bound(long lo, long hi)
{
	while (lo < hi) {
		long mi = lo + (hi - lo) / 2;
		
		int c = 1;
		long prev = x[0];
		for (int i = 1; i < N; i++) {
			if (x[i] >= prev + mi)
				prev = x[i], ++c;
		}
		if (c < C)
			hi = mi;
		else
			lo = mi + 1;
	}
	return lo;	
}

int main()
{
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++)
		scanf("%ld", &x[i]);
	sort(x, x + N);

	printf("%ld", _upper_bound(1, 1000000001) - 1);
}