using namespace std;
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>

int N;
pair<double, double> A[100];

int parent[100];
void dj_init()
{
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}
}
int dj_find(int u)
{
	while (parent[u] != u) {
		u = parent[u];
	}
	return u;
}
void dj_union(int u, int v)
{
	int ru = dj_find(u), rv = dj_find(v);
	parent[rv] = ru;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		double x, y;
		scanf("%lf %lf", &x, &y);
		A[i] = { x, y };
	}

	priority_queue<pair<double, pair<int, int>>> pq;
	for (int i = 0; i < N; i++) {
		auto& [xi, yi] = A[i];
		for (int j = i + 1; j < N; j++) {
			auto& [xj, yj] = A[j];
			pq.push({ -sqrt(pow(xi - xj, 2) + pow(yi - yj, 2)), { i, j } });
		}
	}

	double ans = 0;
	dj_init();
	while (!pq.empty()) {
		auto [cost, p] = pq.top(); pq.pop();
		auto [i, j] = p;
		if (dj_find(i) == dj_find(j)) {
			continue;
		}
		dj_union(i, j);
		ans += -cost;
	}
	printf("%.2lf", ans);
}