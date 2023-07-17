// 2-SAT 4: satisfiability를 넘어 가능한 값 집합 중 아무거나 내보내는 문제. 
// https://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220803009418
// https://ioqoo.tistory.com/m/55
// SCC [위상 정렬] (dfs로 뽑아낸 SCC 그룹을 가장 늦게 뽑은 그룹부터 [역순으로 읽기] (그룹/노드 모두 rbegin)), F => T/F 모두 가능 이용
// satisfiabilty 보장되면 T -> F는 없다. F -> T/F, T -> T 경로만 있음.
// SAT 보장된다는 건 SCC 안에 xi, ~xi가 모두 있는 경우가 없다는 것. 이는 (xi => ~xi) ^ (~xi => xi) = F. 즉 모순을 의미한다.

using namespace std;
#include <bits/stdc++.h>

#define SZ 20000
#define POS(x) (SZ / 2 + (x))
#define X(pos) ((pos) - SZ / 2)

vector<int> adj[SZ + 1];

stack<int> st;
int scn[SZ + 1], max_scn;
vector<vector<int>> sccs;
bool sat;

int dfn[SZ + 1], max_dfn;
int dfs(int v)
{
	st.push(v);
	int ret = dfn[v] = ++max_dfn;

	for (int w : adj[v]) {
		if (!dfn[w]) {
			ret = min(ret, dfs(w));
		}
		else if (!scn[w]) {
			ret = min(ret, dfn[w]);
		}
	}
	if (ret == dfn[v]) {
		sccs.push_back({}); auto &scc = sccs.back();
		++max_scn;
		while (true) {
			int w = st.top(); st.pop();
			scc.push_back(w);
			if ((scn[w] = max_scn) == scn[SZ - w]) {
				sat = false;
			}
			if (w == v) {
				break;
			}
		}
	}
	return ret;
}

int val[SZ + 1];

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	while (M--) {
		int i, j;
		scanf("%d %d", &i, &j);
		adj[POS(-i)].push_back(POS(j)), adj[POS(-j)].push_back(POS(i));
	}

	sat = true;
	for (int x = 1; x <= N; x++) {
		if (!dfn[POS(x)]) {
			dfs(POS(x));
		}
		if (!dfn[POS(-x)]) {
			dfs(POS(-x));
		}
	}
	printf("%d\n", sat);
	if (sat) {
		for (auto it = sccs.rbegin(); it != sccs.rend(); it++) {
			for (int v : *it) {
				val[v] = (val[SZ - v] == 1) ? 2 : 1;
			}
		}
		for (int x = 1; x <= N; x++) {
			printf("%d ", val[POS(x)] - 1);
		}
	}
}