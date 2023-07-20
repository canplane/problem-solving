// BOJ 4196 도미노의 단순 변형. in-degree = 0인 SCC가 유일한가?

using namespace std;
#include <bits/stdc++.h>

int N, M;
vector<int> adj[100000];

stack<int> st;
int scn[100000], max_scn;
int dfn[100000], max_dfn;
int tarjan(int v)
{
	st.push(v);
	int low = (dfn[v] = ++max_dfn);
	for (int w : adj[v]) {
		if (!dfn[w]) {
			low = min(low, tarjan(w));
		}
		else if (!scn[w]) {
			low = min(low, dfn[w]);
		}
	}
	if (low == dfn[v]) {
		++max_scn;
		while (true) {
			int w = st.top(); st.pop();
			scn[w] = max_scn;
			if (w == v) {
				break;
			}
		}
	}
	return low;
}

int scc_indeg[100000];
void sol()
{
	for (int v = 0; v < 100000; v++) {
		adj[v].clear();
	}
	memset(scc_indeg, 0, sizeof(scc_indeg));
	memset(scn, 0, sizeof(scn)), max_scn = 0;
	memset(dfn, 0, sizeof(dfn)), max_dfn = 0;

	scanf("%d %d", &N, &M);

	while (M--) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
	}

	for (int v = 0; v < N; v++) {
		if (!dfn[v]) {
			tarjan(v);
		}
	}

	for (int v = 0; v < N; v++) {
		for (int w : adj[v]) {
			if (scn[w] != scn[v]) {
				++scc_indeg[scn[w]];
			}
		}
	}

	int start = 0;
	for (int i = 1; i <= max_scn; i++) {
		if (!scc_indeg[i]) {
			if (start) {
				start = 0;
				break;
			}
			start = i;
		}
	}
	if (start == 0) {
		printf("Confused\n");
	}
	else {
		for (int v = 0; v < N; v++) {
			if (scn[v] == start) {
				printf("%d\n", v);
			}
		}
	}
	printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		sol();
	}
}