#include	<stdio.h>
#define		MIN(x, y)	((x) > (y) ? (y) : (x))
#define		SZ			10003

int T, N, W;
int _A[2][SZ], *A[2] = { &_A[0][2], &_A[1][2] };
int a[SZ], a0[SZ], a1[SZ];
int ans;

void dp()
{
	int b0, b1;
	int i;

	for (i = 1; i <= N; i++) {
		b0 = (W >= A[0][i - 1] + A[0][i]), b1 = (W >= A[1][i - 1] + A[1][i]);

		a0[i] = a1[i] = a[i - 1] + 1;
		if (b0)			a0[i] = MIN(a0[i], a1[i - 1] + 1);
		if (b1)			a1[i] = MIN(a1[i], a0[i - 1] + 1);

		a[i] = MIN(a[i - 1] + (W >= A[0][i] + A[1][i] ? 1 : 2), MIN(a0[i] + 1, a1[i] + 1));
		if (b0 && b1)	a[i] = MIN(a[i], a[i - 2] + 2);
	}
}

int main()
{
	int t, t0, t1;
	int b0, b1;
	int i;

	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &W);
		for (i = 1; i <= N; i++)	scanf("%d", &A[0][i]);
		for (i = 1; i <= N; i++)	scanf("%d", &A[1][i]);

		dp();
		ans = a[N];
		if (N > 1) {
			t = W + 1, t0 = A[0][1], t1 = A[1][1];
			b0 = (W >= A[0][1] + A[0][N]), b1 = (W >= A[1][1] + A[1][N]);

			A[0][1] = A[1][1] = t; dp(); A[0][1] = t0, A[1][1] = t1;
			ans = MIN(ans, a[N - 1] + (b0 && b1 ? 0 : 2));

			A[0][1] = t; dp(); A[0][1] = t0;
			ans = MIN(ans, a1[N] + (b0 ? 0 : 1));

			A[1][1] = t; dp(); A[1][1] = t1;
			ans = MIN(ans, a0[N] + (b1 ? 0 : 1));
		}
		printf("%d\n", ans);
	}
}