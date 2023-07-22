using namespace std;
#include <bits/stdc++.h>

int N;
pair<int, int> seg[400000];
int seg_idx[100000];
pair<int, int> &seg_init(int l, int r, int i)
{
	if (l + 1 == r) {
		seg_idx[l] = i;
		return seg[i] = { l, l };
	}
	int m = (l + r) / 2;
	auto [m1, M1] = seg_init(l, m, 2 * i); auto [m2, M2] = seg_init(m, r, 2 * i + 1);
	return seg[i] = { min(m1, m2), max(M1, M2) };
}
pair<int, int> seg_query(int l, int r, int i, int from, int to)
{
	if (to <= l || r <= from) {
		return { INT_MAX, INT_MIN };
	}
	if (from <= l && r <= to) {
		return seg[i];
	}
	int m = (l + r) / 2;
	auto [m1, M1] = seg_query(l, m, 2 * i, from, to); auto [m2, M2] = seg_query(m, r, 2 * i + 1, from, to);
	return { min(m1, m2), max(M1, M2) };
}
void seg_update(int i)
{
	i /= 2;
	while (i) {
		auto [m1, M1] = seg[2 * i]; auto [m2, M2] = seg[2 * i + 1];
		seg[i] = { min(m1, m2), max(M1, M2) };
		i /= 2;
	}
}

void sol()
{
	int K;
	scanf("%d %d", &N, &K);

	seg_init(0, N, 1);
	while (K--) {
		int q, a, b;
		scanf("%d %d %d", &q, &a, &b);
		if (q) {
			auto [m, M] = seg_query(0, N, 1, a, b + 1);
			printf("%s\n", (m == a && M == b) ? "YES" : "NO");
		}
		else {
			int i = seg_idx[a], j = seg_idx[b];
			swap(seg[i], seg[j]);
			seg_update(i), seg_update(j);
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		sol();
	}
}