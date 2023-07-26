/* segment tree : O(nlgn) */

using namespace std;
#include <cstdio>
#include <utility>
#include <algorithm>

long h[100001];
int N;

int seg[400001];	// get minimum height in [from, to)
int seg_init(int l, int r, int i)
{
	if (l + 1 == r)
		return seg[i] = l;

	int m = (l + r) / 2;
	int e1 = seg_init(l, m, 2 * i), e2 = seg_init(m, r, 2 * i + 1);
	return seg[i] = h[e1] <= h[e2] ? e1 : e2;
}
int seg_query(int l, int r, int i, int from, int to)
{
	if (r <= from || to <= l)
		return -1;
	if (from <= l && r <= to)
		return seg[i];
	
	int m = (l + r) / 2;
	int e1 = seg_query(l, m, 2 * i, from, to), e2 = seg_query(m, r, 2 * i + 1, from, to);
	if (e1 == -1)	return e2;
	if (e2 == -1)	return e1;
	return h[e1] <= h[e2] ? e1 : e2;
}


long f(int from, int to)
{
	int k = seg_query(1, N + 1, 1, from, to);
	long h0 = h[k] * (to - from);
	if (k != from)
		h0 = max(h0, f(from, k));
	if (k + 1 != to)
		h0 = max(h0, f(k + 1, to));
	return h0;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%ld", &h[i]);
	
	seg_init(1, N + 1, 1);
	long ans = f(1, N + 1);
	printf("%ld", ans);
}