// 시간 초과 : seg tree (minimum) : 사실상 N^2

using namespace std;
#include <cstdio>
#include <algorithm>

int N;
int A[500000];

int seg[2000001];
int seg_init(int l, int r, int i)
{
	if (l + 1 == r) {
		return seg[i] = A[l];
	}
	int m = (l + r) / 2;
	return seg[i] = min(seg_init(l, m, 2 * i), seg_init(m, r, 2 * i + 1));
}
int seg_inv_query(int l, int r, int i, int from, int to, int key)
{
	if (r <= from || to <= l) {
		return 0;
	}
	if (from <= l && r <= to) {	// 이렇게 풀지 마라!!
		if (key < seg[i]) {
			return r - l;
		}
		if (l + 1 == r) {
			return key < seg[i];
		}
	}
	int m = (l + r) / 2;
	return seg_inv_query(l, m, 2 * i, from, to, key) + seg_inv_query(m, r, 2 * i + 1, from, to, key);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	seg_init(0, N, 1);
	for (int i = 0; i < N; i++) {
		printf("%d\n", seg_inv_query(0, N, 1, 0, i, A[i]) + 1);
	}
}