// 처음엔 타잔 알고리즘으로 SCC 리스트 만들고 위상정렬 순서, 즉 역순으로 dfs해서 수동 방문한 횟수 카운팅으로 구했음.
// 근데 단순히 in-degree가 0인 SCC 수 찾으면 됐던 문제.

using namespace std;
#include <bits/stdc++.h>

int N, M;
vector<int> adj[100001];

stack<int> st;
int scn[100001], max_scn;
int dfn[100001], max_dfn;
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

int scc_indeg[100001];
void sol()
{
	for (int v = 1; v < 100001; v++) {
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

	for (int v = 1; v <= N; v++) {
		if (!dfn[v]) {
			tarjan(v);
		}
	}

	// scc의 in-degree가 0인 개수 구하기
	// 타잔 알고리즘 안에서 코드 추가하면 요상하게 틀리는 듯??
	for (int v = 1; v <= N; v++) {
		for (int w : adj[v]) {
			if (scn[w] != scn[v]) {
				++scc_indeg[scn[w]];
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= max_scn; i++) {
		cnt += !scc_indeg[i];
	}
	printf("%d\n", cnt);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		sol();
	}
}