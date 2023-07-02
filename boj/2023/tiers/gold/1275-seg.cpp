using namespace std;
#include <cstdio>
#include <algorithm>

int N;
int A[100000];

long seg[400001];
long seg_init(int l, int r, int i)
{
	if (l + 1 == r)
		return seg[i] = A[l];
	int m = (l + r) / 2;
	return seg[i] = seg_init(l, m, 2 * i) + seg_init(m, r, 2 * i + 1);
}
long seg_query(int l, int r, int i, int from, int to)
{
	if (r <= from || to <= l)
		return 0;
	if (from <= l && r <= to)
		return seg[i];
	int m = (l + r) / 2;
	return seg_query(l, m, 2 * i, from, to) + seg_query(m, r, 2 * i + 1, from, to);
}
void seg_update(int l, int r, int i, int a, int b)
{
	if (l + 1 == r) {
		long _b = seg[i];
		for (; i; i /= 2)
			seg[i] = seg[i] - _b + b;
		return;
	}
	int m = (l + r) / 2;
	if (a < m)
		seg_update(l, m, 2 * i, a, b);
	else
		seg_update(m, r, 2 * i + 1, a, b);
}

int main()
{
	int Q;
	scanf("%d %d", &N, &Q);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	seg_init(0, N, 1);
	while (Q--) {
		int x, y, a, b;
		scanf("%d %d %d %d", &x, &y, &a, &b);
		if (x > y)
			swap(x, y);
		printf("%ld\n", seg_query(0, N, 1, x - 1, y));
		seg_update(0, N, 1, a - 1, b);
	}
}