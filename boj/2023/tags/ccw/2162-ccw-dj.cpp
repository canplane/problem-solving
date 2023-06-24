using namespace std;
#include <cstdio>
#include <algorithm>
#include <utility>

int parent[3000], cnt[3000];
void dj_init(int n)
{
	for (int u = 0; u < n; u++) {
		parent[u] = u;
	}
}
int dj_find(int u)
{
	int r = u;
	while (parent[r] != r) {
		r = parent[r];
	}
	while (parent[u] != u) {
		int t = u;
		u = parent[u];
		parent[t] = r;
	}
	return r;
}
void dj_union(int u, int v)
{
	int ru = dj_find(u), rv = dj_find(v);
	parent[rv] = ru;
}

#define P pair<long, long>
int N;
pair<P, P> p[3000];
long CCW(P a, P b, P c)
{
	return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}
bool intersect(int i, int j)
{
	auto [A, B] = p[i];
	auto [C, D] = p[j];

	long c1 = CCW(A, B, C) * CCW(A, B, D), c2 = CCW(C, D, A) * CCW(C, D, B);
	if (c1 == 0 && c2 == 0) {		// parallel
		if (!(B < C || D < A)) {
			return true;
		}
	}
	else if (c1 <= 0 && c2 <= 0) {	// intersect
		return true;
	}
	return false;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		P a, b;
		scanf("%ld %ld %ld %ld", &a.first, &a.second, &b.first, &b.second);
		if (a > b) {
			swap(a, b);
		}
		p[i] = { a, b };
	}

	dj_init(N);
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (intersect(i, j)) {
				dj_union(i, j);
			}
		}
	}

	int total = 0;
	for (int u = 0; u < N; u++) {
		int ru = dj_find(u);
		cnt[ru]++;
		if (ru == u) {
			total++;
		}
	}
	int max_cnt = 0;
	for (int u = 0; u < N; u++) {
		max_cnt = max(max_cnt, cnt[u]);
	}
	printf("%d\n%d", total, max_cnt);
}