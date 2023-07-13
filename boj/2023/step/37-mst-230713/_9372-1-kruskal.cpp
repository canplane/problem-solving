// kruskal은 pq에 선 집어넣기 : pair<int, pair<int, int>>

using namespace std;
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>

int parent[1001];
void dj_init(int n)
{
	for (int i = 1; i <= n; i++) {
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

template <class T>
int kruskal(T& pq, int n)
{
	dj_init(n);

	int ans = 0;
	while (!pq.empty()) {
		auto [cost, p] = pq.top(); pq.pop();
		auto [u, v] = p;
		if (dj_find(u) == dj_find(v)) {
			continue;
		}
		dj_union(u, v);
		ans += cost;
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, M;
		scanf("%d %d", &N, &M);

		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
		while (M--) {
			int a, b;
			scanf("%d %d", &a, &b);
			pq.push({ 1, { a, b } });
		}
		printf("%d\n", kruskal(pq, N));
	}
}