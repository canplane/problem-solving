using namespace std;
#include <cstdio>
#define DIV 1'000'000'007

long A[1000001], seg[4000001];
int seg_idx[1000001];

long seg_init(int l, int r, int i)
{
	if (l + 1 == r) {
		seg_idx[l] = i;
		return seg[i] = A[l];
	}
	int m = (l + r) / 2;
	return seg[i] = seg_init(l, m, 2 * i) * seg_init(m, r, 2 * i + 1) % DIV;
}
long seg_query(int l, int r, int i, int from, int to)
{
	if (r <= from || to <= l) {
		return 1;
	}
	if (from <= l && r <= to) {
		return seg[i];
	}
	int m = (l + r) / 2;
	return seg_query(l, m, 2 * i, from, to) * seg_query(m, r, 2 * i + 1, from, to) % DIV;
}
void seg_update(int k, long e)
{
	int i = seg_idx[k];
	seg[i] = A[k] = e;
	while ((i /= 2) > 0) {
		seg[i] = seg[2 * i] * seg[2 * i + 1] % DIV;
	}
}

int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%ld", &A[i]);
	}
	seg_init(1, N + 1, 1);
	for (int i = 1; i <= M + K; i++) {
		long a, b, c;
		scanf("%ld %ld %ld", &a, &b, &c);
		if (a == 1) {
			// b := c
			seg_update(b, c);
		}
		else if (a == 2) {
			// seg_query(b, c + 1)
			printf("%ld\n", seg_query(1, N + 1, 1, b, c + 1));
		}
	}
}