#include	<stdio.h>
#include	<math.h>
#include	<limits.h>
#define		MIN(x, y)	((x) > (y) ? (y) : (x))

int T, N, P[2][20];
long ans;

int comb[21];
void combi(int n, int n_i, int r, int r_i)
{
	int i;
	if (r_i == r) {
		long X, Y, X1, Y1;
		X = Y = X1 = Y1 = 0;
		for (i = 0; i < n; i++)
			X += P[0][i], Y += P[1][i];
		for (i = 0; i < r; i++)
			X1 += P[0][comb[i]], Y1 += P[1][comb[i]];
		
		X = 2 * X1 - X, Y = 2 * Y1 - Y;
		ans = MIN(ans, X * X + Y * Y);
		return;
	}
	if (n_i == n)  return;

	for (i = n_i; i < n; i++) {
		comb[r_i] = i, combi(n, i + 1, r, r_i + 1);
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
		combi(N, 0, N / 2, 0);
		printf("%f\n", sqrt(ans));
	}
}