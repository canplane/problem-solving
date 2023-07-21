// byeo.tistory.com/entry/boj-16975-수열과-쿼리-21
// update 시 범위 안에 포함되는 노드면 그냥 거기서 dx 더하고 끝내기
// query 시 타고 내려가는 노드 모두 더하기

#include <cstdio>

int N;
long A[100001];

long seg[400001];
long seg_query(int l, int r, int i, int key)
{
	if (l + 1 == r) {
		return seg[i];
	}

	int m = (l + r) / 2;
	if (key < m) {
		return seg[i] + seg_query(l, m, 2 * i, key);
	}
	else {
		return seg[i] + seg_query(m, r, 2 * i + 1, key);
	}
}
void seg_update(int l, int r, int i, int from, int to, int dx)
{
	if (to <= l || r <= from) {
		return;
	}
	if (from <= l && r <= to) {
		seg[i] += dx;
		return;
	}

	int m = (l + r) / 2;
	seg_update(l, m, 2 * i, from, to, dx), seg_update(m, r, 2 * i + 1, from, to, dx);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%ld", &A[i]);
	}

	int M;
	scanf("%d", &M);
	while (M--) {
		int cmd, i, j, x;
		scanf("%d", &cmd);
		if (cmd == 1) {
			scanf("%d %d %d", &i, &j, &x);
			seg_update(0, N, 1, i - 1, j, x);
		}
		else {
			scanf("%d", &x);
			printf("%ld\n", A[x - 1] + seg_query(0, N, 1, x - 1));
		}
	}
}