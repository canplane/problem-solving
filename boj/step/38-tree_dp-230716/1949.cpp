/* 조건 3에 대하여 :

정점 가중치가 0보다 크기 때문에, 임의 정점에 대하여 어떠한 우수 마을도 인접하지 않는 경우는 없습니다.

조건 1에 따르면, 어떤 정점 v가 우수 마을이 아니고 v와 인접한 모든 정점들 w 역시 우수 마을이 아닌 상태라면, v를 추가로 우수 마을로 선정할 수 있기 때문입니다. 

따라서 각 w 서브 트리들에서 w를 선정하지 않은 경우가 선정한 경우보다 더 큰 경우가 된다면, 이들을 포함한 v 서브 트리에서는 무조건 v를 우수 마을로 선정한 것이 v를 우수 마을로 선정하지 않은 경우보다 크게 됩니다.

따라서 조건 3은 자동으로 따라오는 성질입니다.

*/

using namespace std;
#include <bits/stdc++.h>

int N;
int A[10001];
vector<int> adj[10001];

int S[10001][2];
int dfs(int v, int u)
{
	S[v][1] = A[v], S[v][0] = 0;
	for (int w : adj[v]) {
		if (w != u) {
			S[v][0] += dfs(w, v), S[v][1] += S[w][0];
		}
	}
	return max(S[v][1], S[v][0]);
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	for (int _ = 0; _ < N - 1; _++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v), adj[v].push_back(u);
	}
	printf("%d", dfs(1, 0));
}