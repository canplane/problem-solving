// BOJ 20303 G3 할로윈의 양아치
// [1 hours] 1. 구현 어떻게 해야할지, 냅색 DP 어떻게 짜야할지 몰라서 난관이었음.

using namespace std;
#include <bits/stdc++.h>

int _N, _M, K;
int _V[30001];

vector<int> adj[30001];
bool vis[30001];

long _n, _val;
void dfs(int u)
{
	vis[u] = true;
	_n += 1, _val += _V[u];
	for (int v : adj[u])
		if (!vis[v])
			dfs(v);
}

int N;
long W[30001], V[30001];
long dp[3001];

int main()
{
	scanf("%d %d %d", &_N, &_M, &K);
	for (int i = 1; i <= _N; i++)
		scanf("%d", &_V[i]);
	while (_M--) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v), adj[v].push_back(u);
	}
	for (int u = 1; u <= _N; u++) {
		if (!vis[u]) {
			++N;
			_n = 0, _val = 0;
			dfs(u);
			W[N] = _n, V[N] = _val;
		}
	}

	for (int i = 1; i <= N; i++)
		for (int k = K; k >= 1; k--)
			if (k > W[i])
				dp[k] = max(dp[k], V[i] + dp[k - W[i]]);
	printf("%ld", dp[K]);
}