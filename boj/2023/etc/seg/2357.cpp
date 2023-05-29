using namespace std;
#include <cstdio>
#include <utility>
#include <algorithm>

int A[1000001];
pair<int, int> seg[4000001];

pair<int, int> seg_init(int l, int r, int i)
{
	if (l + 1 == r) {
		return seg[i] = { A[l], A[l] };
	}
	int m = (l + r) / 2;
	auto [m1, M1] = seg_init(l, m, 2 * i);
	auto [m2, M2] = seg_init(m, r, 2 * i + 1);
	return seg[i] = { min(m1, m2), max(M1, M2) };
}
pair<int, int> seg_query(int l, int r, int i, int from, int to)
{
	if (r <= from || to <= l) {
		return { 0, 0 };
	}
	if (from <= l && r <= to) {
		return seg[i];
	}
	int m = (l + r) / 2;
	auto [m1, M1] = seg_query(l, m, 2 * i, from, to);
	auto [m2, M2] = seg_query(m, r, 2 * i + 1, from, to);
	if (!m1)	return { m2, M2 };
	if (!m2)	return { m1, M1 };
	return { min(m1, m2), max(M1, M2) };
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	seg_init(1, N + 1, 1);
	for (int i = 1; i <= M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		auto [m, M] = seg_query(1, N + 1, 1, a, b + 1);
		printf("%d %d\n", m, M);
	}
}