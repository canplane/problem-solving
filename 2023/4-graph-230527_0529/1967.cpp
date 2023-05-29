using namespace std;
#include <cstdio>
#include <vector>
#include <utility>

vector<pair<int, int>> adj[100001];

int k;
int dfs(int v)
{
	int h1 = 0, h2 = 0;
	for (auto [w, c] : adj[v]) {
		int h = c + dfs(w);
		if (h > h1)			h2 = h1, h1 = h;
		else if (h > h2)	h2 = h;
	}
	if (h1 + h2 > k)	k = h1 + h2;
	return h1;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int v, w, c;
		scanf("%d %d %d", &v, &w, &c);
		adj[v].push_back({w, c});
	}
	dfs(1);
	printf("%d", k);
}