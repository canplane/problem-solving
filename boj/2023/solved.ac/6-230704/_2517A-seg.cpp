// 1517 버블소트와 유사: 좌표 압축 -> seg tree (sum (count))
// 태그에 좌표 압축 있는 걸 힌트로 삼아 풀었음.

using namespace std;
#include <cstdio>
#include <algorithm>
#include <utility>

int N;
pair<int, int> A[500000];
int B[500000];

int seg[2000001];
int seg_query(int l, int r, int i, int from, int to)
{
	if (r <= from || to <= l) {
		return 0;
	}
	if (from <= l && r <= to) {
		return seg[i];
	}
	int m = (l + r) / 2;
	return seg_query(l, m, 2 * i, from, to) + seg_query(m, r, 2 * i + 1, from, to);
}
void seg_update(int l, int r, int i, int key, int val)
{
	if (l + 1 == r) {
		seg[i] = val;
		return;
	}
	int m = (l + r) / 2;
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
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		A[i] = { x, i };
	}
	sort(A, A + N);

	int j = 0;
	for (int i = 0; i < N; i++) {
		B[A[i].second] = j++;
	}

	for (int i = 0; i < N; i++) {
		printf("%d\n", seg_query(0, N, 1, B[i] + 1, N) + 1);
		seg_update(0, N, 1, B[i], 1);
	}
}