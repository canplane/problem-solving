// counting inversions : 세그먼트 트리가 머지 소트보다 더 느리다. (2배)

using namespace std;
#include <cstdio>

int N;
int A[1000000];

int seg[4000001];
int seg_query(int l, int r, int i, int from, int to)
{
	if (r <= from || to <= l) {
		return 0;		
	}
	if (from <= l && r <= to) {
		return seg[i];
	}
	int m = l + (r - l) / 2;
	return seg_query(l, m, 2 * i, from, to) + seg_query(m, r, 2 * i + 1, from, to);
}
void seg_update(int l, int r, int i, int key, int val)
{
	if (l + 1 == r) {
		seg[i] = val;
		return;
	}
	int m = l + (r - l) / 2;
	if (key < m) {
		seg_update(l, m, 2 * i, key, val);
	}
	else {
		seg_update(m, r, 2 * i + 1, key, val);
	}
	seg[i] = seg[2 * i] + seg[2 * i + 1];
}

int main()
{
	scanf("%d", &N);

	long invcnt = 0;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		invcnt += seg_query(1, N + 1, 1, x + 1, N + 1);
		seg_update(1, N + 1, 1, x, 1);
	}
	printf("%ld", invcnt);
}