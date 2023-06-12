using namespace std;
#include <cstdio>
#include <algorithm>

long x[200000], c[200000];
int N, C;

int main()
{
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++)
		scanf("%ld", &x[i]);
	sort(x, x + N);

	long lo = 1, hi = 1000000001;
	while (lo < hi) {
		int mi = lo + (hi - lo) / 2;
		bool inc = true;
		c[0] = x[0];
		for (int i = 1; i < C; i++) {
			if (c[i - 1] + mi > x[N - 1]) {
				inc = false;
				break;
			}
			// 굳이 lower_bound로 구해서 (log N)^2으로 할 이유가 없지 않은가? -> try2
			auto it = lower_bound(x + i, x + N, c[i - 1] + mi);
			c[i] = *it;
		}
		if (!inc)
			hi = mi;
		else
			lo = mi + 1;
	}
	printf("%ld", lo - 1);
}