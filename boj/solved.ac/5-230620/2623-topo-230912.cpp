// BOJ 2623 G3 음악프로그램
// [15 mins] 단순 위상 정렬

using namespace std;
#include <bits/stdc++.h>

int N;
vector<int> adj[1001];
int indeg[1001];

int main()
{
	int M;
	scanf("%d %d", &N, &M);
	while (M--) {
		int n;
		scanf("%d", &n);

		int u, v;
		n--, scanf("%d", &u);
		while (n--) {
			scanf("%d", &v);
			adj[u].push_back(v), ++indeg[v];
			u = v;
		}
	}

	vector<int> ans;
	deque<int> q;
	for (int u = 1; u <= N; u++) {
		if (!indeg[u]) {
			q.push_back(u);
		}
	}
	while (!q.empty()) {
		int u = q.front(); q.pop_front();
		ans.push_back(u);
		for (int v : adj[u]) {
			if (!--indeg[v]) {
				q.push_back(v);
			}
		}
	}
	
	if (ans.size() != N) {
		printf("0\n");
	}
	else {
		for (int u : ans) {
			printf("%d\n", u);
		}
	}
}