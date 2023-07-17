// 2-SAT
// https://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220803009418
// (~p => p) ^ (p => ~p)이면 모순. 그냥 (~p => p)만 존재하면 ~p가 F이기만 하면 참.

using namespace std;
#include <bits/stdc++.h>

#define SZ 20000
#define V(x) (SZ / 2 + (x))

vector<int> adj[SZ + 1];

deque<int> st;
int scn[SZ + 1], max_scn;
bool sat;

int dfn[SZ + 1], max_dfn;
int dfs(int v)
{
	st.push_back(v);
	int ret = dfn[v] = ++max_dfn;

	for (int w : adj[v]) {
		if (!dfn[w])
			ret = min(ret, dfs(w));
		else if (!scn[w])
			ret = min(ret, dfn[w]);
	}

	if (ret == dfn[v]) {
		++max_scn;
		while (true) {
			int w = st.back(); st.pop_back();
			if ((scn[w] = max_scn) == scn[SZ - w])
				sat = false;
			if (w == v)
				break;
		}
	}
	return ret;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	while (M--) {
		int i, j;
		scanf("%d %d", &i, &j);
		adj[V(-i)].push_back(V(j)), adj[V(-j)].push_back(V(i));
	}

	sat = true;
	for (int v = 1; v <= N; v++) {
		if (!dfn[V(v)])
			dfs(V(v));
		if (!dfn[V(-v)])
			dfs(V(-v));
	}
	printf("%d", sat);
}