// BOJ 1043 G4 거짓말
// uf나 dfs나 하는 짓 같음. uf도 그래프

using namespace std;
#include <bits/stdc++.h>

vector<int> adj[51];
vector<int> party[50];

bool vis[51];
void dfs(int v)
{
	vis[v] = true;
	for (int w : adj[v]) {
		if (!vis[w]) {
			dfs(w);
		}
	}
}

int main()
{
	int N, M, n, x;

	scanf("%d %d", &N, &M);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		adj[0].push_back(x), adj[x].push_back(0);
	}

	for (int i = 0; i < M; i++) {
		int pre_x = -1;
		scanf("%d", &n);
		while (n--) {
			scanf("%d", &x), party[i].push_back(x);
			if (pre_x != -1) {
				adj[pre_x].push_back(x), adj[x].push_back(pre_x);
			}
			pre_x = x;
		}
	}
	dfs(0);

	int ans = 0;
	for (int i = 0; i < M; i++) {
		bool valid = true;
		for (auto &e : party[i]) {
			if (vis[e]) {
				valid = false;
				break;
			}
		}
		if (valid) {
			ans++;
		}
	}
	printf("%d", ans);
}