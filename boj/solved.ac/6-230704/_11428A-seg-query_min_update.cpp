// seg_update 함수를 잘못 짜서 헤맸다.

using namespace std;
#include <cstdio>
#include <algorithm>

#define INF 0x7fffffff

int N;
int A[100000];

pair<int, int> seg[400001];
pair<int, int> seg_init(int l, int r, int i)
{
	if (l + 1 == r) {
		return seg[i] = { A[l], l };
	}
	int m = (l + r) / 2;
	return seg[i] = min(seg_init(l, m, 2 * i), seg_init(m, r, 2 * i + 1));
}
pair<int, int> seg_query(int l, int r, int i, int from, int to)
{
	if (r <= from || to <= l) {
		return { INF, -1 };
	}
	if (from <= l && r <= to) {
		return seg[i];
	}
	int m = (l + r) / 2;
	return min(seg_query(l, m, 2 * i, from, to), seg_query(m, r, 2 * i + 1, from, to));
}
void seg_update(int l, int r, int i, int key, int val)
{
	if (l + 1 == r) {
		seg[i] = { A[l] = val, l };
		return;
	}
	int m = (l + r) / 2;
	if (key < m) {
		seg_update(l, m, 2 * i, key, val);
	}
	else {
		seg_update(m, r, 2 * i + 1, key, val);
	}
	
	// 중요!!!
	seg[i] = min(seg[2 * i], seg[2 * i + 1]);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	seg_init(0, N, 1);

	int M;
	scanf("%d", &M);
	while (M--) {
		int h, i, j;
		scanf("%d %d %d", &h, &i, &j);
		if (h == 1) {
			seg_update(0, N, 1, i - 1, j);
		}
		else {
			printf("%d\n", 1 + seg_query(0, N, 1, i - 1, j).second);
		}
	}
}