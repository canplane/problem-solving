#include <cstdio>
#include <cmath>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int x, y;
		scanf("%d %d", &x, &y);
		int d = y - x;			// distance
		int n = (int)sqrt(d);	// maximum speed
		d -= n * n;
		printf("%d\n", (2 * n - 1) + d / n + !!(d % n));
	}
}