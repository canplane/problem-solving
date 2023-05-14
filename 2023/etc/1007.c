#include	<stdio.h>
#include	<math.h>
#include	<limits.h>
#define		MIN(x, y)	((x) > (y) ? (y) : (x))

int T, N, P[2][20];
long long ans;

int _c[21];
void combi(int n, int r, int left, int pos)
{
	int i;
	if (pos == r) {
		long long X, Y, X1, Y1;
		X = Y = X1 = Y1 = 0;
		for (i = 0; i < n; i++)
			X += P[0][i], Y += P[1][i];
		for (i = 0; i < r; i++)
			X1 += P[0][_c[i]], Y1 += P[1][_c[i]];
		
		X = 2 * X1 - X, Y = 2 * Y1 - Y;
		ans = MIN(ans, X * X + Y * Y);
		return;
	}
	if (left == n)  return;

	for (i = left; i < n; i++) {
		_c[pos] = i;
		combi(n, r, i + 1, pos + 1);
	}
}

int main()
{
	int i;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf("%d %d", &P[0][i], &P[1][i]);

		ans = LLONG_MAX;
		combi(N, N / 2, 0, 0);
		printf("%f\n", sqrt(ans));
	}
}