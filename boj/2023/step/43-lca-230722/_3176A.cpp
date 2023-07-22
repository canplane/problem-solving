using namespace std;
#include <bits/stdc++.h>

#define SZ 100001
#define LOG_SZ 17

int N;
vector<pair<int, int>> adj[SZ];

int par[SZ][LOG_SZ], dep[SZ];
int m[SZ][LOG_SZ], M[SZ][LOG_SZ];

void dfs(int v, int u, int c)
{
	par[v][0] = u;
	m[v][0] = M[v][0] = c;
	for (int i = 1; i < LOG_SZ; i++) {
		par[v][i] = par[par[v][i - 1]][i - 1];
		m[v][i] = min(m[v][i - 1], m[par[v][i - 1]][i - 1]), M[v][i] = max(M[v][i - 1], M[par[v][i - 1]][i - 1]);
	}

	for (auto [w, cost] : adj[v]) {
		if (w != u) {
			dep[w] = dep[v] + 1, dfs(w, v, cost);
		}
	}
}
int lca(int a, int b)
{
	int ans_m = INT_MAX, ans_M = INT_MIN;

	if (dep[a] != dep[b]) {
		if (dep[a] > dep[b]) {
			swap(a, b);
		}
		int dd = dep[b] - dep[a];
		for (int i = 0; i < LOG_SZ; i++) {
			if (dd & (1 << i)) {
				ans_m = min(ans_m, m[b][i]), ans_M = max(ans_M, M[b][i]);
				b = par[b][i];
			}
		}
	}
	if (a != b) {
		for (int i = LOG_SZ - 1; i >= 0; i--) {
			if (par[a][i] != par[b][i]) {
				ans_m = min(ans_m, min(m[a][i], m[b][i])), ans_M = max(ans_M, max(M[a][i], M[b][i]));
				a = par[a][i], b = par[b][i];
			}
		}
		ans_m = min(ans_m, min(m[a][0], m[b][0])), ans_M = max(ans_M, max(M[a][0], M[b][0]));
		a = par[a][0], b = par[b][0];
	}
	printf("%d %d\n", ans_m, ans_M);
	return a;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		adj[a].push_back({ b, cost }), adj[b].push_back({ a, cost });
	}
	dep[1] = 1, dfs(1, 0, 0);

	int K;
	scanf("%d", &K);
	while (K--) {
		int d, e;
		scanf("%d %d", &d, &e);
		lca(d, e);
	}
}