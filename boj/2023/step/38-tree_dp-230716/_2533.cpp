using namespace std;
#include <cstdio>
#include <vector>

int N;
vector<int> adj[1000001];

int S[1000001][3];
int dfs(int v, int u)
{
	S[v][1] = 1, S[v][0] = 0;
	for (int w : adj[v]) {
		if (w != u) {
			S[v][1] += dfs(w, v), S[v][0] += S[w][1];
		}
	}
	return min(S[v][0], S[v][1]);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v), adj[v].push_back(u);
	}
	printf("%d", dfs(1, 0));
}