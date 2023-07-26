using namespace std;
#include <cstdio>
#include <vector>
#include <deque>
#include <utility>
#include <cstring>
#include <algorithm>

#define MAX_NODES 1000
vector<int> adj[1 + MAX_NODES];

bool visit[1 + MAX_NODES];

// simulates computer architecture
void dfs_iter2(int v)
{
	deque<int> s;
	bool call;
	int ret, i;

	visit[v] = true;
	{ ( s.push_back(v), s.push_back(0) ); s.push_back(0); call = true; }		// callee context
	// v, i, ret -> ret
	while (true) {
		{ call = false; (ret = s.back(), s.pop_back()); ( (i = s.back(), s.pop_back()), (v = s.back(), s.pop_back()) ); }

		if (i == 0) {
			printf("%d ", v);
			ret++;
		}
		for (; i < adj[v].size(); i++) {
			int w = adj[v][i];
			if (!visit[w]) {
				visit[w] = true;
				{ ( s.push_back(v), s.push_back(i + 1) ); }									// caller context
				{ ( s.push_back(w), s.push_back(0) ); s.push_back(ret); call = true; }		// callee context
				break;
			}
		}
		if (call)	continue;
		{ s.push_back(ret); if (s.size() == 1) break; }
	}
	{ call = false; (ret = s.back(), s.pop_back()); }
}
void bfs(int v)
{
	deque<int> q;
	visit[v] = true, q.push_back(v);
	while (q.size()) {
		v = q.front(), q.pop_front();
		// PRE
		printf("%d ", v);
		for (auto w : adj[v]) {
			if (!visit[w])
				visit[w] = true, q.push_back(w);
		}
	}
}

int main()
{
	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 1; i <= M; i++) {
		int v, w;
		scanf("%d %d", &v, &w);
		adj[v].push_back(w), adj[w].push_back(v);
	}
	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	dfs_iter2(V), printf("\n");
	memset(visit, 0, N + 1);
	bfs(V), printf("\n");
}