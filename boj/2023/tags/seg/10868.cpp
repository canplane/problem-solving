using namespace std;
#include <cstdio>
#include <algorithm>

#define INF 0x7fffffff

int N;
int A[100000];

int seg[400001];
int seg_init(int l, int r, int i)
{
	if (l + 1 == r) {
		return seg[i] = A[l];
	}

	int m = (l + r) / 2;
	return seg[i] = min(seg_init(l, m, 2 * i), seg_init(m, r, 2 * i + 1));
}
int seg_query(int l, int r, int i, int from, int to)
{
	if (r <= from || to <= l) {
		return INF;
	}
	if (from <= l && r <= to) {
		return seg[i];
	}

	int m = (l + r) / 2;
	return min(seg_query(l, m, 2 * i, from, to), seg_query(m, r, 2 * i + 1, from, to));
}

int main()
{
	int M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	seg_init(0, N, 1);

	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", seg_query(0, N, 1, a - 1, b));
	}
}